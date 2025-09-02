from multiprocessing import Process, Queue, current_process
import queue
import time


def do_some_stuff(smt_to_do: Queue, smt_done: Queue):
    while True:
        try:
            task = smt_to_do.get_nowait()
        except queue.Empty:
            break
        else:
            print(task)
            smt_done.put(task + " is done by " + current_process().name)
            time.sleep(2)


if __name__ == "__main__":
    number_of_task = 10
    number_of_process = 4
    smt_to_do = Queue()
    smt_done = Queue()
    procs = []
    for task in range(number_of_task):
        smt_to_do.put("Task no: " + str(task))

    for proc in range(number_of_process):
        p = Process(target=do_some_stuff, args=(smt_to_do, smt_done))
        procs.append(p)
        p.start()

    for proc in procs:
        proc.join()

    while not smt_done.empty():
        print(smt_done.get())

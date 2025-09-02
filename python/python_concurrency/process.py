from multiprocessing import Process
import time


def print_num(num: int):
    for i in range(10):
        print("Process number: ", num)
        time.sleep(1)


if __name__ == "__main__":
    proc_list = []
    for num in range(3):
        proc = Process(target=print_num, args=(num,))
        proc_list.append(proc)
        proc.start()

    for proc in proc_list:
        proc.join()

from multiprocessing import Pool
import time

work = (["A", 5], ["B", 7], ["C", 1])


def work_log(work_data):
    print(f"Process {work_data[0]} sleep for {work_data[1]}")
    time.sleep(work_data[1])
    print(f"Process {work_data[0]} done")


if __name__ == "__main__":
    p = Pool(3)
    p.map(work_log, work)

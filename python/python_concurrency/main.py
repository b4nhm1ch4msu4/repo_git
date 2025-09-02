from multiprocessing import Process


def print_func(continent="Asia"):
    print("The name of continent is : ", continent)


if __name__ == "__main__":
    names = ["America", "Europe", "Afica"]
    procs = []
    proc = Process(target=print_func)
    procs.append(proc)
    proc.start()

    for name in names:
        proc = Process(target=print_func, args=(name,))
        procs.append(proc)
        proc.start()

    for proc in procs:
        proc.join()

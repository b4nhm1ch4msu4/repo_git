import array as arr

a = arr.array("i", [1, 2, 3])
a.append(4)
a.extend([5, 6, 7])
a.insert(7, 8)
print("a: ", a)

b = arr.array("i", [11, 12, 13])
print("b: ", b)
c = arr.array("i")
c = a + b
last = c.pop()
not_last = c.pop(1)
print("c: ", c)

d = c[0:3]
for i in d:
    print(i)
print("d: ", d)

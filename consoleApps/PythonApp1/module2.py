
def outer():
    num = 10
    def inner():
        nonlocal num   # nonlocal关键字声明
        num = 100
        print(num)
    inner()
    print(num)
outer()

def func(a):
    a =10
    a**=9
    print(a)
    return a
func(0.9)

import sys
print(sys.path)
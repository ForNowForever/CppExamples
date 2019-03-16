
num = 1
def fun1():
    #global num  # 需要使用 global 关键字声明
    num = 2
    print(num) 
    num = 123
    print(num)
fun1()
print(num)
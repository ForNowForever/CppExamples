#！/usr/bin/env python
# Fibonacci series: 斐波纳契数列
# 两个元素的总和确定了下一个数
#a, b = 0, 1
#while b < 40:
#    print(b)
#    a, b = b, a + b

m = [1,2,3,4]
#for x in m:
#    print(x)

itr = iter(m)
i=0
while m[-1] < 100 and i <len(m):
    print(next(itr),end='\t')
    i+=1
    pass
    m[-1]+=10
print(m[-1],end='\t')

#a = int(20)
#b = 20 
#if ( a is b ):
#   print ("1 - a 和 b 有相同的标识")
#else:
#   print ("1 - a 和 b 没有相同的标识")

    
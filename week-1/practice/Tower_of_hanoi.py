import math 
n = int(input())
print(int(math.pow(2,n) -1))
 
def hanoi(n, a, b, c):
        if (n <= 0 ):
            return
        if (n == 1 ):
            print(f"{a}  {b}")
            return
        hanoi(n -1, a, c, b)
        print(f"{a}  {b}")
        hanoi(n-1,c,b,a )
 
hanoi(n,1,3,2)
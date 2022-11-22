def fibonacci_iterative(n:int):
    n1=0
    n2=1
    if n == 1:
        return 0
    if n == 2:
        return 1
    for i in range(2,n):
        sum=n1+n2
        n1=n2
        n2=sum
    return n2
        

def fibonacci_recursive(n):
    if n==1:
        return 0
    elif n==2:
        return 1
    else:
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2)


n = int(input("Enter value of n(nth Fibonacci number): "))
print(f"Fibonacci Number(Iterative): {fibonacci_iterative(n)}")
print(f"Fibonacci Number(Recursive): {fibonacci_recursive(n)}")

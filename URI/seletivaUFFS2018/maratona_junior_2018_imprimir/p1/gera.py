import random


a, b, c = map(int, input().split())


print(a)
for i in range(a):
    cost = random.randint(1, b)
    p = random.randint(cost, c)
    print(cost, p)

import random
import string

n = int(input())

print(''.join(random.choice(string.ascii_lowercase) for x in range(n)))

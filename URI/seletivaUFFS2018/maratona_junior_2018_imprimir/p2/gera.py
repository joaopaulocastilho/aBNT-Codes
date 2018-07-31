import random
import string

def gera(size):
    return ''.join([random.choice(string.ascii_letters) for n in range(size)])

print(gera(100))
print(gera(100))

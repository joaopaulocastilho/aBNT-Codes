import random
import string

def palavra(s):
    letras = string.ascii_lowercase + string.ascii_uppercase
    return ''.join(random.choice(letras) for x in range(s))



for x in "cdefghijklmnopqrstuvxy":
    n = 10
    fn = "ordena-%s.in" % x
    print(fn)
    with open(fn, 'w') as f:
        print(n, file=f)
        for x in range(n):
            p = palavra(20)
            print(p, file=f)

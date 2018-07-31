import random
import string

def palavra(s):
    letras = string.ascii_lowercase
    return ''.join(random.choice(letras) for x in range(s))


for x in "cdefghijklmnopqrstuvxy":
    fn = "lexico-%s.in" % x
    with open(fn, 'w') as f:
        print(palavra(random.randint(1, 20)), file=f)
        print(palavra(random.randint(1, 20)), file=f)

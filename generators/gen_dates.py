# -*- coding: utf-8 -*-

# Gera datas (delta, dia, mês, ano) aleatórias
#
# Autor: Edson Alves
# Data: 25/03/2015
# Licença: LGPL. Sem copyright.

from random import randint
from datetime import time, timedelta, datetime, date

basename = 'dates'
T = 5


def addTime(delta, a):
    x = datetime(a[2], a[1], a[0])
    y = timedelta(days=delta)
    z = x + y
    return '{} {} {}'.format(z.day, z.month, z.year)


def cc():
    ins = [(365, 1, 1, 1), (366, 2, 1, 1), (500, 1, 1, 1), (2000, 1, 1, 2000), 
        (800, 1, 3, 4)]
    outs = [addTime(x, (y, z, w)) for x, y, z, w in ins]
    plain = [(y, z, w) for x, y, z, w in ins]

    infile = '{}_cc.in'.format(basename)
    outfile = '{}_cc.sol'.format(basename)
    plainfile = '{}_cc.pln'.format(basename)

    with open(infile, 'w') as f:
        ins = ['%d %d %d %d' % x for x in ins]
        f.write('\n'.join(ins))
        f.write('\n')

    with open(outfile, 'w') as f:
        f.write('\n'.join(outs))
        f.write('\n')

    with open(plainfile, 'w') as f:
        plain = ['%d %d %d' % x for x in plain]
        f.write('\n'.join(plain))
        f.write('\n')



def random_cases():
    ranges = [10 ** k for k in range(1, T + 1)]

    for r in ranges:
        ins = []

        for i in range(r):
            ins.append((randint(1, 10 ** 6), randint(1, 28), randint(1, 12), 
                       randint(1, 4000)))

        outs = [addTime(x, (y, z, w)) for x, y, z, w in ins]
        plain = [(y, z, w) for x, y, z, w in ins]

        suffix = r

        if suffix >= 10 ** 6:
            suffix /= 10 ** 6
            suffix = '{}M'.format(suffix)
        elif suffix >= 10 ** 3:
            suffix /= 10 ** 3
            suffix = '{}K'.format(suffix)

        infile = '{}_{}.in'.format(basename, suffix)
        outfile = '{}_{}.sol'.format(basename, suffix)
        plainfile = '{}_{}.pln'.format(basename, suffix)

        with open(infile, 'w') as f:
            ins = ['%d %d %d %d' % x for x in ins]
            f.write('\n'.join(ins))
            f.write('\n')

        with open(outfile, 'w') as f:
            f.write('\n'.join(outs))
            f.write('\n')

        with open(plainfile, 'w') as f:
            plain = ['%d %d %d' % x for x in plain]
            f.write('\n'.join(plain))
            f.write('\n')


def gen():
    cc()
    random_cases()


if __name__ == '__main__':
    gen()

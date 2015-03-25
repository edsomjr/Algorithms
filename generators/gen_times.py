# -*- coding: utf-8 -*-

# Gera números inteiros aleatórios
#
# Autor: Edson Alves
# Data: 06/03/2015
# Licença: LGPL. Sem copyright.

from random import randint
from datetime import time, timedelta, datetime, date

basename = 'times'
T = 5


def addTime(a, b):
    x = time(*a)
    y = timedelta(hours=b[0], minutes=b[1], seconds=b[2])
    z = datetime.combine(date.today(), x) + y
    return z.strftime('%H %M %S')


def cc():
    ins = [(0, 0, 0), (12, 0, 0), (23, 59, 59), (1, 2, 3), (3, 45, 30), 
           (11, 22, 55)]

    outs = []

    for i in range(len(ins)/2):
        outs.append(addTime(ins[2*i], ins[2*i + 1]))


    infile = '{}_cc.in'.format(basename)
    outfile = '{}_cc.sol'.format(basename)

    with open(infile, 'w') as f:
        ins = ['%d %d %d' % x for x in ins]
        f.write('\n'.join(ins))
        f.write('\n')

    with open(outfile, 'w') as f:
        f.write('\n'.join(outs))
        f.write('\n')


def random_cases():
    ranges = [10 ** k for k in range(1, T + 1)]

    for r in ranges:
        ins = []

        for i in range(r):
            ins.append((randint(0, 23), randint(0, 59), randint(0, 59)))

        outs = []

        for i in range(len(ins)/2):
            outs.append(addTime(ins[2*i], ins[2*i + 1]))


        suffix = r

        if suffix >= 10 ** 6:
            suffix /= 10 ** 6
            suffix = '{}M'.format(suffix)
        elif suffix >= 10 ** 3:
            suffix /= 10 ** 3
            suffix = '{}K'.format(suffix)

        infile = '{}_{}.in'.format(basename, suffix)
        outfile = '{}_{}.sol'.format(basename, suffix)

        with open(infile, 'w') as f:
            ins = ['%d %d %d' % x for x in ins]
            f.write('\n'.join(ins))
            f.write('\n')

        with open(outfile, 'w') as f:
            f.write('\n'.join(outs))
            f.write('\n')


def gen():
    cc()
    random_cases()


if __name__ == '__main__':
    gen()

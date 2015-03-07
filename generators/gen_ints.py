# -*- coding: utf-8 -*-

# Gera números inteiros aleatórios
#
# Autor: Edson Alves
# Data: 06/03/2015
# Licença: LGPL. Sem copyright.

from random import randint

basename = 'ints'
T = 6


def cc():
    ins = [0, -1, 2147483647, '\n', -2147483648]
    outs = [x for x in ins if type(x) == int]

    infile = '{}_cc.in'.format(basename)
    outfile = '{}_cc.sol'.format(basename)
    countfile = '{}_cc.cnt'.format(basename)

    with open(infile, 'w') as f:
        ins = [str(x) for x in ins]
        f.write(' '.join(ins))

    with open(outfile, 'w') as f:
        outs = [str(x) for x in outs]
        f.write('\n'.join(outs))
        f.write('\n')

    with open(countfile, 'w') as f:
        f.write('{}\n'.format(len(outs)))


def random_cases():
    ranges = [10 ** k for k in range(1, T + 1)]

    for r in ranges:
        ins = []

        for i in range(r):
            ins.append(randint(-2147483648, 2147483647))

            n = randint(1, 10)

            if n == 6:
                ins.append(' ')

            if n == 9:
                ins.append('\n')

        outs = [x for x in ins if type(x) == int]

        suffix = r

        if suffix >= 10 ** 6:
            suffix /= 10 ** 6
            suffix = '{}M'.format(suffix)
        elif suffix >= 10 ** 3:
            suffix /= 10 ** 3
            suffix = '{}K'.format(suffix)

        infile = '{}_{}.in'.format(basename, suffix)
        outfile = '{}_{}.sol'.format(basename, suffix)
        countfile = '{}_{}.cnt'.format(basename, suffix)

        with open(infile, 'w') as f:
            ins = [str(x) for x in ins]
            f.write(' '.join(ins))

        with open(outfile, 'w') as f:
            outs = [str(x) for x in outs]
            f.write('\n'.join(outs))
            f.write('\n')

        with open(countfile, 'w') as f:
            f.write('{}\n'.format(len(outs)))


def gen():
    cc()
    random_cases()


if __name__ == '__main__':
    gen()

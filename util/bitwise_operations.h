/*
 * Operações binárias.
 *
 * Autor: Edson Alves
 * Data: 04/05/2018
 * Licença: LGPL. Sem copyright.
 */
#ifndef BITWISE_OPERATIONS_H
#define BITWISE_OPERATIONS_H

int least_significant_bit(int n)
{
    return n & -n;
}

bool is_power_of_2(int n)
{
    return n > 0 and least_significant_bit(n) == n;
}

int least_power_of_2_greater_or_equals(int n)
{
    if (n < 0)
        return 1;

    if (is_power_of_2(n))
        return n;

    int most_significant_bit = n;

    while (most_significant_bit & (most_significant_bit - 1))  // Checks if MSB is a power of 2
        most_significant_bit &= (most_significant_bit - 1);    // Turns LSB off

    return most_significant_bit << 1;
}

#endif // BITWISE_OPERATIONS_H

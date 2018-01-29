/*
** EPITECH PROJECT, 2017
** my_atoi.c
** File description:
**reproduces atoi function
*/

#include "stick.h"

int my_atoi(char *number)
{
	int x = 0;
	int nb = 0;
	int sign = 0;

	if (number[0] == '-') {
		sign = 1;
		x = 1;
	}
	while (number[x]) {
		nb = nb + number[x] - 48;
		if (number[x + 1])
			nb = nb * 10;
		x = x + 1;
	}
	if (sign)
		nb = -1 * nb;
	return (nb);
}

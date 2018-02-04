/*
** EPITECH PROJECT, 2017
** my_atoi.c
** File description:
** reproduces atoi function
*/

#include "stick.h"

int my_put_nbr(int nb)
{
	int nbr;

	if (nb < 0) {
		my_putchar(45);
		nb = (-1) * nb;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			nbr = nb % 10;
			nb = (nb - nbr);
			nb = nb / 10;
			my_put_nbr(nb);
			my_putchar(48 + nbr);
		}
		else
			my_putchar(48 + nb % 10);
	}
	return (0);
}

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

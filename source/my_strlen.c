/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** Handle strlen function
*/

#include "stick.h"

int my_strlen(char *str)
{
	int x = 0;

	while (str[x])
		x = x + 1;
	return (x);
}

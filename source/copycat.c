/*
** EPITECH PROJECT, 2017
** copycat.c
** File description:
** copy and cat functions
*/

#include "stick.h"

char *my_strcat(char *str1, char *str2)
{
	char *final = malloc(sizeof(char) *
		(my_strlen(str1) + my_strlen(str2) + 1));
	int x = 0;
	int y = 0;

	while (str1[x]) {
		final[x] = str1[x];
		x = x + 1;
	}
	final[x] = '\0';
	while (str2[y]) {
		final[x] = str2[y];
		x = x + 1;
		y = y + 1;
	}
	final[x] = '\0';
	return (final);
}

char *my_strdup(char *str)
{
	char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));
	int x = 0;

	while (str[x]) {
		dest[x] = str[x];
		x = x + 1;
	}
	dest[x] = '\0';
	return (dest);
}

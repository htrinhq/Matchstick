/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** my_str_to_word_array functions
*/

#include "sh.h"

char *back_sep(char *str, char separator, char other_sep)
{
	int len = my_strlen(str) - 1;

	while (str[len] == separator || str[len] == other_sep)
		len = len - 1;
	str[len + 1] = '\0';
	return (str);
}

void fill_tab(char *str1, char *str2, int *x, int *i)
{
	str1[*x] = str2[*i];
	*x = *x + 1;
	*i = *i + 1;
}

void skip_sep(char *str, char separator, char other_sep, int *i)
{
	while (str[*i] == separator || str[*i] == other_sep)
		*i = *i + 1;
}

void if_sep(char **tab, int *y, int *x, char *str)
{
	tab[*y][*x] = '\0';
	*y = *y + 1;
	tab[*y] = malloc(sizeof(char) * (my_strlen(str) + 1));
	*x = 0;
}

char **my_str_to_word_array(char *str, char separator, char other_sep)
{
	char **tab = malloc(sizeof(char*) * my_strlen(str));
	int x = 0;
	int y = 0;
	int i = 0;

	str = back_sep(str, separator, other_sep);
	while (str[0] == separator || str[0] == other_sep)
		str ++;
	tab[y] = malloc(sizeof(char) * (my_strlen(str) + 1));
	while (str[i]) {
		if (str[i] == separator || str[i] == other_sep) {
			if_sep(tab, &y, &x, str);
			skip_sep(str, separator, other_sep, &i);
		} else
			fill_tab(tab[y], str, &x, &i);
	}
	tab[y][x] = '\0';
	tab[y + 1] = '\0';
	return (tab);
}

/*
** EPITECH PROJECT, 2017
** stick.h
** File description:
** stick.h
*/

#ifndef	STICK_H
#define STICK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct map {
	char **map;
	int lines;
	int max_nb;
} map_t;

int my_atoi(char *number);
int my_strlen(char *str);
void fill_line(map_t *map, int *y, int *x, int *pipe);
void display_map(map_t *map);
int create_map(map_t *map);
char *my_strcat(char *str1, char *str2);
void input(void);

#endif

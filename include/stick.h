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

#endif

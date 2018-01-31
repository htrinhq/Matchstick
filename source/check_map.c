/*
** EPITECH PROJECT, 2017
** check_map.c
** File description:
** check_map for win or lose conditions
*/

#include "stick.h"

void count_pipe(map_t *map, int y, int *x, int *pipe)
{
	while (map->map[y][*x]) {
		if (map->map[y][*x] == '|')
			*pipe = *pipe + 1;
		*x = *x + 1;
	}
}

int check_map(map_t *map)
{
	int y = 1;
	int x = 1;
	int pipe = 0;

	while (map->map[y]) {
		count_pipe(map, y, &x, &pipe);
		x = 1;
		y = y + 1;
	}
	if (pipe > 0)
		return (0);
	return (1);
}

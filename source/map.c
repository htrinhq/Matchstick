/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** map creation functions
*/

#include "stick.h"

void fill_line(map_t *map, int *y, int *x, int *pipe)
{

	map->map[*y] = malloc(sizeof(char) * (2 * map->lines + 2));
	map->map[*y][0] = '*';
	for (*x = 1; *x <= 2 * map->lines - 1; *x = *x + 1)
		if (*x <= map->lines - (*pipe / 2) ||
			*x >= map->lines + (*pipe / 2))
			map->map[*y][*x] = ' ';
		else
			map->map[*y][*x] = '|';
	*pipe = *pipe + 2;
	map->map[*y][*x] = '*';
	map->map[*y][*x + 1] = '\0';
}

void display_map(map_t *map)
{
	int x;

	for (x = 0; map->map[x]; x = x + 1) {
		write(1, map->map[x], my_strlen(map->map[x]));
		write(1, "\n", 1);
	}
}

int create_map(map_t *map)
{
	int x = 0;
	int y = 1;
	int pipe = 2;

	if (malloc(sizeof(char*) * (map->lines + 3)) == NULL)
		return (1);
	map->map = malloc(sizeof(char*) * (map->lines + 3));
	map->map[0] = malloc(sizeof(char) * (2 * map->lines + 2));
	for (x = 0; x <= 2 * map->lines; x = x + 1)
		map->map[0][x] = '*';
	map->map[0][x] = '\0';
	for (y = 1; y <= map->lines; y = y + 1)
		fill_line(map, &y, &x, &pipe);
	map->map[y] = malloc(sizeof(char) * (2 * map->lines + 2));
	for (x = 0; x <= 2 * map->lines; x = x + 1)
		map->map[y][x] = '*';
	map->map[y][x] = '\0';
	map->map[y + 1] = NULL;
	return (0);
}

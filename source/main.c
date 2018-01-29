/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** matchstick main
*/

#include "stick.h"

void fill_line(map_t *map, int *y, int *x)
{
	map->map[*y] = malloc(sizeof(char) * (2 * map->lines + 2));
	map->map[*y][0] = '*';
	for (*x = 1; *x <= 2 * map->lines - 1; *x = *x + 1)
		map->map[*y][*x] = 'f';
	map->map[*y][*x] = '*';
}

int create_map(map_t *map)
{
	int x = 0;
	int y = 1;

	if (malloc(sizeof(char*) * (map->lines + 3)) == NULL)
		return (66);
	map->map = malloc(sizeof(char*) * (map->lines + 3));
	map->map[0] = malloc(sizeof(char) * (2 * map->lines + 2));
	for (x = 0; x <= 2 * map->lines; x = x + 1)
		map->map[0][x] = '*';
	map->map[0][x] = '\0';
	for (y = 1; y <= map->lines; y = y + 1)
		fill_line(map, &y, &x);
	map->map[y] = malloc(sizeof(char) * (2 * map->lines + 2));
	for (x = 0; x <= 2 * map->lines; x = x + 1)
		map->map[y][x] = '*';
	for (x = 0; map->map[x]; x = x + 1)
		printf("%s\n", map->map[x]);
	return (0);
}

int main(int ac, char **av)
{
	map_t *map;

	if (ac != 3 || my_atoi(av[2]) < 0 ||
	my_atoi(av[1]) < 1 || my_atoi(av[1]) >= 100)
		return (84);
	if (malloc(sizeof(map_t)) == NULL)
		return (66);
	map = malloc(sizeof(map_t));
	map->lines = my_atoi(av[1]);
	map->max_nb = my_atoi(av[2]);
	return (create_map(map));
}

//nbline - nb pipe / 2;
//2 * nblines - 1 = etoiles;

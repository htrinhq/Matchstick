/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** matchstick main
*/

#include "stick.h"

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
	if (create_map(map))
		return (66);
	else
		game_loop(map);
		//input();
	return (0);
}

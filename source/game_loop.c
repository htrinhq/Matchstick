/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** game_loop functions
*/

#include "stick.h"

void change_map(map_t *map, usr_t *usr)
{
	int x = 1;
	int i = 1;

	while (map->map[usr->line][x] == ' ')
		x = x + 1;
	while (map->map[usr->line][x] == '|')
		x = x + 1;
	while (i <= usr->matches) {
		map->map[usr->line][x - i] = ' ';
		i = i + 1;
	}
}

int game_loop(map_t *map)
{
	usr_t *usr = malloc(sizeof(usr_t));
	usr_t *ia = malloc(sizeof(usr_t));

	display_map(map);
	while (42) {
		if (usr_turn(map, usr))
			return (2);
		else if (ia_turn(map, ia))
			return (1);
	}
	return (0);
}

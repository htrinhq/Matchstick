/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** game_loop functions
*/

#include "stick.h"

int limit_superior(int nb, int limit, int ind)
{
	if (nb > limit) {
		if (ind)
			my_printf("Error: this line is out of range\n");
		else {
			my_printf("You cannot remove more than ");
			my_printf("%d matches per turn\n", limit);
		}
		return (1);
	}
	return (0);
}

int define_limit(map_t *map, int ind)
{
	int limit;

	if (ind)
		limit = map->lines;
	else
		limit = map->max_nb;
	return (limit);
}

int errors(char* usr_cmd, map_t *map, int ind)
{
	int nb;
	int limit = define_limit(map, ind);

	if (check_usr_cmd(usr_cmd)) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (-777);
	} else {
		nb = my_atoi(usr_cmd);
		if (limit_superior(nb, limit, ind))
			return(-777);
	}
	return (nb);
}

void change_map(map_t *map, usr_t *usr)
{
	int x = 1;
	int i = 1;

	while(map->map[usr->line][x] == ' ')
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

	display_map(map);
	while (42) {
		my_printf("\nYour turn\n");
		if (fill_usr(usr, map))
			return (-1);
		write(1, "\n", 1);
		change_map(map, usr);
		display_map(map);
	}
	return (0);
}

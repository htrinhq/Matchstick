/*
** EPITECH PROJECT, 2017
** ia.c
** File description:
** ia functions
*/

#include "stick.h"

int check_line(map_t *map, usr_t *ia)
{
	int x = 1;
	int pipe = 0;

	for (x = 1; map->map[ia->line][x]; x = x + 1)
		if (map->map[ia->line][x] == '|')
			pipe = pipe + 1;
	ia->matches = pipe;
	return (pipe);
}

void randomize(usr_t *ia, map_t *map)
{
	int max = check_line(map, ia);

	srandom(time(NULL));
	ia->matches = (random() % map->max_nb) + 1;
	if (max < ia->matches && max > 1)
		ia->matches = max - 1;
	else if (max < ia->matches)
		ia->matches = max;
}

int ia_turn(map_t *map, usr_t *ia)
{
	ia->line = map->lines;
	while (!check_line(map, ia))
		ia->line = ia->line - 1;
	randomize(ia, map);
	my_printf("\nAI's turn...\n");
	change_map(map, ia);
	my_printf("AI removed %d match(es) from line %d\n",
	ia->matches, ia->line);
	display_map(map);
	if (check_map(map)) {
		my_printf("I lost... snif... but I'll get you next time!!\n");
		return (1);
	}
	return (0);
}

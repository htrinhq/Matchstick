/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** game_loop functions
*/

#include "stick.h"

int input(void)
{
	char *command = malloc(sizeof(char));
	char *usr_cmd = malloc(sizeof(char) * 10);
	int nb;

	read(0, command, 1);
	usr_cmd = my_strcat(usr_cmd, command);
	while (command[0] != '\n') {
		read(0, command, 1);
		usr_cmd = my_strcat(usr_cmd, command);
	}
	nb = my_atoi(usr_cmd);
	return (nb);
}

void game_loop(map_t *map)
{
	while (42) {
		display_map(map);
		write(1, "Your turn\nLine: ", 16);
		map->usr_line = input();
		write(1, "Matches: ", 10);
		map->usr_matches = input();
		write(1, "\n", 1);
	}
}

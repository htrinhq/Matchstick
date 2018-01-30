/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** game_loop functions
*/

#include "stick.h"

int input(int limit, char* name)
{
	char *command = malloc(sizeof(char) + 1);
	char *usr_cmd;
	int nb;

	read(0, command, 1);
	command[1] = '\0';
	if (command[0] == '\0')
		return (-99999);
	usr_cmd = my_strdup(command);
	while (command[0] != '\n') {
		read(0, command, 1);
		if (command[0] != '\n')
			usr_cmd = my_strcat(usr_cmd, command);
	}
	nb = my_atoi(usr_cmd);
	if (nb > limit) {
		write(1, "Invalid value!\n", 15);
		write(1, name, my_strlen(name));
		nb = input(limit, name);
	}
	return (nb);
}

void change_map(map_t *map, usr_t *usr)
{
	int x = 1;
	int i = 1;

	printf("line : %d\n", usr->line);
	printf("match : %d\n", usr->matches);
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
		write(1, "Your turn\nLine: ", 16);
		usr->line = input(map->lines, "Line: ");
		if (usr->line == -99999)
			return (-1);
		write(1, "Matches: ", 10);
		usr->matches = input(map->max_nb, "Matches: ");
		if (usr->matches == -99999)
			return (-1);
		write(1, "\n", 1);
		change_map(map, usr);
		display_map(map);
	}
	return (0);
}

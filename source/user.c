/*
** EPITECH PROJECT, 2017
** user.c
** File description:
** user interface functions
*/

#include "stick.h"

int fill_usr(usr_t *usr, map_t *map)
{
	int n;

	my_printf("Line: ");
	usr->line = input(map, usr, 1);
	if (usr->line == -99999)
		return (2);
	else if (usr->line == -777) {
		if (fill_usr(usr, map))
			return (1);
		return (0);
	}
	my_printf("Matches: ");
	usr->matches = input(map, usr, 0);
	if (usr->matches == -99999)
		return (2);
	else if (usr->matches == -777) {
		n = fill_usr(usr, map);
		return (n);
	}
	return (0);
}

int check_usr_cmd(char *cmd)
{
	int x = 0;

	while (cmd[x])
		if (cmd[x] >= '0' && cmd[x] <= '9')
			x = x + 1;
		else
			return (1);
	return (0);
}

int input(map_t *map, usr_t *usr, int ind)
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
	nb = errors(usr_cmd, map, usr, ind);
	return (nb);
}

int usr_turn(map_t *map, usr_t *usr)
{
	int n;

	my_printf("\nYour turn\n");
	n = fill_usr(usr, map);
	if (n == 2)
		return (2);
	else if (n)
		return (-1);
	change_map(map, usr);
	my_printf("Player removed %d match(es) from line %d\n",
	usr->matches, usr->line);
	display_map(map);
	if (check_map(map)) {
		my_printf("You lost, too bad..");
		return (1);
	}
	return (0);
}

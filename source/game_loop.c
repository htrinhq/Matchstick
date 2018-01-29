/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** game_loop functions
*/

#include "stick.h"

void input(void)
{
	char *command = malloc(sizeof(char));
	char *usr_cmd = malloc(sizeof(char) * 10);

	read(0, command, 1);
	usr_cmd = my_strcat(usr_cmd, command);
	while (command[0] != '\n') {
		read(0, command, 1);
		usr_cmd = my_strcat(usr_cmd, command);
	}
	//printf("%s\n", usr_cmd);
}

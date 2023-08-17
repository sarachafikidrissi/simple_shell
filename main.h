#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*======== shell.c =======*/
int main(int ac, char **av, char **env);

/*=== full_path and environement=====*/
char *get_full_path(char *input);
char *get_env(char *str);

/*===== memory handling ======*/
void free_exit(char **tokens);
void free_command(char **tokens);

/*====== tokenizing the input ========*/
char **split_buffer(char *buffer);

/*====== handling end of file ====*/
void handle_EOF(char *buffer);

/*======== helper functions =======*/
unsigned int _strlen(char *s);
int _strcmp(char *s1, char *s2);


#endif /* MAIN_H */

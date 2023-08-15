#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024
/*======== shell.c =======*/
int main(int ac, char **av, char **env);

/*====== tokenizing the input ========*/
char **split_buffer(char *buffer);

/*====== handling end of file ====*/
void handle_EOF(char *buffer);

/*======== helper functions =======*/
unsigned int _strlen(char *s);


#endif /* MAIN_H */

/*
** client.h for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Fri Jun  9 23:52:20 2017 arnoul_b
** Last update Sun Jun 11 20:25:49 2017 arnoul_b
*/

#ifndef __CLIENT_H_
#define __CLIENT_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>
#include <pwd.h>
#include <crypt.h>
#include <dirent.h>
#include <netdb.h>

void	my_parser(char *, int);
char	*my_merge(char **);
char	**my_str_to_wordtab(char *);
void	my_free(char **);

#endif

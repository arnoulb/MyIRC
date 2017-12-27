/*
** error.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myftp
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun May 21 15:29:23 2017 arnoul_b
** Last update Fri Jun  9 23:53:04 2017 arnoul_b
*/

#include "server.h"

void	error_argv(char *name)
{
      fprintf(stderr, "USAGE : %s port\n", name);
      fprintf(stderr,
	      "\tport\tport number on which the socket is listening\n");
      exit(-1);
}

void	close_socket(int fd)
{
  close(fd);
  exit(-1);
}

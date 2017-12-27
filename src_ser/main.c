/*
** main.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myftp
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Mon May 15 16:29:20 2017 arnoul_b
** Last update Sun Jun 11 16:53:24 2017 arnoul_b
*/

#include "server.h"

void	main_loop(t_srv *srv)
{
  int	i;

  while (1)
    {
      srv->readf = srv->master;
      if (select(srv->max + 1, &(srv->readf), NULL, NULL, NULL) == -1)
	{
 	  fprintf(stderr, "Error select\n");
	  close(srv->fd);
	  exit(-1);
	}
      i = -1;
      while (++i <= srv->max)
	if (FD_ISSET(i, &(srv->readf)))
	  {
	    if (i == srv->fd)
	      accept_srv(srv);
	    else
	      interract(srv, i);
	  }
    }
}

void	init(int port)
{
  t_srv	srv;

  init_socket(&srv, port);
  if (listen(srv.fd, 42) == -1)
    {
      fprintf(stderr, "Error listening\n");
      close(srv.fd);
      exit(-1);
    }
  FD_ZERO(&(srv.master));
  FD_ZERO(&(srv.readf));
  FD_SET(srv.fd, &(srv.master));
  srv.max = srv.fd;
  srv.cli = NULL;
  main_loop(&srv);
}

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      if (strncmp(av[1], "--help", 6) == 0)
	error_argv(av[0]);
      else if (atoi(av[1]) > 0)
	init(atoi(av[1]));
      else
	{
	  fprintf(stderr, "wrong port value\n");
	  return (-1);
	}
    }
  else
    error_argv(av[0]);
  return (0);
}

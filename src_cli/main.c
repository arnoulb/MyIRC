/*
** main.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Mon Jun  5 14:29:49 2017 arnoul_b
** Last update Sun Jul  2 20:38:33 2017 arnoul_b
*/

#include "client.h"

void	error(char *name)
{
      fprintf(stderr, "USAGE : %s address port\n", name);
      fprintf(stderr,
	      "\taddress\tip address server\n");
      fprintf(stderr,
	      "\tport\tport number on which the socket is listening\n");
      exit(-1);
}

void	init(char *buf2, char *buf)
{
  memset(buf2, 0, 2000);
  memset(buf, 0, 200);
}

void	main_loop(int fd)
{
  char		buf[200];
  char		buf2[2000];
  fd_set	readf;

  while (1)
    {
      FD_SET(0, &readf);
      FD_SET(fd, &readf);
      init(buf2, buf);
      if (select(fd + 1, &readf, NULL, NULL, NULL) == -1)
	{
	  fprintf(stderr, "Error select\n");
	  exit(-1);
	}
	if (FD_ISSET(fd, &readf))
	  {
	    if (read(fd, buf2, 2000) == 0)
	      exit (1);
	    write(1, buf2, strlen(buf2));
	  }
	if (FD_ISSET(0, &readf))
	  {
	    if (read(0, buf, 200) == 0)
	      exit (1);
	    my_parser(buf, fd);
	  }
    }
}

void	my_client(char *ip, int port)
{
  int			fd;
  struct protoent	*p;
  struct sockaddr_in	addr;

  p = getprotobyname("TCP");
  if ((fd = socket(AF_INET, SOCK_STREAM, p->p_proto)) == -1)
    {
      fprintf(stderr, "Error socket\n");
      exit(-1);
    }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip);
  if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
      fprintf(stderr, "Error conenct\n");
      close(fd);
      exit(-1);
    }
  main_loop(fd);
}

int	main(int ac, char **av)
{
  if (ac == 3)
    my_client(av[1], atoi(av[2]));
  else
    error(av[0]);
  return (0);
}

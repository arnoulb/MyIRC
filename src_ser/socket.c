/*
** socket.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Wed Jun  7 17:33:58 2017 arnoul_b
** Last update Sun Jun 11 21:23:12 2017 arnoul_b
*/

#include "server.h"

void	init_socket(t_srv *s, int port)
{
  struct protoent	*p;

  p = getprotobyname("TCP");
  if ((s->fd = socket(PF_INET, SOCK_STREAM, p->p_proto)) == -1)
    {
      fprintf(stderr, "Error socket\n");
      exit(-1);
    }
  s->srv_addr.sin_family = AF_INET;
  s->srv_addr.sin_port = htons(port);
  s->srv_addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(s->srv_addr.sin_zero), 0, 8);
  if (bind(s->fd, (const struct sockaddr *)&(s->srv_addr),
	   sizeof(s->srv_addr)) == -1)
    {
      close(s->fd);
      fprintf(stderr, "Error binding\n");
      exit(-1);
    }
}

void	accept_srv(t_srv *s)
{
  t_cli		*cli;
  socklen_t	sz;

  sz = sizeof (struct sockaddr_in);
  cli = lister(&(s->cli));
  if ((cli->fd = accept(s->fd,
			(struct sockaddr *)&(cli->addr), (&sz))) == -1)
    {
      fprintf(stderr, "Error accepting\n");
      exit(-1);
    }
  else
    {
      if (cli->fd > s->max)
	s->max = cli->fd;
      printf("New connection from %s on socket %d\n",
	     inet_ntoa(cli->addr.sin_addr), cli->fd);
      sprintf(cli->nick, "Guest%d", cli->fd);
      welcome(cli, s);
      FD_SET(cli->fd, &(s->master));
    }
}

void	interract(t_srv *srv, int fd)
{
  char	buf[4000];
  t_cli	*cli;

  memset(buf, 0, 4000);
  cli = get_client_byid(fd, srv, cli);
  if (read(fd, buf, 4000) == 0)
    {
      printf("socket %d quit\n", fd);
      close(fd);
      FD_CLR(fd, &(srv->master));
    }
  else
    {
      my_parser(buf, cli, srv);
    }
}

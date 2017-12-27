/*
** users.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun Jun 11 18:50:10 2017 arnoul_b
** Last update Sun Jun 11 19:58:37 2017 arnoul_b
*/

#include "server.h"

void	srv_list(t_cli *cli, t_srv *srv)
{
  t_cli *tmp;

  tmp = srv->cli;
      dprintf(cli->fd, "392 UserID terminal  Hôte\r\n");
      dprintf(cli->fd, "393");
  while (tmp)
    {
      dprintf(cli->fd, " %s", tmp->nick);
      tmp = tmp->next;
    }
      dprintf(cli->fd, "\r\n394 End of users\r\n");
}

void	channel_list(t_cli *cli, t_srv *srv, char **chans)
{
  t_cli *tmp;
  int	i;

  i = -1;
  while (chans[++i])
    {
      tmp = srv->cli;
      while (tmp)
	{
	  if (strcmp(tmp->chan, chans[i]) == 0)
	    dprintf(cli->fd, "353 %s\r\n", tmp->nick);
	  tmp = tmp->next;
	}
    }
  dprintf(cli->fd, "\r\n366 End of Names list\r\n");
}

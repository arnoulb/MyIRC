/*
** join.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun Jun 11 16:44:58 2017 arnoul_b
** Last update Sun Jun 11 18:36:22 2017 arnoul_b
*/

#include "server.h"

void	change_chan(char *name, t_srv *srv, int fd)
{
  t_cli	*tmp;

  tmp = srv->cli;
  while (tmp)
    {
      if (tmp->fd == fd)
	{
	  strcpy(tmp->chan, name);
	  return ;
	}
      tmp = tmp->next;
    }
}

void	part(char **cmd, t_srv *srv, t_cli *cli)
{
  t_cli *tmp;
  char	*name;

  name = cmd[1];
  if (name == NULL)
    dprintf(cli->fd, "461 JOIN : not enough paramters\r\n");
  else if (strcmp(name, cli->chan) != 0)
    dprintf(cli->fd, "442 %s you're not on that channel\r\n", name);
  else
    {
      dprintf(cli->fd, "341 %s\r\n", name);
      tmp = srv->cli;
      while (tmp)
	{
	  if (strcmp(tmp->chan, name) == 0)
	    dprintf(tmp->fd, "%s leaves %s\n", cli->nick, name);
	  tmp = tmp->next;
	}
      change_chan("", srv, cli->fd);
    }
}

void	join(char **cmd, t_srv *srv, t_cli *cli)
{
  t_cli *tmp;
  char	*name;

  name = cmd[1];
  if (name == NULL)
    dprintf(cli->fd, "461 JOIN : not enough paramters\r\n");
  else
    {
      dprintf(cli->fd, "341 %s\r\n", name);
      tmp = srv->cli;
      while (tmp)
	{
	  if (strcmp(tmp->chan, name) == 0)
	    dprintf(tmp->fd, "%s enter in %s\n", cli->nick, name);
	  tmp = tmp->next;
	}
      change_chan(name, srv, cli->fd);
    }
}

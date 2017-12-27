/*
** nickname.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun Jun 11 15:46:48 2017 arnoul_b
** Last update Sun Jun 11 17:35:11 2017 arnoul_b
*/

#include "server.h"

int	is_wrongchar(char *name)
{
  int	i;

  i = -1;
  while (name[++i])
    if (!((name[i] >= 'a' && name[i] <= 'z')
	|| (name[i] >= 'A' && name[i] <= 'Z')
	|| (name[i] >= '0' && name[i] <= '9')
	|| name[i] == '_'))
      return (1);
  return (0);

}

int	is_conflict(char *name, t_cli *cli)
{
  t_cli *tmp;

  tmp = cli;
  while (tmp)
    {
      if (strcmp(name, tmp->nick) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

void	change_nick(char *name, t_srv *srv, int fd)
{
  t_cli *tmp;

  tmp = srv->cli;
  while (tmp)
    {
      if (tmp->fd == fd)
	{
	  strcpy(tmp->nick, name);
	  return ;
	}
      tmp = tmp->next;
    }
}

void	nickname(char *name, t_srv *srv, t_cli *cli)
{
  if (name == NULL)
    dprintf(cli->fd, "431 No nickname given\r\n");
  else if (is_wrongchar(name))
    dprintf(cli->fd, "432 Erroneus nickname\r\n");
  else if (strcmp(name, cli->nick) == 0)
    dprintf(cli->fd, "433 Nickname already in use\r\n");
  else if (is_conflict(name, srv->cli))
    dprintf(cli->fd, "436 Error nickname collision\r\n");
  else
    {
      change_nick(name, srv, cli->fd);
      dprintf(cli->fd, "%s change nickname to %s\n", cli->nick, name);
    }
}

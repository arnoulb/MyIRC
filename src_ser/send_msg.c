/*
** send_msg.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun Jun 11 17:39:24 2017 arnoul_b
** Last update Sun Jun 11 18:27:43 2017 arnoul_b
*/

#include "server.h"

void	send_msg(t_cli *cli, char *msg, t_srv *srv, char *nick)
{
  t_cli *tmp;

  tmp = srv->cli;
  while (tmp)
    {
      if (strcmp(cli->chan, tmp->chan) == 0
	  && cli->fd != tmp->fd
	  && (nick == NULL || strcmp(tmp->nick, nick) == 0))
	dprintf(tmp->fd, "%s : %s\r\n", cli->nick, msg);
      tmp = tmp->next;
    }
}

int	user_exist(t_cli *cli, char *name)
{
  t_cli *tmp;

  tmp = cli;
  while (tmp)
    {
      if (strcmp(tmp->nick, name) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

void	send_privatemsg(t_cli *cli, t_srv *srv, char **cmd)
{
  char	*msg;

  msg = my_merge(&cmd[1]);
  if (cmd[0] == NULL)
    dprintf(cli->fd, "411 No recipient given\r\n");
  else if (!user_exist(srv->cli, cmd[0]))
    dprintf(cli->fd, "401 %s No such nick\r\n", cmd[0]);
  else if (cmd[1] == NULL || msg[1] == 0)
    dprintf(cli->fd, "412 No text to send\r\n");
  else
    send_msg(cli, &msg[1], srv, cmd[0]);
  free(msg);
}

/*
** exec.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Thu Jun  8 22:22:13 2017 arnoul_b
** Last update Sun Jun 11 21:24:14 2017 arnoul_b
*/

#include "server.h"

void	my_parser(char *buf, t_cli *cli, t_srv *srv)
{
  char	**cmd;
  int	i;

  cmd = split_line(buf);
  i = -1;
  while (cmd[++i])
    my_exec(cmd[i], cli, srv);
  my_free(cmd);
}

void	my_exec(char *line, t_cli *cli, t_srv *srv)
{
  char	**cmd;

  cmd = my_str_to_wordtab(line);
  if (strncmp(line, "NICK", 4) == 0)
    nickname(cmd[1], srv, cli);
  else if (strncmp(line, "JOIN", 4) == 0)
    join(cmd, srv, cli);
  else if (strncmp(line, "PART", 4) == 0)
    part(cmd, srv, cli);
  else if (strncmp(line, "PRIVMSG", 7) == 0)
    send_privatemsg(cli, srv, &cmd[1]);
  else if (strncmp(line, "USERS", 5) == 0)
    srv_list(cli, srv);
  else if (strncmp(line, "NAMES", 5) == 0)
    channel_list(cli, srv, &cmd[1]);
  else if (strncmp(line, "QUIT", 4) == 0)
    {
      FD_CLR(cli->fd, &(srv->master));
      close(cli->fd);
      remove_byfd(cli->fd, &(srv->cli));
    }
  else
      send_msg(cli, line, srv, NULL);
  my_free(cmd);
}

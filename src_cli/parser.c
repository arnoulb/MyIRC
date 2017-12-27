/*
** parser.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun Jun 11 19:10:43 2017 arnoul_b
** Last update Sun Jun 11 20:17:49 2017 arnoul_b
*/

#include "client.h"

void	send_msg(int fd, char **cmd)
{
  char	*msg;

  msg = my_merge(&cmd[1]);
  dprintf(fd, "PRIVMSG %s %s\n", cmd[0], msg);
  free(msg);
}

void	my_parser(char *buf, int fd)
{
  char	**cmd;

  cmd = my_str_to_wordtab(buf);
  if (strncmp(buf, "/join", 5) == 0)
    dprintf(fd, "JOIN %s\n", cmd[1]);
  else if (strncmp(buf, "/part", 5) == 0)
    dprintf(fd, "PART %s\n", cmd[1]);
  else if (strncmp(buf, "/quit", 5) == 0)
    dprintf(fd, "QUIT");
  else if (strncmp(buf, "/nick", 5) == 0)
    dprintf(fd, "NICK %s\n", cmd[1]);
  else if (strncmp(buf, "/users", 6) == 0)
    dprintf(fd, "USERS\n");
  else if (strncmp(buf, "/names", 6) == 0)
    dprintf(fd, "NAMES %s\n", cmd[1]);
  else if (strncmp(buf, "/msg", 4) == 0)
    send_msg(fd, cmd);
  else
    dprintf(fd, "%s\n", buf);
  my_free(cmd);
}

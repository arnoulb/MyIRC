/*
** cmd.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun Jun 11 14:41:21 2017 arnoul_b
** Last update Thu Jun 15 15:35:58 2017 arnoul_b
*/

#include "server.h"

char **get_cmd()
{
  char	**cmd;

  cmd = malloc(sizeof (char *) * 12);
  cmd[0] = "NICK";
  cmd[1] = "JOIN";
  cmd[2] = "QUIT";
  cmd[3] = "SERVER";
  cmd[4] = "USER";
  cmd[5] = "LIST";
  cmd[6] = "PART";
  cmd[7] = "ACCEPT_FILE";
  cmd[8] = "SEND_FILE";
  cmd[9] = "NAMES";
  cmd[10] = "PRIVMSG";
  cmd[11] = 0;
  return (cmd);
}

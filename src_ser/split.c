/*
** split.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun Jun 11 15:29:07 2017 arnoul_b
** Last update Sun Jun 11 15:39:17 2017 arnoul_b
*/

#include "server.h"

int	get_nbline(char *s)
{
  int	i;
  int	nb;

  nb = 0;
  i = -1;
  while (s[++i])
    if (s[i] == '\n')
      ++nb;
  return (nb);
}

void	get_line(char *s, char *dest)
{
  int i;
  i = -1;
  while (s[++i] && s[i] != '\n')
    dest[i] = s[i];
  dest[i] = 0;
}

int	my_strline(char *s)
{
  int	i;

  i = -1;
  while (s[++i] && s[i] != '\n');
  return (i);
}

char	**split_line(char *str)
{
  int	i;
  int	j;
  char	**tab;

  tab = malloc(sizeof (char *) * (get_nbline(str) + 1));
  i = -1;
  j = -1;
  while (str[++i])
    {
      if (i == 0 || (str[i] != '\n' && str[i - 1] == '\n'))
	{
	  tab[++j] = malloc(sizeof (char) * (my_strline(&str[i]) + 1));
	  get_line(&str[i], tab[j]);
	}
    }
  tab[j + 1] = 0;
  return (tab);
}

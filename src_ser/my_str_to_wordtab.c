/*
** my_str_to_wordtab.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myftp
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun May 21 20:51:48 2017 arnoul_b
** Last update Sun Jun 11 15:29:39 2017 arnoul_b
*/

#include <unistd.h>
#include <stdlib.h>

int	is_alnum(char c)
{
  if (c >= '!' && c <= 'z')
    return (1);
  else
    return (0);
}

int	my_strlen_space(char *s)
{
  int i;
  i = -1;
  while (s[++i] && is_alnum(s[i]));
  return (i);
}

int	get_nb_word(char *s)
{
  int	i;
  int	nb;

  i = -1;
  nb = 1;
  while (s[++i])
    if (is_alnum(s[i]) && !is_alnum(s[i - 1]))
      ++nb;
  return (nb);
}

void	get_word(char *s, char *dest)
{
  int i;
  i = -1;
  while (s[++i] && is_alnum(s[i]))
    dest[i] = s[i];
  dest[i] = 0;
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  char	**tab;

  tab = malloc(sizeof (char *) * (get_nb_word(str) + 1));
  i = -1;
  j = -1;
  while (str[++i])
    {
      if (is_alnum(str[i]) && !is_alnum(str[i - 1]))
	{
	  tab[++j] = malloc(sizeof (char) * (my_strlen_space(&str[i]) + 1));
	  get_word(&str[i], tab[j]);
	}
    }
  tab[j + 1] = 0;
  return (tab);
}

/*
** recurs.c for recurs
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Jan 10 03:01:35 2016 marc brout
** Last update Sun Jan 10 10:03:43 2016 marc brout
*/

#include "main.h"

char		concate_strs(t_arg *arg, struct dirent *file, t_file *par)
{
  char		*str;
  char		*str2;
  int		size;

  if ((size = strlen(par->path) + strlen(file->d_name) + 2) > 100 ||
      (str = malloc(size + 1)) == NULL)
    return (1);
  str[size] = 0;
  if (snprintf(str, size, "%s%c%s", par->path, '/', file->d_name) < 0)
    return (1);
  if ((size = strlen(par->archpath) + strlen(file->d_name) + 1) > 100 ||
      (str2 = malloc(size + 1)) == NULL ||
      (snprintf(str2, size, "%s%s", par->archpath, file->d_name) < 0))
    return (1);
  str2[size] = 0;
  if (add_file_to_list(arg, str, str2))
    return (1);
  free(str);
  free(str2);
  return (0);
}

char		folder_list(t_arg *arg, t_file *par)
{
  DIR		*fold;
  struct dirent *file;

  if ((fold = opendir(par->path)) == NULL ||
      (par->archpath = realloc(par->archpath, strlen(par->archpath) + 2))
       == NULL)
    return (1);
  par->archpath = strcat(par->archpath, "/");
  while ((file = readdir(fold)) != NULL)
    {
      if (strcmp(file->d_name, ".") && strcmp(file->d_name, ".."))
	if (concate_strs(arg, file, par))
	  return (1);
    }
  closedir(fold);
  return (0);
}

void		my_revstr(char *str)
{
  int		mid;
  int		i;
  int		j;
  char		c;

  i = 0;
  j = strlen(str) - 1;
  mid = strlen(str) / 2;
  while (i < mid)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i++;
      j--;
    }
}

char		set_padres(t_file *files)
{
  int		i;
  t_file	*tmp;

  tmp = files;
  while ((tmp = tmp->next) != NULL)
    {
      i = -1;
      my_revstr(tmp->archpath);
      while (tmp->archpath[++i] && tmp->archpath[i] != '/');
      if (tmp->archpath[i])
	{
	  if ((tmp->archpath = realloc(tmp->archpath, i + 1)) == NULL)
	    return (1);
	  tmp->archpath[i] = 0;
	}
      my_revstr(tmp->archpath);
    }
  return (0);
}

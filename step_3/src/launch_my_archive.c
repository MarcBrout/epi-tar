/*
** launch_my_archive.c for rush
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sun Jan 10 06:41:42 2016 marc brout
** Last update Sun Jan 10 11:22:00 2016 marc brout
*/

#include "main.h"

char		file_type(struct stat *stats)
{
  char		c;

  c = '0';
  if ((long)stats->st_nlink > 2)
    c = '1';
  c = S_ISDIR(stats->st_mode) ? '5' : c;
  c = S_ISCHR(stats->st_mode) ? '3' : c;
  c = S_ISBLK(stats->st_mode) ? '4' : c;
  c = S_ISFIFO(stats->st_mode) ? '6' : c;
  c = S_ISLNK(stats->st_mode) ? '2' : c;
  return (c);
}

char		add_file_to_list(t_arg *arg, char *file, char *archfile)
{
  t_file	*elem;
  t_file	*tmp;

  tmp = arg->files;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
      if (!strcmp(file, tmp->path))
	return (0);
    }
  if ((elem = malloc(sizeof(t_file))) == NULL ||
      (elem->path = strdup(file)) == NULL ||
      (elem->archpath = strdup(archfile)) == NULL)
    return (1);
  elem->next = NULL;
  tmp->next = elem;
  return (0);
}

char		construct_list(t_arg *arg)
{
  t_file	*tmp;
  struct stat	stats;

  tmp = arg->files;
  while ((tmp = tmp->next) != NULL)
    {
      if ((lstat(tmp->path, &stats)) < 0)
	return (1);
      if (S_ISDIR(stats.st_mode))
	if (folder_list(arg, tmp))
	  return (1);
    }
  return (0);
}

char		launch_my_archive(char **av, int *opt)
{
  t_arg		targ;
  t_file	file;
  int		i;

  file.path = "root";
  file.next = NULL;
  targ.files = &file;
  targ.opt = opt;
  i = 0;
  while (av[++i] != NULL)
    if (!access(av[i], F_OK) && !access(av[i], R_OK))
      {
	if (add_file_to_list(&targ, av[i], av[i]))
	  return (1);
      }
    else
	fprintf(stderr, "Fichier inexistant : %s\n", av[i]);
  if (file.next == NULL || set_padres(targ.files) || construct_list(&targ)
      || create_all_headers(&targ) || archive_files(&targ, av[0]))
    return (1);
  free_list(targ.files);
  return (0);
}

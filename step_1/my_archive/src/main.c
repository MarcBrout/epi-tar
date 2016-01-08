/*
** main.c for tarball
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan  8 21:16:14 2016 marc brout
** Last update Sat Jan  9 00:22:09 2016 marc brout
*/

#include "my_archive.h"

/* int		main(int ac, char **av) */
/* { */
/*   int		fd; */
/*   int		len; */
/*   t_header	header; */

/*   if (ac < 2) */
/*     { */
/*       printf("wrong Usage\n"); */
/*       return (0); */
/*     } */
/*   fd = open(av[1], O_RDONLY); */
/*   if ((len = read(fd, &header, 512)) < 512) */
/*     printf("Archive corrupted\n"); */
/*   printf("len = %d\n", len); */
/*   return (0); */
/* } */


char		create_header(t_file *file)
{
  t_header	head;
  struct stat	stats;

  if (!lstat(file->path, &stats))
    {
      strncpy(header.name, file->path, 100);
      memcpy(header.mode, stats.st_mode, 8);
      strncpy(header.uid, "", 8);
      strncpy(header.gid, "", 8);
      
    }
}

char		add_file_to_list(t_arg *arg, char *file)
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
  if ((elem = malloc(sizeof(t_file))) == NULL)
    return (1);
  elem->path = strdup(file);
  elem->next = NULL;
  tmp->next = elem;
  return (0);
}

char		launch_my_archive(char **av)
{
  t_arg		targ;
  t_file	file;
  int		i;

  file.path = "root";
  file.next = NULL;
  targ.files = &file;
  i = 1;
  while (av[++i])
    if (!access(av[i], F_OK) && !access(av[i], R_OK))
      if (add_file_to_list(&targ, av[i]))
	return (1);
  if (file.next == NULL)
    return (1);
  return (0);
}

int		main(int ac, char **av, char **ev)
{
  if (ac < 2 || ev == NULL)
    return (1);
  launch_my_archive(av);
  return (0);
}

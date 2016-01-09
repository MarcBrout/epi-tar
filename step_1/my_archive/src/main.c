/*
** main.c for tarball
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan  8 21:16:14 2016 marc brout
** Last update Sat Jan  9 04:11:18 2016 marc brout
*/

#include "my_archive.h"

char		file_type(struct stat *stats)
{
  char		c;

  c = '0';
  c = S_ISDIR(stats->st_mode) ? '5' : c;
  c = S_ISCHR(stats->st_mode) ? '3' : c;
  c = S_ISBLK(stats->st_mode) ? '4' : c;
  c = S_ISFIFO(stats->st_mode) ? '6' : c;
  if ((long)stats->st_nlink > 1)
    c = '1';
  c = S_ISLNK(stats->st_mode) ? '2' : c;
  return (1);
}

char		create_header(t_file *file)
{
  char		*str;
  int		r;
  t_header	header;
  struct passwd *ps;
  struct group  *gr;
  struct stat	stats;

  memset(&header, 0, sizeof(t_header));
  if (!lstat(file->path, &stats))
    {
      strncpy(header.name, file->path, 99);
      header.name[99] = 0;
      memcpy(header.mode, stats.st_mode, 8);
      sprintf(header.size, "%lo", (long)stats.st_size);
      sprintf(header.mdate, "%lo",  (long)stats.st_mtime);
      if ((header.type = file_type(&stats)) == 1)
	{
	  if ((r = readlink(file->path, str, stats.st_size + 1)) == -1)
	    return (1);
	  strncpy(header.link, str, 99);
	}
      strncpy(header.magic, "ustar", 6);
      strncpy(header.magic, "00", 2);
      if ((ps = getpwuid(stats.st_uid)) == NULL)
	return (1);
      if ((gr = (stats.st_uid)) == NULL)
	return (1);
      strncpy(header.uname, ps->pw_name, 32);
      strncpy(header.gname, gr->gr_name, 32);
      if (header.type == 3 || header.type == 4)
	{
	  sprintf(header.devmajor, "%u", major(stats.st_rdev));
	  sprintf(header.devminor, "%u", minor(stats.st_rdev));
	}
    }
  return (0);
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

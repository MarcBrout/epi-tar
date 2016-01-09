/*
** main.c for tarball
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan  8 21:16:14 2016 marc brout
** Last update Sat Jan  9 08:33:42 2016 marc brout
*/

#include "main.h"

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
  return (c);
}

char		create_header(t_file *file)
{
  char		str;
  int		r;
  struct passwd *ps;
  struct group  *gr;
  struct stat	stats;

  memset(&file->header, 0, sizeof(t_header));
  if (!lstat(file->path, &stats))
    {
      strncpy(file->header.name, file->path, 100);
      sprintf(file->header.uid, "%07lo", (long)stats.st_uid);
      sprintf(file->header.gid, "%07lo",  (long)stats.st_gid);
      sprintf(file->header.mode, "%07lo", (long)stats.st_mode);
      sprintf(file->header.size, "%011lo", (long)stats.st_size);
      sprintf(file->header.mdate, "%011lo",  (long)stats.st_mtime);
      if ((file->header.type[0] = file_type(&stats)) == '2')
      	{
      	  if ((r = readlink(file->path, &str, stats.st_size + 1)) == -1)
      	    return (1);
      	  strncpy(file->header.link, &str, 100);
      	}
      file->header.space[0] = ' ';
      strncpy(file->header.magic, "ustar", 6);
      strncpy(file->header.version, "00", 2);
      if ((ps = getpwuid(stats.st_uid)) == NULL)
	return (1);
      if ((gr = getgrgid(stats.st_gid)) == NULL)
	return (1);
      strncpy(file->header.uname, ps->pw_name, 32);
      strncpy(file->header.gname, gr->gr_name, 32);
      if (file->header.type[0] == 3 || file->header.type[0] == 4)
	{
	  sprintf(file->header.devmajor, "%u", major(stats.st_rdev));
	  sprintf(file->header.devminor, "%u", minor(stats.st_rdev));
	}
      else
	{
	  memset(&file->header.devmajor, '0', 7);
	  memset(&file->header.devminor, '0', 7);
	}
      calc_chksum(&file->header);
    }
  return (0);
}

char		create_all_headers(t_arg *arg)
{
  t_file	*tmp;

  tmp = arg->files;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
      if (create_header(tmp))
	return (1);
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
  if (create_all_headers(&targ))
    return (1);
  archive_files(&targ, av[1]);
  return (0);
}

int		main(int ac, char **av, char **ev)
{
  if (ac < 2 || ev == NULL)
    return (1);
  launch_my_archive(av);
  return (0);
}

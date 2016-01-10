/*
** header.c for header
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sat Jan  9 20:33:36 2016 marc brout
** Last update Sun Jan 10 10:02:28 2016 marc brout
*/

#include "main.h"

char		header_start(t_file * file, struct stat *stats)
{
  if (sprintf(file->header.uid, "%07lo", (long)stats->st_uid) < 0 ||
      sprintf(file->header.gid, "%07lo",  (long)stats->st_gid) < 0 ||
      sprintf(file->header.mode, "%07lo", (long)stats->st_mode) < 0 ||
      sprintf(file->header.size, "%011lo", (long)stats->st_size) < 0 ||
      sprintf(file->header.mdate, "%011lo",  (long)stats->st_mtime) < 0 ||
      strncpy(file->header.magic, "ustar", 6) == NULL ||
      strncpy(file->header.version, "00", 2) == NULL ||
      strncpy(file->header.name, file->archpath, 100) == NULL ||
      sprintf(file->header.devmajor, "%07u", major(stats->st_rdev)) < 0 ||
      sprintf(file->header.devminor, "%07u", minor(stats->st_rdev)) < 0)
    return (1);
  file->header.space[0] = ' ';
  file->header.type[0] = file_type(stats);
  memset(file->header.chksum, ' ', 7);
  file->header.mode[1] = '0';
  return (0);
}

char		create_header(t_file *file)
{
  struct passwd *ps;
  struct group  *gr;
  struct stat	stats;

  memset(&file->header, 0, sizeof(t_header));
  if (!lstat(file->path, &stats))
    {
      if ((header_start(file, &stats)) ||
	  (ps = getpwuid(stats.st_uid)) == NULL ||
	  (gr = getgrgid(stats.st_gid)) == NULL ||
	  strncpy(file->header.uname, ps->pw_name, 32) == NULL ||
	  strncpy(file->header.gname, gr->gr_name, 32) == NULL)
	return (1);
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

void		free_list(t_file *files)
{
  t_file	*tmp;
  t_file	*tmp2;

  tmp = files->next;
  while (tmp != NULL)
    {
      tmp2 = tmp->next;
      free(tmp->path);
      free(tmp->archpath);
      free(tmp);
      tmp = tmp2;
    }
}

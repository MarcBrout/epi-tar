/*
** my_archive.h for tarball
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan  8 21:17:18 2016 marc brout
** Last update Fri Jan  8 23:44:19 2016 marc brout
*/

#ifndef MY_ARCHIVE_H_
# define MY_ARCHIVE_H_

# include "main.h"

typedef struct		s_file
{
  char			*path;
  struct s_file		*next;
}			t_file;

typedef struct		s_arg
{
  t_file		*files;
}			t_arg;

char *strdup(const char *);

#endif /* !MY_ARCHIVE_H_ */

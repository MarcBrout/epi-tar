/*
** my_archive.h for tarball
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan  8 21:17:18 2016 marc brout
** Last update Sat Jan  9 06:24:17 2016 marc brout
*/

#ifndef MY_ARCHIVE_H_
# define MY_ARCHIVE_H_

typedef struct		s_file
{
  char			*path;
  t_header		header;
  struct s_file		*next;
}			t_file;

typedef struct		s_arg
{
  t_file		*files;
}			t_arg;

void calc_chksum(t_header *);
char launch_my_archive(char **);
char add_file_to_list(t_arg *, char *);
char create_all_headers(t_arg *);
char create_header(t_file *);
char file_type(struct stat *);
void archive_files(t_arg *, char *);
void write_tar(t_header *, int, int);

#endif /* !MY_ARCHIVE_H_ */

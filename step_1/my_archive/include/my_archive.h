/*
** my_archive.h for tarball
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan  8 21:17:18 2016 marc brout
** Last update Sat Jan  9 21:04:02 2016 marc brout
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
  char			zero[512];
  int			pad;
}			t_arg;

void calc_chksum(t_header *);
char header_start(t_file *, struct stat *);
char launch_my_archive(char **);
char add_file_to_list(t_arg *, char *);
char create_all_headers(t_arg *);
char create_header(t_file *);
char file_type(struct stat *);
char archive_files(t_arg *, char *);
char write_tar(t_arg *, t_header *, int, int);

#endif /* !MY_ARCHIVE_H_ */

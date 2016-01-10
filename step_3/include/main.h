/*
** main.h for main header
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Jan  7 20:56:14 2016 
** Last update Sun Jan 10 04:47:41 2016 
*/

#ifndef MAIN_H_
# define MAIN_H_
# define _BSD_SOURCE

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pwd.h>
# include <grp.h>
# include <ctype.h>
# define NO_ARGS ("No parameter\n")
# define MISSING_F ("missing -f option\n")
# define MISSING_ARCHIVE ("missing archive\n")

typedef struct		s_header
{
  char			name[100];
  char			mode[8];
  char			uid[8];
  char			gid[8];
  char			size[12];
  char			mdate[12];
  char			chksum[7];
  char			space[1];
  char			type[1];
  char			link[100];
  char			magic[6];
  char			version[2];
  char			uname[32];
  char			gname[32];
  char			devmajor[8];
  char			devminor[8];
  char			prefix[155];
  char			end[12];
}			t_header;

void			disp_parser(char*);
int			check_conflict(int args[], char file[]);
int			my_parser(int, char**, int args[], char file[]);
#endif /* !MAIN_H_ */

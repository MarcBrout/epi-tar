/*
** main.h for main header file in /home/troncy_l/prog/PSU_2015_minishell1/include
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Jan  7 20:56:14 2016 
** Last update Sat Jan  9 21:14:24 2016 
*/

#ifndef MAIN_H_
# define MAIN_H_

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/sendfile.h>
# include <math.h>
# include <fcntl.h>

int			my_untar(int fd);

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

#endif /* !MAIN_H_ */

/*
** main.h for main
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu Jan  7 20:56:14 2016 
** Last update Sat Jan  9 04:10:05 2016 marc brout
*/

#ifndef MAIN_H_
# define MAIN_H_

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_header
{
  char			name[100];
  char			mode[8];
  char			uid[8];
  char			gid[8];
  char			size[12];
  char			mdate[8];
  char			chksum[8];
  char			type;
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

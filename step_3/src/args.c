/*
** args.c for args parser in /home/troncy_l/prog/Rush1/step_3
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sun Jan 10 01:42:48 2016 
** Last update Sun Jan 10 04:58:00 2016 
*/

#include "main.h"

void		disp_err(char *err)
{
  dprintf(2, err);
}

int		check_conflict(int args[], char file[])
{
  if (args[3] != 1)
    {
      disp_err(MISSING_F);
      return (-1);
    }
  else if (file[0] == '\0')
    {
      disp_err(MISSING_ARCHIVE);
      return (-1);
    }
  return (0);
}

int		my_parser(int argc,
			   char **argv,
			   int args[],
			   char file[])
{
  int		c;
  int		i;
  char		flags[7];
  int		tmp;

  tmp = 0;
  sprintf(flags, "xcvftp");
  while ((c = getopt(argc, argv, "xcvf:tp")) != -1)
    {
      i = 0;
      if (c == 'f')
	{
	  if (optarg != NULL)
	    strcpy(file, optarg);
	  else
	    file[0] = '\0';
	}
      while (i < 6)
	{
	  if (c == flags[i])
	    {
	      args[i] = 1;
	      tmp++;
	    }
	  i++;
	}
    }
  if (tmp == 0)
    {
      disp_err(NO_ARGS);
      return (-1);
    }
  else
    return (check_conflict(args, file));
}

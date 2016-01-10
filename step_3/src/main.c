/*
** main.c for main function in /home/troncy_l/prog/Rush1/step_3
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sun Jan 10 01:30:11 2016 
** Last update Sun Jan 10 07:49:25 2016 
*/

#include "main.h"

int		main(int argc, char **argv)
{
  int		args[6];
  int		i;
  char		file[100];

  if (argc == 1)
    {
      disp_err(NO_ARGS);
      return (-1);
    }
  file[99] = '\0';
  i = 0;
  while (i < 6)
    args[i++] = 0;
  if (my_parser(argc, argv, args, file) == -1)
    {
      write(2, ":(\n", 3);
      return (1);
    }
  my_start();
  return (0);
}

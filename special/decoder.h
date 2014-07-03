/*
** decoder.h for decoder in /home/casoni_f/Projets/selma/selmakey/special
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Thu Jul  3 13:42:31 2014 Fabien Casoni
** Last update Thu Jul  3 16:51:00 2014 Fabien Casoni
*/

#ifndef			_DECODER_H_
# define		_DECODER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <search.h>

#define			NB_KEYS_MAX 104

struct			s_keymap
{
  char			*keycode;
  char       		*keyname;
};


typedef struct		s_decoder
{
  FILE			*file;
  int			keycode[3];
  ENTRY			entry;
  char			*tmp;
}			t_decoder;

#endif			/* _DECODER_H_ */

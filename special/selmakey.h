/*
** selmakey.h for selmakey in /home/casoni_f/Projets/selma/selmakey/special
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Jul  2 18:58:49 2014 Fabien Casoni
** Last update Wed Jul  2 18:59:34 2014 Fabien Casoni
*/

#ifndef		_SELMAKEY_H_
# define	_SELMAKEY_H_

#define NB_MAX_EVENTS 100

typedef struct		s_kl
{
  int			fd;
  int			epoll_fd;
  int			ctrl;
  int			ret;
  struct epoll_event	epoll_event;
  struct epoll_event	*events;
  FILE			*file;
  struct input_event	kbd_event;
}			t_kl;

#endif		/* _SELMAKEY_H_ */

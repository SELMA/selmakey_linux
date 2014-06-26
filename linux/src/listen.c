/*
** listen.c for selmakey in /home/alexmog/projets/SELMA/selmakey/linux/src
** 
** Made by Moghrabi Alexandre
** Login   <alexmog@epitech.net>
** 
** KeyHandling
** 
** Started on  Thu Jun 26 21:55:54 2014 Moghrabi Alexandre
** Last update Thu Jun 26 22:25:08 2014 Moghrabi Alexandre
*/

#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdio.h>

void			send_keycode(int code)
{
  printf("%d\n", code);
}

void			start_listening(int fd)
{
  struct input_event	event;
  unsigned int		readed;

  while (1337)
    {
      memset(&event, 0, sizeof(struct input_event));
      readed = read(fd, &event, sizeof(struct input_event));
      if (readed == sizeof(struct input_event)
	  && event.type == EV_KEY && event.value == 0)
	send_keycode(event.code);
    }
}

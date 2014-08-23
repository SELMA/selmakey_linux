/*
** decoder.c for decoder in /home/casoni_f/Projets/selma/selmakey/special
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Jul  2 19:00:26 2014 Fabien Casoni
** Last update Thu Jul  3 17:28:59 2014 Fabien Casoni
*/

#include "decoder.h"

struct s_keymap	keymap[] = 
{
  "0",  "[RESERVED]",
  "1",  "[ESC]",
  "2",  "1",
  "3",  "2",
  "4",  "3",
  "5",  "4",
  "6",  "5",                   
  "7",  "6",                   
  "8",  "7",                   
  "9",  "8",                   
  "10", "9",
  "11", "0",
  "12", "-",
  "13", "=",
  "14", "[BACKSPACE]",
  "15", "[TAB]",
  "16", "q",
  "17", "w",                   
  "18", "e",                   
  "19", "r",                   
  "20", "t",                   
  "21", "y",                   
  "22", "u",                   
  "23", "i",                   
  "24", "o",                   
  "25", "p",                   
  "26", "[",           
  "27", "]",          
  "28", "[ENTER]",               
  "29", "[LEFT_CTRL]",            
  "30", "a",                   
  "31", "s",                   
  "32", "d",                   
  "33", "f",                   
  "34", "g",                   
  "35", "h",                   
  "36", "j",                   
  "37", "k",                   
  "38", "l",                   
  "39", ";",           
  "40", "KEY_APOSTROPHE",          
  "41", "KEY_GRAVE",               
  "42", "[LEFT_SHIFT]",           
  "43", "\\",           
  "44", "z",                   
  "45", "x",                   
  "46", "c",                   
  "47", "v",                   
  "48", "b",                   
  "49", "n",                   
  "50", "m",                   
  "51", ",",               
  "52", ".",                 
  "53", "/",               
  "54", "[RIGHT_SHIFT]",          
  "55", "*",          
  "56", "[LEFT_ALT]",             
  "57", "[SPACE]",               
  "58", "[CAPS_LOCK]",            
  "59", "[F1]",                  
  "60", "[F2]",                  
  "61", "[F3]",                  
  "62", "[F4]",                  
  "63", "[F5]",                  
  "64", "[F6]",                  
  "65", "[F7]",                  
  "66", "[F8]",                  
  "67", "[F9]",                  
  "68", "[F10]",                 
  "69", "[NUMLOCK]",             
  "70", "[SCROLLLOCK]",          
  "71", "[KP7]",                 
  "72", "[KP8]",                 
  "73", "[KP9]",                 
  "74", "[KPMINUS]",             
  "75", "[KP4]",                 
  "76", "[KP5]",                 
  "77", "[KP6]",                 
  "78", "[KPPLUS]",              
  "79", "[KP1]",                 
  "80", "[KP2]",                 
  "81", "[KP3]",                 
  "82", "[KP0]",                 
  "83", "[KPDOT]",               
  "87", "[F11]",                 
  "88", "[F12]",                 
  "96", "[KPENTER]",             
  "97", "[RIGHT_CTRL]",           
  "98", "[KPSLASH]",             
  "99", "[SYSRQ]",               
  "100", "[RIGHTALT]",            
  "101", "[LINEFEED]",            
  "102", "[HOME]",                
  "103", "[UP]",                  
  "104", "[PAGEUP]",              
  "105", "[LEFT]",                
  "106", "[RIGHT]",               
  "107", "[END]",                 
  "108", "[DOWN]",                
  "109", "[PAGEDOWN]",            
  "110", "[INSERT]",              
  "111", "[DELETE]",              
  "117", "[KPEQUAL]",             
  "118", "[KPPLUSMINUS]",         
  "119", "[PAUSE]",
};

void		start_decode(t_decoder *decoder)
{
  ENTRY		*result;
  int		shift;
  int		caps_lock;

  shift = 0;
  caps_lock = 0;
  while (1337)
    {
      if (fscanf(decoder->file, "%d\n%d\n%d\n", &decoder->keycode[0],
		 &decoder->keycode[1], &decoder->keycode[2]) < 0)
	exit(1);
      decoder->tmp = (char *)malloc(sizeof(int));
      sprintf(decoder->tmp, "%d", decoder->keycode[0]);
      decoder->entry.key = decoder->tmp;
      result = hsearch(decoder->entry, FIND);
      free(decoder->tmp);
      if (result)
	{
	  if (decoder->keycode[1] == 1)
	    {
	      printf("%s", (char *)result->data);
	      if (strcmp((char *)result->data, "[ENTER]") == 0
		  || strcmp((char *)result->data, "[KPENTER]") == 0)
		printf("\n");
	      else if (caps_lock == 0 &&
		       strcmp((char *)result->data, "[CAPS_LOCK]") == 0)
		fscanf(decoder->file, "%d\n", &caps_lock);
	      else if (caps_lock == 1 &&
		       strcmp((char *)result->data, "[CAPS_LOCK]") == 0)
		caps_lock = -1;
	    }
	  else if (decoder->keycode[1] == 2)
	    {
	      if (shift == 0 && (strcmp((char *)result->data, "[LEFT_SHIFT]") == 0
				 || strcmp((char *)result->data, "[RIGHT_SHIFT]") == 0))
		shift = 1;
	      else
		printf("%s", (char *)result->data);
	    }
	  else if (decoder->keycode[1] == 0)
	    {
	      if (shift == 1 && (strcmp((char *)result->data, "[LEFT_SHIFT]") == 0
				 || strcmp((char *)result->data, "[RIGHT_SHIFT]") == 0))
		{
		  shift = 0;
		  printf("[END_OF_SHIFT]");
		}
	      else if (caps_lock == -1 &&
		       strcmp((char *)result->data, "[CAPS_LOCK]") == 0)
		fscanf(decoder->file, "%d\n", &caps_lock);
	    }
	}
    }
}

int		main(int ac, char **av)
{
  t_decoder	*decode;
  int		i;

  if (ac != 2)
    {
      printf("Usage : %s filename\n", av[0]);
      return (-1);
    }
  if ((decode = malloc(sizeof(*decode))) == NULL
      || !(decode->file = fopen(av[1], "r")))
    return (-2);
  hcreate(NB_KEYS_MAX);
  i = -1;
  while (++i < NB_KEYS_MAX)
    {
      decode->entry.key = (char *)keymap[i].keycode;
      decode->entry.data = (void *)keymap[i].keyname;
      if (hsearch(decode->entry, ENTER) == NULL)
	return (-3);
    }
  start_decode(decode);
  hdestroy();
  fclose(decode->file);
  free(decode);
}

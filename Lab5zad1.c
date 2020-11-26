#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
  int fd_tab[2];
  pid_t pid;
  int bufor[50];

  if(pipe(fd_tab)==-1)
    {
      fprintf(stderr, "Blad w tworzeniu pipe'a \n");
      return -1;
    }

  pid = fork();

  if(pid>0)
    {
      // rodzic
      close(fd_tab[0]);

      int plik = open(argv[1],O_RDONLY);
      while(read(plik, bufor, 50)>0) 
	{
	  write(fd_tab[1], bufor, strlen(bufor));
	}
      
      close(fd_tab[1]);
      return 0;
    }else if(pid==0)
    {
      // dziecko
      close(fd_tab[1]);

      while(read(fd_tab[0], bufor, 50)>0)
	{
	  write(STDOUT_FILENO, "#", 1);
	  write(STDOUT_FILENO, bufor, 50);
	  write(STDOUT_FILENO, "#", 1);
	}
   
      close(fd_tab[0]);
      exit(1);
      
    }else if(pid<0)
    {
       fprintf(stderr, "Blad - PID<0 \n");
       return -1;
    } 
}

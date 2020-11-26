#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  int fd_tab[2];
  pid_t pid;
  int bufor[50];
  char nazwa[50];

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
      printf("\nPodaj nazwe pliku: \n");
      scanf("%s", nazwa);
      
      int plik = open(nazwa, O_RDONLY);

      while(read(plik, bufor, 1)>0)
	{
	  write(fd_tab[1], bufor, 1);
	}
      
      close(fd_tab[1]);
      return 0;
    }else if(pid==0)
    {
      // dziecko
      close(fd_tab[1]);
      close(0); 
      dup(fd_tab[0]);

      execlp("/usr/bin/display","display",(char *)NULL);
      close(fd_tab[0]);
      exit(1);
      
    }else if(pid<0)
    {
       fprintf(stderr, "Blad - PID<0 \n");
       return -1;
    } 
}

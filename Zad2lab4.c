#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <ucontext.h>

int licznik = 100;

void catcha(int sig)
{
  printf("Zlapano SIGALRM \n");
  exit(0);
}

void catchb(int sig)
{
  printf("Zlapano SIGTERM \n");
}

void catchc(int sig)
{ 
  printf("Zlapano SIGUSR1 \n");
  sigignore(SIGUSR1);
  licznik = 0;
}

void catchd(int sig)
{
}


int main()
{
  int i = 0;

  struct timespec tim1, tim2;
  tim1.tv_sec = 0;
  tim1.tv_nsec = 100000000;

  signal(SIGALRM, catcha);
  signal(SIGTERM, catchb);

  signal(SIGUSR2, catchd);

while(1)
  {

    
   if(licznik == 100)
  {
      signal(SIGUSR1, catchc);
  }

   if(licznik < 100)
    {
      licznik++;
    }
    
    i++;
    printf("%d \n",i);

    nanosleep(&tim1, &tim2);
  }
 return 0;
}

#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <ucontext.h>


int main()
{
  int i = 0;

  struct timespec tim1, tim2;
  tim1.tv_sec = 0;
  tim1.tv_nsec = 100000000;

while(1)
  { 
    i++;
    printf("%d \n",i);

    nanosleep(&tim1, &tim2);
  }
 return 0;
}

/*
By zwiększyć częstotliwość odświerzania się polecenia top 
należy dodać -d [parametr], gdzie parametr to czas w sekundach
co jaki się polecenie odświeża
*/

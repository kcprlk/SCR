#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *Hello(void *threadID)
{
  printf("Hello SCR. Written by thread %ld\n", threadID);
  pthread_exit(NULL);
}

int main()
{
  int numOfThreads = 10;
  pthread_t threads[numOfThreads];
  int err;

  
  for( int i = 0; i < numOfThreads; i++)
    {
      err = pthread_create(&threads[i], NULL, Hello, (void *)i);
      if (err)
	{
	  printf("ERROR, from %d\n", err);
	  exit(-1);
	}

    }
  pthread_exit(NULL);
}


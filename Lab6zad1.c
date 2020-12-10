#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>


int main()
{
  char NazwaPliku[50];
  int plik[2];
  int length;
  char *ptr;

    while(1)
      {
	    printf("\nPodaj nazwe pliku \n");
	    scanf("%s", NazwaPliku);
	    plik[0] = open(NazwaPliku, O_RDONLY);

	    plik[1]= open("plik1", O_CREAT | O_RDWR);
	
	length = lseek(plik[0], 0, SEEK_END);
	lseek(plik[0],0,SEEK_SET); 

	ftruncate(plik[1], length);
	
	ptr =(char *) mmap(0, length, PROT_READ | PROT_WRITE, MAP_SHARED, plik[1], 0);
	read(plik[0], ptr, length);
	msync(plik[1], length, MS_SYNC);
	close(plik[0]);
	close(plik[1]);
      }
    return 0;
}

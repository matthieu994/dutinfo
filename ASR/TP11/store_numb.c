#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main (int argc, char *argv[]) {
  if(argc < 2) {
    fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
    exit(1);
  }
  int fd, n, r, buf[256];
  fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0600);

  if(n == -1) {
    perror("read of file fails");
    exit(3);
  }
  
  do {
    write(1, "Number: ", 9);
    n = read(0, buf, 256);
    
    r = write(fd, buf, n);
    if(r == -1) {
      perror("Write fails");
      exit(3);
    }
  } while(n);
  exit(0);
}

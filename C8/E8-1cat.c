/* rewrite of cat without standard library */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    void filecopy(int fdin, int fdout);

    if (argc == 1)  /* no args; copy standard input */
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                filecopy(fd, 1);
                close(fd);
            }
    return 0;
}

void filecopy(int fdin, int fdout)
{
    int n;
    char buf[BUFSIZE];

    while (n = read(fdin, buf, BUFSIZE) > 0)
        write(fdout, buf, n);
}
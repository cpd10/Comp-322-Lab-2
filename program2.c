/*
    Darius Hooks
    COMP 322
    Lab #2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void main(int argc, char* argv[])
{
    pid_t cpid;
    int i;
    pid_t cpid, mypid;
    pid_t pid = getpid();         /* get current processes PID */
    printf("Parent pid: %d\n", pid);
    cpid = fork();
    if (cpid > 0) { /* Parent Process */
	mypid = getpid();
	printf("[%d] parent of [%d]\n", mypid, cpid);
    }  else if (cpid == 0) { /* Child Process */
	mypid = getpid();
	printf("[%d] child\n", mypid);
    } else {
	perror("Fork failed");
	exit(1);
    }
    printf("Done\n");
    exit(0);
}

#include <stdio.h>
#include <unistd.h> // fork
#include <stdlib.h> // exit

int main()
{
	int x = 100;
	int rc = fork();
	if(rc < 0)
	{
		printf("fork failed\n");
		exit(1);
	}
	else if(rc == 0) // child process
	{
		sleep(2);
		printf("Before change x, I am child process %d,x=%d\n",getpid(),x);
        x = 1;
		printf("After change x, I am child process %d,x=%d\n",getpid(),x);
	}
	else
	{
		//sleep(2);
		printf("Before change x,I am parent process %d of %d, x=%d\n", getpid(),rc,x);
		x = 2;
		printf("After change x,I am parent process %d of %d, x=%d\n", getpid(),rc,x);
	}
	return 0;
}

/*
    Q: Write a program that calls fork(). Before calling fork(), have the
    main process access a variable (e.g., x) and set its value to
    something (e.g., 100). What value is the variable in the child
    process? What happens to the variable when both the child and
    parent change the value of x?

    A: After the fork, the value of the variable in both the child and
    parent is 100. Each has its own copy of the variable and changing
    the value of x in one does not change the value of x in the other.
*/

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

/*
 *  this program creates 12 child processes by using 2 while loops and a counter.
 *  The structure is one in which the original program has 3 children and 
 *  each child has 3 children of its own. Each while loop only allows creation
 *  of child programs on the condition that a program is a parent. In the second
 *  loop the children are artificially set to parents so they are able to perform
 *  the same process as the original parent.
 *
 *  I tested it by drawing out a structure of 12 children that followed the rules and printed out
 *  the "round" or height of each child process being created to check for correctness
 */ 

#include <stdio.h>
#include <sys/types.h>

int main(){

	int counter =0;
    int status;
	pid_t pid;
	pid = 1;//sets original id to be a parent
	
	//creates 3 children from original parent
	while(counter<3 && pid>0){
		pid = fork();
		counter++; //increments counter after a fork
        printf("parent:%d child:%d\n", getppid(), getpid());
		
	
	}
    if(pid!=0){
        waitpid(-1, &status, 0);
        return 0;
    }
	
    pid=1;
    counter=0;
    //creates 3 child processes for each child using same loop as above
    while(counter<3 && pid>0){
        pid=fork();
        if(pid!=0)
            waitpid(-1,&status, 0);
        counter++;
        printf("parent:%d child:%d\n", getppid(), getpid());
    }
	
	return 0;	
}

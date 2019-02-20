/*
 * The purpose of this program is to launch 17 child processes. 
 * program starts by immediately creating 3 child programsby forking twice. 
 * Then only the 2 current parents are allowed to launch child processes.
 * This leeves 5 children, 4 of which have a pid of 0. These 4 with id 0
 * then create 3 subprocesses each using similar code to the previous problem 
 *
 * I tested this by drawing out my intended solution and then printing values 
 * and counting the results to make sure it worked as intended 
 */
#include <stdio.h>
#include <sys/types.h>

int main(){

	pid_t pid;
	pid = fork();
	printf("num0:%d\n", pid); //0th round with pid
	pid=fork();
	printf("num1:%d\n",pid);//1st round with pid
	if(pid>1)
		pid = fork(); 
		printf("num2:%d\n", pid);//2nd round with pid
	if(pid==0){
		pid = 1; //sets current children to "parents"
		int counter=0;
		while(counter<3 && pid>0){//creates 3 children for each current child
			pid = fork();
			counter++;
			printf("num2:%d\n", pid); //2nd round with pid
		
	
		}
	}

	return 0;	
}

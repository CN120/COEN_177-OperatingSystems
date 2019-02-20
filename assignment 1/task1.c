/*
 * 	Chris Nelson
 * 	COEN 177
 * 	task1.c 
 * 	
 * 	Summary:
*	this program creates a new child process of hello world everytime 
*	the user inputs something that is not the exit code which in this case
*	is "exit". When the exit code is entered the, the program terminates
*
*	Tested by:  having it run a new hello world progra each time
*	something is entered and if it continued printing hello world when 
*	"exit" was entered I knew I did something wrong   	
*/
#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
while(1){
	char input[20]; //array to take in input
	char exitcode[] = "exit";
	int status;
	scanf("%s",&input); //captures input

	if(strcmp(exitcode, input)==0){
		return 0; //terminate program
	} 

	pid_t pid = fork();
	if(pid !=0) {
		waitpid(-1, &status, 0);
	}
	else{
		execve("hello", NULL, NULL);
		//runs helloworld.c
	}
	
	

}
}

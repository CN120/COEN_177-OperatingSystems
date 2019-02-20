
/* Chris Nelson
 * COEN_177
 *
 * Summary:
 * This program's purpose is to create eight child processes.
 * This is done simply by calling fork on a program only if that program
 * is a child of another processs and the counter has not yet reached 8.
 * In essense it creates a linear inheritance structure of 
 * height 9: 8 children and 1 parent. 
 *
 * Tested:
 * I tested this program by printing out the counter for number of
 * parents as #parents = #children in this case
*/

#include <stdio.h>
#include <sys/types.h>

int main(){
    int status;
	int counter =0; //counts number of programs creted
	pid_t pid;//process id
	int par = 0; //int boolean
	
	while(counter<8){	//loop to create 8 processes
		pid = fork(); //creates child process
		counter++;
		if(pid!=0){ //if process is a parent set prent to TRUE/1
			waitpid(-1, &status, 0);
            return 0;
			
		}
        printf("Child number %d\n", counter);
		
	
	}
    return 0;
}

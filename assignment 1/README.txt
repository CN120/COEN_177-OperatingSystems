Chris Nelson
Lab2
COEN_177
10/2/18


Note: task4 does not use waitpid. I could not get the program to work
using pid but I am almost certain it performs its intended action. I 
will make sure to utilize waitpid next time in lab as I understand it better now.

task1.c
I use an array to take input from the user. I then used strcmp to check if the entered
string was equal to the exit code. if it was the program returns and exits, otherwise
it calls a helloworld.c program.


task2.c
I use a counter that updates each time fork() is called. A while loop runs 8 times
creating a linear inheritance downward. Essentially, each child (program with pid=0) 
creates a new child until the number of children is equal to 8. The result should be saying "Child number" followed by the count

task3.c
Again I use a counter to count the number of children each child can create. pid is
originally set to 1, or a parent. Then 3 child processess are creted by calling fork 
only on the parents. Then I check for program with pid =0, set their pid to 1 and 
use the same parent code to have each child create 3 child processes, making 12 in total. 

task4.c
For this problem, I immediately fork twice, which creates 3 children, 2 of which will have 
a pid of 0. For each program with pid >0 I fork again, giving me 5 children, 4 of which have pid 
of zero. For each of these child processes, I set their pid to 1 and run a while loop that creates
3 children for a parent. This ends with each of the 4 children that had pid=0 having 3 children each,
and one other child from the begiining. This results in a total of 17 children.

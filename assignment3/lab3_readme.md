###task 1:
For this solution I simply found where the code for the banner was in Minix's main.c file. It was under the heading of "announce" and the line I added is on line 278.


###task2:
My solution to this scheduling task is fairly simple and can be found on lines 1314-1321 in proc.c. It runs as follows: As long as the queue that is currently being pointed to is greater than 7, to avoid messing with any critical programs needed to launch minix, then my code will randomly choose another queue to check for ready processes. I had to go through a fair amount of iterations before I got to this point. I went about testing minix by FTPing the file outside of minix and modifying it, and then putting it back into minix and rebooting it. On many of the trials, Minix would simply fail to launch because I was not checking for q>7, meaning I was interfering with critical startup programs. Also during this process, the program would not run the way I had written by initial random code by including time.h. Once this was removed and I figured out I needed to check for a q greater than at least 6, things ran more smoothly. The way I chose to randomize the choosing of processes, was to simply generate a random number and mod it with 10 to get a number from 0-9. Then I checked to see if this number was arbitrarily equal to 3, as a way to run my scheduling algorithm only 1/10 or 10% of the time compared to the normal scheduler. inside my scheduler, I again used a random number and a mod operation to randomly choose queue 8-15 as the one to next look for a ready process. The way that the normal scheduler works, as defined in the pick_proc function, is as follows. It uses 16 queues that hold processes, where lower numbered queues have higher priority than higher numbered queues, and will therefore be the first ones checked for ready processes. Within the queue, which is just an array, it will search for a ready program and if it runs into a queue with no ready process it simply continues onto the next queue and checks there. 

Questions:
1) how many queues are there?
	16 (0-15) from the header file
	it's defined this way in proc.h

2) Which queue is the highest priority? Lowest?
	queue 0 is the highest priority and queue 15 is the lowest

3) What C expression gives you the first ready process?
	rp = rdy_head[q] 
	rp is a pointer to a struct proc 
	ready_head is an array of struct proc pointers
3.1) what if that queue has no ready process
	pointer will be updated to point to a new queue. If no queues have ready processes in them, then the lowest queue contains IDLE, which is a program that is always ready.

4) Which queues are affected?
	queues 8-15

5) What is the probability that randomization takes place?
  there is a 10% chance of randomization due to the way i wrote my code. I simply moded a random number by 10 and randomized q only if the modded number returned 3

6) What parameter is being randomized?
	q is being randomized, or in other words the index to the array that chooses which process queue to check for processes next

7) What difference do you observe?
	ready processes will take longer to be granted CPU time and therefore will take longer to run	


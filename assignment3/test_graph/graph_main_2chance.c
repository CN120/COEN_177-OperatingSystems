  
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  int length = atoi(argv[1]); /*gets cache size from command line*/
  int table[length]; 
  int ref[length];
  int page, found,i,j;
  int current=0;
  /*for testing */
  int graphval=0;
  /*		*/
  for(i=0; i<length; i++){
    ref[i]=0;	
  }

  for(i=0; i<10000;i++){
    scanf("%d", &page);
    /* search loop*/
    found=-1;
    //printf("page = %d\n", page);
    
    for(j=0; j<length; j++){
      if (table[j]==page){
	//printf("search\n");
	found = 1;
	ref[j]=1;
	break;
      }
    }
    
    /*end search*/
    
    if(found==-1){
      for(j=current;ref[j]==1;j=(j+1)%length){
	ref[j]=0;
      }
      table[j]=page;
      current=(j+1)%length;
      // printf("%d\n", page);
      
      graphval++;
    }
      
       
  }
  
  printf("Graph y value is %d: ", graphval);
  
}



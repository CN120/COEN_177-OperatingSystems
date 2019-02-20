
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  int length = atoi(argv[1]); /*gets cache size from command line*/
  int table[length]; 
  int ref[length];
  int page, found,i,j;
  int current=0;

  for(i=0; i<length; i++){
    ref[i]=0;	//reference bits set to zero
  }

  for(i=0; i<10000;i++){
    scanf("%d", &page);
      
    /* search loop*/
    found=-1;
    for(j=0; j<length; j++){
      if (table[j]==page){
          found = 1;
          ref[j]=1; //set reference bit to 1
          break;
      }
    }
    /*end search*/
    
    if(found==-1){
    /* sets reference bits to zero as "head pointer" passes over referenced bits */
      for(j=current;ref[j]==1;j=(j+1)%length){
          ref[j]=0;
      }
    
      table[j]=page; //replaces first page with ref=0 since last time it was seen
      current=(j+1)%length; //update "head pointer"
      printf("%d\n", page);
    }
      
       
  }
}


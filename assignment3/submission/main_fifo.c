  
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  
  int length = atoi(argv[1]); 
  int table[length];
  int page, found,i,j;
  int fifo_loc=0; //keeps track of oldest inserted page

  for(i=0; i<10000;i++){
    scanf("%d", &page);
      
    /* search loop*/
    found=0;
    for(j=0; j<length; j++){
      if (table[j]==page){
          found = 1;
          break;
      }
    }
    /*end search*/
    
    /* if not found, replace page */
    if(found==0){
      table[fifo_loc]=page;
      fifo_loc= (fifo_loc+1)%length;
      printf("%d\n", page);
    }
  }
}

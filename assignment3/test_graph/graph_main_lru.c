  
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int length = atoi(argv[1]); 
  int table[length];
  int page, found,i,j,k;

  int graphval=0;

  for(i=0; i<10000; i++){
    scanf("%d", &page);
    /* search loop*/
    found=-1;
    //printf("page = %d\n", page);
    
    for(j=0; j<length; j++){
      if (table[j]==page){
	//printf("search\n");
	found = j;
	break;
      }
    }
    
    /*end search*/
    
    if(found==-1){
      for(k=length-1; k>0; k--){
	table[k] = table[k-1];
      }
      table[0]=page;
      // printf("%d\n", page);
      
      graphval++;
    }
    else{
      int temp= table[found];
      //printf("loc = %d\n", found);
      for(k=found; k>0; k--){
	table[k]=table[k-1];
      }
      table[0]=temp;
    }
  }
      
  printf("Graph y value is: %d\n", graphval);
       
}



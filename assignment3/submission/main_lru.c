  
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int length = atoi(argv[1]); 
  int table[length];
  int page, found,i,j,k;
  for(i=0; i<10000; i++){
    scanf("%d", &page);
      
    /* search loop*/
    found=-1;   //not found != 0 in case page found at position zero
    
    for(j=0; j<length; j++){
      if (table[j]==page){
          found = j;
          break;
      }
    }
    /*end search*/
    
    /* if not found, move everything in table down
     and insert new item in position 0 */
    if(found==-1){
      for(k=length-1; k>0; k--){
          table[k] = table[k-1];
      }
      table[0]=page;
      printf("%d\n", page);
    }
    /* if page found, move it to head of array */
    else{
      int temp= table[found];
      for(k=found; k>0; k--){
          table[k]=table[k-1];
      }
      table[0]=temp;
    }
  }
      
      
       
}



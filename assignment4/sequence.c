#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
  clock_t start_t, end_t; 
  double total_t;
  FILE *fp = fopen(argv[1],"r"); //opens passed file for reading
  char *buffer = malloc(sizeof(char)*4);    //creates buffer for characters to be read to
  start_t=clock();
  printf("start time: %f\n", start_t);
  //sleep(7);
  fseek(fp,0, SEEK_SET);    //seek to start of file
  //reads all of file sequentially
  while(fread(buffer,1, 1, fp)==1){
  }
  fclose(fp);
  end_t = clock();
  //calculate and print time taken by cpu
  total_t = (double)(end_t-start_t)/CLOCKS_PER_SEC;
  printf("Total time taken by CPU: %f\n", total_t);
  printf("end time: %f\n", end_t);


}

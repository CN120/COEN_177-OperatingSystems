#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    clock_t start_t, end_t;
    double total_t;
    srand(time(0)); //initializes random key
    int r; //for random integer
    
    FILE *fp = fopen(argv[1],"r");  //read in file
    char *buffer = malloc(sizeof(char)); //buffer for reading
    
    /*
     gets file size to calculate number of reads to make
     in the for loop
     */
    fseek(fp, 0, SEEK_END);
    int sz = ftell(fp);
    printf("File size is: %d bytes\n",sz);
    //starts clock
    start_t=clock();
    //printf("start time: %lu\n", start_t);
    int numReads = sz/10; //decrease number of bytes that will be randomly read
    //reeds random bytes throughout the file
    for(int i=0; i<numReads; i++){
        r=rand()%sz;
        fseek(fp,r, SEEK_SET);
        fread(buffer,1, 1, fp);
    }
    
    fclose(fp);
    //calculates time taken
    end_t = clock();
    total_t = (double)(end_t-start_t)/CLOCKS_PER_SEC;
    //printf("end time: %lu\n", end_t);
    printf("Total time taken by CPU:\n %f secs\n\n", total_t);
    


}

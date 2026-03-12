//dynamic memory implementation over here
#include <stdio.h>
#include <stdlib.h>

int main(){
        int *ptr = (int *)malloc(20);
        //int *ptr = (int *)malloc(sizeof(int) * 5);
        if(ptr == NULL){
                printf("Allocation Failed");
                exit(0);
        }

        for(int i = 0; i < 5; i++)
                ptr[i] = i + 1;

        for(int i = 0; i < 5; i++)
                printf("%2d ", ptr[i]);

        //calloc : no garbage values, the memory is initialized to zero
        int *newptr = (int *)calloc(5, sizeof(int));
        if(newptr == NULL){
                printf("Allocation Failed");
                exit(0);
        }
        printf("\n");
        for(int i = 0; i<5; i++)
                printf("%d ", newptr[i]);
        //the memory allocated using functions malloc() and calloc() is not de-allocated on their own.
        //the free() function is used to release dynamically allocated memory back to the operating system.
        
        free(ptr);
        free(newptr);
        //realloc() function is used to resize a previously allocated memory block.
        int *pointer = (int *)malloc(5*sizeof(int));

        int *temp = (int *)realloc(pointer, 10*sizeof(int));

        if(pointer == NULL){
                printf("Memory Reallocation Failed");
                exit(0);
        }//the original memory is not deallocated so it might cause fragmentation and memory leaks
        else{
                pointer = temp;
        }
        free(pointer);


        return 0;
}

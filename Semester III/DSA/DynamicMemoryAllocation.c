// Dynamic Memory Allocation --> malloc(), calloc(), realloc(), free()

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("Enter num: ");
    scanf("%d", &n);
    
    // malloc()
    int* arr = (int*) malloc(n* sizeof(int));

    // checking for default values -- Garbage values with malloc
    for (int i =0; i<n; i++){
        printf("%d  ", arr[i]);
    }
    
    // Taking members for array
    for(int i = 0; i<n; i++){
            arr[i] = i + 1;
    }
        
    // printing address of each elemnent
    printf("\nIndex\tValue\tAddress\n");
    for(int i=0; i<n; i++) {
        printf("%d\t %d\t%p\n", i, arr[i], &arr[i]);
    }
   

    // using realloc()
    arr = (int*) realloc(arr, 2*n*sizeof(int));  // Increase arr size by 2X

    // Taking "Extended" members for array
    for(int i = n; i < 2 * n; i++){
        arr[i] = i + 1;
    }

    // Printing Extended members
    for(int i = n; i < 2*n; i++) {
        printf("%d\t %d\t%p\n", i, arr[i], &arr[i]);
    }


    // Calloc 

    int* array = (int*) calloc(n, sizeof(int));

    printf("\nIndex\tValue\tAddress\n");

    for(int i=0; i<n; i++) {
        printf("%d\t %d\t%p\n", i, array[i], &array[i]);
    }


    //free()
    free(arr);
    free(array);

    return 0;
}
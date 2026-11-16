#include <stdlib.h> 

void double_free();
void use_after_free();
void memory_leak();
void buffer_overflow();

// ------- Instructions to run --------
// 1. Compile c file: gcc -o example example.c
// 2. Run Valgrind: valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./program
// 3. Repeat after removing comment of a function in main to try out a specific memory leak

void double_free() {
    int *ptr = malloc(sizeof(int));

    free(ptr); // Double Free
    free(ptr); 
}

void use_after_free() {
    int *ptr = malloc(sizeof(int));
    *ptr = 42;

    free(ptr);

    printf("%d\n", *ptr); // Use-after-free
}

void memory_leak() {
    int *ptr = malloc(sizeof(int));
    *ptr = 100; 
} // allocated memory from ptr loses reference -> memory leak

void buffer_overflow() {
    int *arr = malloc(3 * sizeof(int));

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    arr[3] = 40; // Out-of-bounds write

    free(arr);
}


int main(void) {
    double_free();
    //use_after_free();
    //memory_leak();
    //buffer_overflow();
}
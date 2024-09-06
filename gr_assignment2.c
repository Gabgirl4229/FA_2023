#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "common_threads.h"

int num[100];

void *mythread(void *arg) {
    long int value = (long int) arg;
    long int result;
    printf("%ld\n", value);

    if (value == 0) {
        result = 0;
    } else if (value == 1) {
        result = 1;
    } else {
        result = num[value - 1] + num[value - 2];
    }
    return (void *) result;
}

int main(int argc, char * argv[]) {
    pthread_t p;
    long int rvalue;

    int t = atoi(argv[1]);
    
    if (t <= 0) {
        printf("ERROR: number less than 1\n");
        return 0;
    }
    
    for (int i = 0; i < t; i++) {
        Pthread_create(&p, NULL, mythread, (void *) (long int) i);
        Pthread_join(p, (void **) &rvalue);
        num[i] = rvalue;
        
    }

    rvalue = num[t - 1];
    
    printf("Output: %ld\n", rvalue);
    return 0;
}
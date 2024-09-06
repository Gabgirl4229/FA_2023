#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //allows fork, sleep, and getpid functions
#include <sys/wait.h> //allows wait function

int main(int argc, char *argv[]) {

    //arrays for children
    int fd1[2];
    pipe(fd1);
    int fd2[2];
    pipe(fd2);
    int fd3[2];
    pipe(fd3);

    //variables for child amount and Fibonacci numbers
    int t = atoi(argv[1]);
    int num[3] = {atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};

    //variable for final result
    int sum = 0;
    
    //start code for parent
    puts("");
    printf("I am parent. PID: %d\n", (int) getpid());
    printf("I have %d children.\n", t);

    //sending numbers to child 1
    if (t == 1) {
        //variables
        int fib0 = 0;
        int fib1 = 1;
        int result;
        
        //child 1
        puts("");
        printf("Sending %d to one of my children...\n", atoi(argv[2]));
        int rc = fork();

        if (rc < 0) {
            //fork failed, exit program
            fprintf(stderr, "Fork failed!\n");
            exit(1);
        } else if (rc == 0) {
            close(fd1[0]);

            //do the Fibonacci
            int j;
            for (j = 1; j <= num[0]; j++) {
                if (j == 1) {
                    result = fib0;
                } else if (j == 2) {
                    result = fib1;
                } else {
                    result = fib0 + fib1;
                    fib0 = fib1;
                    fib1 = result;
                }
            }

            write(fd1[1], &result, sizeof(result));

            //child speaks!
            puts("");
            printf("Hello! I am a child. PID: %d\n", (int) getpid());
            printf("Sending %d to my parent...\n", result);

            close(fd1[1]);
            exit(0); //KILL THE CHILD
        } else {
            //variables for parent
            int result1;
            int final = 0;

            //closing processes
            close(fd1[1]);
            read(fd1[0], &result1, sizeof(sum));
            final = result1;
            close(fd1[0]);

            //parent speaks now
            puts("");
            printf("Hello, I am the parent of %d. PID: %d\n", rc, (int) getpid());
            printf("The final sum is: %d\n", final);
        }
    }

    //sending numbers to children 1 and 2
    if (t == 2) {
        //variables
        int fib0 = 0;
        int fib1 = 1;
        int result;
        
        //child 1
        puts("");
        printf("Sending %d to one of my children...\n", atoi(argv[2]));
        int rc0 = fork();
        

        if (rc0 < 0) {
            //fork failed, exit program
            fprintf(stderr, "Fork failed!\n");
            exit(1);
        } else if (rc0 == 0) {
            close(fd1[0]);

            //do the Fibonacci
            int j;
            for (j = 1; j <= num[0]; j++) {
                if (j == 1) {
                    result = fib0;
                } else if (j == 2) {
                    result = fib1;
                } else {
                    result = fib0 + fib1;
                    fib0 = fib1;
                    fib1 = result;
                }
            }

            write(fd1[1], &result, sizeof(result));

            //child speaks!
            puts("");
            printf("Hello! I am a child. PID: %d\n", (int) getpid());
            printf("Sending %d to my parent...\n", result);

            close(fd1[1]);
            exit(0); //KILL THE CHILD
        }

        //child 2
        puts("");
        printf("Sending %d to one of my children...\n", atoi(argv[3]));
        int rc1 = fork();

        if (rc1 < 0) {
            //fork failed, exit program
            fprintf(stderr, "Fork failed!\n");
            exit(1);
        } else if (rc1 == 0) {
            close(fd2[0]);

            //do the Fibonacci
            int j;
            for (j = 1; j <= num[1]; j++) {
                if (j == 1) {
                    result = fib0;
                } else if (j == 2) {
                    result = fib1;
                } else {
                    result = fib0 + fib1;
                    fib0 = fib1;
                    fib1 = result;
                }
            }

            write(fd2[1], &result, sizeof(result));

            //child speaks!
            puts("");
            printf("Hello! I am a child. PID: %d\n", (int) getpid());
            printf("Sending %d to my parent...\n", result);

            close(fd2[1]);
            exit(0); //KILL THE CHILD
        } else {
            //variables for parent
            int result1, result2;
            int final = 0;

            //closing processes
            close(fd1[1]);
            read(fd1[0], &result1, sizeof(sum));
            final = final + result1;
            close(fd2[1]);
            read(fd2[0], &result2, sizeof(sum));
            final = final + result2;

            //parent speaks now
            puts("");
            printf("Hello, I am the parent of %d. PID: %d\n", rc1, (int) getpid());
            printf("The final sum is: %d\n", final);

            //close last tasks
            close(fd1[0]);
            close(fd2[0]);
        }
    }

    //sending numbers to children 1, 2, and 3
    if (t == 3) {
        //variables
        int fib0 = 0;
        int fib1 = 1;
        int result;
        
        //child 1
        puts("");
        printf("Sending %d to one of my children...\n", atoi(argv[2]));
        int rc2 = fork();

        if (rc2 < 0) {
            //fork failed, exit program
            fprintf(stderr, "Fork failed!\n");
            exit(1);
        } else if (rc2 == 0) {
            close(fd1[0]);

            //do the Fibonacci
            int j;
            for (j = 1; j <= num[0]; j++) {
                if (j == 1) {
                    result = fib0;
                } else if (j == 2) {
                    result = fib1;
                } else {
                    result = fib0 + fib1;
                    fib0 = fib1;
                    fib1 = result;
                }
            }

            write(fd1[1], &result, sizeof(result));

            //child speaks!
            puts("");
            printf("Hello! I am a child. PID: %d\n", (int) getpid());
            printf("Sending %d to my parent...\n", result);

            close(fd1[1]);
            exit(0); //KILL THE CHILD
        }
        
        //child 2
        puts("");
        printf("Sending %d to one of my children...\n", atoi(argv[3]));
        int rc3 = fork();

        if (rc3 < 0) {
            //fork failed, exit program
            fprintf(stderr, "Fork failed!\n");
            exit(1);
        } else if (rc3 == 0) {
            close(fd2[0]);

            //do the Fibonacci
            int j;
            for (j = 1; j <= num[1]; j++) {
                if (j == 1) {
                    result = fib0;
                } else if (j == 2) {
                    result = fib1;
                } else {
                    result = fib0 + fib1;
                    fib0 = fib1;
                    fib1 = result;
                }
            }

            write(fd2[1], &result, sizeof(result));

            //child speaks!
            puts("");
            printf("Hello! I am a child. PID: %d\n", (int) getpid());
            printf("Sending %d to my parent...\n", result);

            close(fd2[1]);
            exit(0); //KILL THE CHILD
        }
        
        //child 3
        puts("");
        printf("Sending %d to one of my children...\n", atoi(argv[4]));
        int rc4 = fork();

        if (rc4 < 0) {
            //fork failed, exit program
            fprintf(stderr, "Fork failed!\n");
            exit(1);
        } else if (rc4 == 0) {
            close(fd3[0]);

            //do the Fibonacci
            int j;
            for (j = 1; j <= num[2]; j++) {
                if (j == 1) {
                    result = fib0;
                } else if (j == 2) {
                    result = fib1;
                } else {
                    result = fib0 + fib1;
                    fib0 = fib1;
                    fib1 = result;
                }
            }

            write(fd3[1], &result, sizeof(result));

            //child speaks!
            puts("");
            printf("Hello! I am a child. PID: %d\n", (int) getpid());
            printf("Sending %d to my parent...\n", result);

            close(fd3[1]);
            exit(0); //KILL THE CHILD
        } else {
            //variables for parent
            int result1, result2, result3;
            int final = 0;

            //closing processes
            close(fd1[1]);
            read(fd1[0], &result1, sizeof(sum));
            final = final + result1;
            close(fd2[1]);
            read(fd2[0], &result2, sizeof(sum));
            final = final + result2;
            close(fd3[1]);
            read(fd3[0], &result3, sizeof(sum));
            final = final + result3;

            //parent speaks now
            puts("");
            printf("Hello, I am the parent of %d. PID: %d\n", rc4, (int) getpid());
            printf("The final sum is: %d\n", final);

            //close last tasks
            close(fd1[0]);
            close(fd2[0]);
            close(fd3[0]);
        }
    }
    return 0;
}
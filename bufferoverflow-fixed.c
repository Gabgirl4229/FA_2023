#include <stdio.h>
#include <string.h>

void secretFunction() {
    printf("Congratulations!\n");
    printf("You have entered in the secret function! The password is 12%Auda*city*11\n");
}

void FileCompress() {
    char buffer[20];
    char exists[28] = "test -f ";
    char zip[25] = "gzip ";
    char cp[45] = "cp ";
    char mv[45] = "mv ";
    int status;

    printf("Enter file name to compress:\n");
    fgets(buffer,20,stdin); //change the gets() function

    strcat(exists, buffer);
    status = system(exists);
    if (status == 256) {
        printf("%s", "File not found, exiting");
        return;
    }

    strcat(cp, buffer);
    strcat(cp, " ");
    strcat(cp, buffer);
    strcat(cp, "1");
    system(cp);

    strcat(zip, buffer);
    status = system(zip);
    if (status == 256) {
        printf("%s", "Gzip failed, exiting");
        return;
    }
    else {
        printf("%s has been zipped. \n", buffer);
    }

    strcat(mv, buffer);
    strcat(mv, "1");
    strcat(mv, " ");
    strcat(mv, buffer);
    system(mv);

    return;
}

int main() {
    FileCompress();
    return 0;
}

// $ python -c 'print "a"NN + "\xDD\xCC\xBB\xAA"' | ./bufferoverflow
// Find correct values of NN, AA, BB, CC, DD so that the python call from above
// overwrites the return register in stack memory and jumps to the secretFunction
// Hint: use objdump utility to find correct values AA, BB, CC, DD
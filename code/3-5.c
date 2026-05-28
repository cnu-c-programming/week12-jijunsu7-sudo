#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    char line[50];
    int num = 0;
    char err[50];
    int sum = 0;
    while(!feof(fp)){
        if(fscanf(fp, "%d\n", &num) != 1){
            fscanf(fp, "%s\n", err);
            fprintf(stderr, "invalid input %s\n", err);
            continue;
        }
        sum += num;
    }
    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]) {
    FILE* fp = fopen("student.txt", "r");
    int count = 0;
    Student students[64];

    while(1){
        if(feof(fp) != 0){
            break;
        }
        fscanf(fp, "%s %d\n", &students[count].name, &students[count].score);
        count++;
    }



    int max = 0;
    float avg = 0;
    for(int i = 0; i < count; i++){
        if(max < students[i].score)
            max = students[i].score;
        avg += students[i].score;
    }
    avg /= count;


    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);

    return 0;
}


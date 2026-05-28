#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    int count[26] = {0};
    while(1){
        if(feof(fp) != 0)
            break;
        int c = fgetc(fp);
        if(c >= 'a' || c < 'z')
            count[c - 97]++;
    }
    for(int i = 0; i < 26; i++){
        printf("%c: %d\n", i+97, count[i]);
    }


    fclose(fp);
}


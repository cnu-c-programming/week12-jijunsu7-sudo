#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    if (argc < 3)
        return 0;

    FILE* fp = fopen(argv[1], "r");
    const char* target_str = argv[2];
    char line[2048];
    char tmp[2048];
    while(fgets(line, sizeof(line), fp) != NULL){
        strcpy(tmp, line);
        char *token = strtok(tmp, " \t\r\n.,");
        if (token == NULL) continue;
        while(token != NULL){
            if(strcmp(token, target_str) == 0){
                printf("%s", line);
                break;
            }
            token = strtok(NULL, " \t\r\n.,");
        }
    }

    fclose(fp);
}


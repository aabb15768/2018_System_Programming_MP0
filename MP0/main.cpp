
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


int main(int argc, char* argv[]) {
    int count = 0;
    int flag = -1;
    int stringLen = strlen(argv[1]);
    if(stringLen == 0) {
        flag = 0;
    } else {
        flag = 1;
    }
    
    if(argc == 2) {
        char c = 0;
        while((c = getchar()) != EOF) {
            if(c == '\n') {
                printf("%d\n", count);
                count = 0;
                continue;
            }
            if(flag == 1) {
                for(int i = 0; i < stringLen; i++) {
                    if(argv[1][i] == c) {
                        count++;
                        break;
                    }
                }
            } else if(flag == 0) {
                continue;
            }
        }
    } else if (argc == 3) {
        ifstream inFile(argv[2]);
        if(!inFile.is_open()){
            fprintf(stderr, "error\n");
            return 0;
        }
        char c = 0;
        while(inFile.get(c)) {
            if(c == '\n') {
                printf("%d\n", count);
                count = 0;
                continue;
            }
            if(flag == 1) {
                for(int i = 0; i < stringLen; i++) {
                    if(argv[1][i] == c) {
                        count++;
                        break;
                    }
                }
            } else if(flag == 0) {
                continue;
            }
            
            
        }
    } else {
        printf("wrong usage! arguments should be one or two!");
    }
    return 0;
}

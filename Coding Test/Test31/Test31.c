#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181925
// numLog_len은 배열 numLog의 길이입니다.
char* solution(int numLog[], size_t numLog_len) {
    char* answer = (char*)malloc(numLog_len);
    for (int i = 0; i < numLog_len - 1; i++) {
        int diff = numLog[i + 1] - numLog[i];
        
        switch (diff) {
            case 1:
                answer[i] = 'w';
                break;
            case -1:
                answer[i] = 's';
                break;
            case 10:
                answer[i] = 'd';
                break;
            case -10:
                answer[i] = 'a';
                break;
        }
    }
    answer[numLog_len - 1] = '\0';
    
    return answer;
}
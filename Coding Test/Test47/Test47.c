#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181909
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
       // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    
    char** answer = (char**)malloc(sizeof(char*) * len);
    
    // 접미사 생성
    for (int i = 0; i < len; i++) {
        int suffix_len = len - i;
        answer[i] = (char*)malloc(suffix_len + 1);
        strcpy(answer[i], &my_string[i]);
    }
    
    // 버블 정렬로 사전순 정렬
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (strcmp(answer[j], answer[j+1]) > 0) {
                char* temp = answer[j];
                answer[j] = answer[j+1];
                answer[j+1] = temp;
            }
        }
    }
    
    return answer;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181878
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* myString, const char* pat) {
    int myString_len = strlen(myString);
    int pat_len = strlen(pat);

    // 소문자로 변환된 문자열 생성
    char* lower_myString = (char*)malloc(myString_len + 1);
    char* lower_pat = (char*)malloc(pat_len + 1);

    // myString을 소문자로 변환
    for (int i = 0; i < myString_len; i++) {
        lower_myString[i] = tolower(myString[i]);
    }
    lower_myString[myString_len] = '\0';

    // pat을 소문자로 변환
    for (int i = 0; i < pat_len; i++) {
        lower_pat[i] = tolower(pat[i]);
    }
    lower_pat[pat_len] = '\0';

    // strstr로 pat이 존재하는지 확인
    int result = (strstr(lower_myString, lower_pat) != NULL) ? 1 : 0;

    free(lower_myString);
    free(lower_pat);

    return result;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// https://school.programmers.co.kr/learn/courses/30/lessons/181900
// indices_len은 배열 indices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int indices[], size_t indices_len) {
    int len = strlen(my_string);

    bool* to_delete = (bool*)malloc(len * sizeof(bool));
    for (int i = 0; i < len; i++) {
        to_delete[i] = false;
    }

    for (int i = 0; i < indices_len; i++) {
        to_delete[indices[i]] = true;
    }

    int result_len = len - indices_len;
    char* answer = (char*)malloc((result_len + 1) * sizeof(char));

    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (!to_delete[i]) {
            answer[idx++] = my_string[i];
        }
    }
    answer[idx] = '\0';

    free(to_delete);
    return answer;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181886
// names_len은 배열 names의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* names[], size_t names_len) {
    // 5명씩 묶은 그룹의 개수
    int group_count = (names_len + 4) / 5;
    char** answer = (char**)malloc(group_count * sizeof(char*));

    // 각 그룹의 첫 번째 사람 (인덱스 0, 5, 10, ...)
    for (int i = 0; i < group_count; i++) {
        answer[i] = (char*)names[i * 5];
    }

    return answer;
}

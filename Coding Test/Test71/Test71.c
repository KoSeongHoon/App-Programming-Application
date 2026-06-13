#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181885
// todo_list_len은 배열 todo_list의 길이입니다.
// finished_len은 배열 finished의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* todo_list[], size_t todo_list_len, bool finished[], size_t finished_len) {
    // 미완료 일의 개수 세기
    int unfinished_count = 0;
    for (int i = 0; i < finished_len; i++) {
        if (!finished[i]) {
            unfinished_count++;
        }
    }

    char** answer = (char**)malloc(unfinished_count * sizeof(char*));

    // finished[i]가 false인 일들만 저장
    int idx = 0;
    for (int i = 0; i < finished_len; i++) {
        if (!finished[i]) {
            answer[idx++] = (char*)todo_list[i];
        }
    }

    return answer;
}

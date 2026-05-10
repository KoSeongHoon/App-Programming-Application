#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
 
//https://school.programmers.co.kr/learn/courses/30/lessons/181912
int* solution(const char* intStrs[], size_t intStrs_len, int k, int s, int l) {
    // 최악의 경우 intStrs_len 개의 원소가 모두 k보다 클 수 있으므로
    // 임시 배열을 intStrs_len 크기로 할당
    int* temp = (int*)malloc(intStrs_len * sizeof(int));
    int count = 0;  // 결과 배열에 저장된 원소 개수
    
    // 각 문자열을 순회
    for (size_t i = 0; i < intStrs_len; i++) {
        // 부분 문자열 추출 (길이 l + null 종료 문자)
        char substring[100];  // 충분한 크기 할당
        
        // s부터 l길이 만큼 부분 문자열 복사
        strncpy(substring, intStrs[i] + s, l);
        substring[l] = '\0';  // null 종료 문자 추가
        
        // 문자열을 정수로 변환
        int num = atoi(substring);
        
        // k보다 큰 경우 결과 배열에 추가
        if (num > k) {
            temp[count] = num;
            count++;
        }
    }
    
    // 최종 크기에 맞게 할당
    int* answer = (int*)malloc((count + 1) * sizeof(int));
    for (int i = 0; i < count; i++) {
        answer[i] = temp[i];
    }
    answer[count] = 0;  // 배열 끝 표시
    
    free(temp);
    return answer;
}
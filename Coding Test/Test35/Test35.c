#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181921
int* solution(int l, int r) {
    // 임시 배열: l부터 r까지 최대 (r-l+1)개의 수가 가능
    int* temp = (int*)malloc(sizeof(int) * (r - l + 2));
    int count = 0;
    
    // l부터 r까지 확인
    for (int num = l; num <= r; num++) {
        // 각 숫자가 0과 5로만 이루어졌는지 확인
        int temp_num = num;
        bool valid = true;
        
        while (temp_num > 0) {
            int digit = temp_num % 10;
            if (digit != 0 && digit != 5) {
                valid = false;
                break;
            }
            temp_num /= 10;
        }
        
        if (valid) {
            temp[count++] = num;
        }
    }
    
    // 결과 배열 할당 및 저장
    int* answer;
    if (count == 0) {
        // 조건을 만족하는 수가 없으면 -1 저장
        answer = (int*)malloc(sizeof(int));
        answer[0] = -1;
    } else {
        // 조건을 만족하는 수들을 answer에 복사
        answer = (int*)malloc(sizeof(int) * count);
        for (int i = 0; i < count; i++) {
            answer[i] = temp[i];
        }
    }
    
    free(temp);
    return answer;
}
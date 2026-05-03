#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//https://school.programmers.co.kr/learn/courses/30/lessons/181916
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int solution(int a, int b, int c, int d) {
    int dice[4] = {a, b, c, d};
    
    // 배열 정렬 (비교하기 쉽게)
    qsort(dice, 4, sizeof(int), compare);
    
    // 경우 1: 네 개 모두 같음 → 1111 × p
    if (dice[0] == dice[1] && dice[1] == dice[2] && dice[2] == dice[3]) {
        return 1111 * dice[0];
    }
    
    // 경우 2: 세 개가 같음 → (10p + q)²
    if ((dice[0] == dice[1] && dice[1] == dice[2]) || 
        (dice[1] == dice[2] && dice[2] == dice[3])) {
        int p, q;
        if (dice[0] == dice[1] && dice[1] == dice[2]) {
            p = dice[0];
            q = dice[3];
        } else {
            p = dice[1];
            q = dice[0];
        }
        int temp = 10 * p + q;
        return temp * temp;
    }
    
    // 경우 3: 두 개씩 같음 → (p + q) × |p - q|
    if ((dice[0] == dice[1]) && (dice[2] == dice[3])) {
        int p = dice[0];
        int q = dice[2];
        return (p + q) * (p > q ? p - q : q - p);
    }
    
    // 경우 4: 두 개만 같음 → q × r
    if ((dice[0] == dice[1]) || (dice[1] == dice[2]) || (dice[2] == dice[3])) {
        int diff1, diff2;
        
        if (dice[0] == dice[1]) {
            diff1 = dice[2];
            diff2 = dice[3];
        } else if (dice[1] == dice[2]) {
            diff1 = dice[0];
            diff2 = dice[3];
        } else {
            diff1 = dice[0];
            diff2 = dice[1];
        }
        return diff1 * diff2;
    }
    
    // 경우 5: 모두 다름 → 최솟값
    return dice[0];
}
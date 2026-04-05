#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181939
int solution(int a, int b) {
    char ab[20], ba[20];
    
    sprintf(ab, "%d%d", a, b);  // a⊕b
    sprintf(ba, "%d%d", b, a);  // b⊕a

    
    return strcmp(ab, ba) >= 0 ? atoi(ab) : atoi(ba);
}
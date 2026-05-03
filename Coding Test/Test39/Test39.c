#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181917
bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = (x1 || x2) && (x3 || x4);
    return answer;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//https://school.programmers.co.kr/learn/courses/30/lessons/181908
int solution(const char* my_string, const char* is_suffix) {
    int my_len = strlen(my_string);
    int suffix_len = strlen(is_suffix);
    
    // is_suffix가 my_string보다 길면 접미사가 될 수 없음
    if (suffix_len > my_len) {
        return 0;
    }
    
    // my_string의 끝에서 suffix_len만큼 비교
    // my_string의 (my_len - suffix_len) 인덱스부터 끝까지와 is_suffix 비교
    if (strcmp(&my_string[my_len - suffix_len], is_suffix) == 0) {
        return 1;
    }
    
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
//https://school.programmers.co.kr/learn/courses/30/lessons/181929
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int mult_num=1;
    int sum_mult_num=0;
    for (int i = 0; i < num_list_len; i++)
    {
       mult_num=mult_num*num_list[i];
       sum_mult_num=sum_mult_num+num_list[i];
    }
    
    if (mult_num < sum_mult_num * sum_mult_num) {
        answer = 1;
    }else {
        answer = 0;
    }
    
    return answer;
}
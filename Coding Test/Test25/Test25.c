#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// included_len은 배열 included의 길이입니다.
//https://school.programmers.co.kr/learn/courses/30/lessons/181931
int solution(int a, int d, bool included[], size_t included_len) {
    int answer = 0;
    for (int i = 0; i < included_len; i++)
    {
        if (included[i]==true)
        {
            answer+=a+i*d;
        }
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    bool included[5]={true, false, false, true, true};
    size_t included_len=5;
    printf("%d",solution(3,7,included,included_len)); // 54
    return 0;
}

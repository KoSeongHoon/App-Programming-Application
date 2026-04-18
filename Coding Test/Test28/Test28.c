#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
// https://school.programmers.co.kr/learn/courses/30/lessons/181928
int solution(int num_list[], size_t num_list_len)
{
    int answer = 0;
    int even_num = 0;
    int odd_num = 0;
    int even_join_num = 0;
    int odd_join_num = 0;
    for (int i = 0; i < num_list_len; i++)
    {
        if (num_list[i] % 2 == 0)
        {
            even_num++;
        }
        else
        {
            odd_num++;
        }
    }

    for (int j = 0; j < num_list_len; j++)
    {
        if (num_list[j] % 2 == 0)
        {
            even_join_num += pow(10, even_num - 1) * num_list[j];
            even_num--;
        }
        else
        {
            odd_join_num += pow(10, odd_num - 1) * num_list[j];
            odd_num--;
        }
        answer = even_join_num + odd_join_num;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int num_list[] = {3, 4, 5, 2, 1};
    printf("%d\n", solution(num_list, 5));
    return 0;
}

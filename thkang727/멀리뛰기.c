#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long answer = 0;
    long long ans_list[2001];
    ans_list[0]=1;
    ans_list[1]=2;
    for(int i=2;i<n;i++){
        ans_list[i] = (ans_list[i-2] + ans_list[i-1]) % 1234567;  
    }
    answer = ans_list[n-1];
    return answer;
}

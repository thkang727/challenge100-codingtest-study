#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 풀이실패...
int main()
{
    int n;
    scanf("%d", &n);
    char arr[n][50];


    //문자열 입력
    for(int i = 0 ; i< n ; i++){

        gets(arr[i]);

    }

    char cnt_arr[n][50];
    int n_arr[n];
    for(int i = 0 ; i< n ; i++){
        n_arr[i]= 0;
    }
    strcpy(cnt_arr[0], arr[0]);
    n_arr[0] = 1;
    int n_cnt=1;

    
    //문자열 별로 수 세기.
    for(int i = 1 ; i< n ; i++){
        for(int j = 0 ; j< n_cnt ; j++){
            int res = strcmp(arr[i], cnt_arr[j]);
            if (res == 0)
                n_arr[j]+=1;
            else{
                if(j == n_cnt-1 && n_cnt<n){
                    strcpy(cnt_arr[j+1],arr[i]);
                    n_arr[j+1]=1;
                    n_cnt+=1;
                    break;
                }
            }
        }
    }

    int ans = 0, best_cnt=0;
    //문자열 수에따라 best case.
    for(int i=0;i<n;i++){

        if(n_arr[i] > best_cnt ){
            best_cnt = n_arr[i];
            ans = i;
        }
        //수가 같으면 문자열 비교로.
        else if(n_arr[i] == best_cnt ){
            int res = strcmp(cnt_arr[ans], cnt_arr[i]);
            if(res >0){
                best_cnt = n_arr[i];
                ans = i;
            }
        }
    }
    printf(cnt_arr[ans]);




    return 0;
}

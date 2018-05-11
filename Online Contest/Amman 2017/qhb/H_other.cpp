#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long

using namespace std;
const int MX = 1e6 + 5;
const int mod = 1e9 + 7;
const int INF = 2e9 + 5;

char s[MX];

int main(){
    freopen("input", "r", stdin);
    freopen("output.b", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        int n, ss;
        scanf("%d%d", &n, &ss);
        for(int i = 1; i <= n; i++){
            s[i] = '9';
        }
        int sum = n * 9;
        int mid = (1+n)/2;
        if(sum < ss || (n % 2 == 0 && (ss & 1)) || (n & 1 && n != 1 && ss == 1)){
            printf("-1\n");
            continue;
        }
        if(n & 1){
            while(sum > ss && s[mid] > '0'){
                s[mid]--;
                sum--;
                if(s[mid] == '1' && (ss & 1)) break;
            }
            if(sum == ss){
                for(int i = 1; i <= n; i++){
                    printf("%c", s[i]);
                }
                printf("\n");
                continue;
            }
            else mid--;
            while(sum > ss){
                s[mid]--;
                s[n - mid + 1]--;
                sum -= 2;
                if(s[mid] == '0')   mid--;
            }
        }
        else{
            while(sum > ss){
                s[mid]--;
                s[n - mid + 1]--;
                sum -= 2;
                if(s[mid] == '0')   mid--;
            }
        }
        for(int i = 1; i <= n; i++){
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}

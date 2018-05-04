#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char ans[105], a[105], b[105];
int len;
void deal(char *a, char *b) {
//     printf("%s   %s   %d\n", a, b, len);
     for(int i = len - 1; i >= 0; --i) {
             if(a[i] >= b[i]) ans[i] = a[i] - b[i] + '0';
             else {
                 a[i] += 10;
                 if(a[i - 1] == '0')  a[i - 1] = '9';
                 else   a[i - 1]--;
                 ans[i] = a[i] - b[i] + '0';
             }
     }  
}
int main() {
    
    
    while(scanf("%s", a) != EOF) {
          
          len = strlen(a);
          bool flag = 1;
          for(int i = 0; i < len; ++i){
                  b[len - i - 1] = a[i];  
                  if(a[i] != a[len - 1 - i])   flag = 0;     
          }
          if(flag) {
                      printf("YES\n");
                      continue;
                      }
          flag = 1;
          for(int i = 0; i < len; ++i)
                  if(a[i] > b[i]) break;
                  else if(a[i] < b[i])  {
                       flag = 0;
                       break;     
                  }          
          if(flag)           deal(a, b);
          else               deal(b, a);
          
 //        printf("%s\n", ans);
          flag = 1;
          int idx = 0;
          while(ans[idx] == '0') ++idx;
          if(len - idx == 1 && ans[len - 1] == '9') {
                 printf("YES\n");
                 continue;       
          }
          if(ans[len - 1] == '0')      flag = 0;
          if(ans[len - 1] + ans[idx] - '0' != '9')  flag = 0;
          for(int i = idx + 1; i < len - 1; ++i)  if(ans[i] != '9')   flag = 0;
          if(flag)  printf("YES\n");
          else      printf("NO\n");
          
          memset(a, 0, sizeof(b));
          memset(b, 0, sizeof(a));
    }
}


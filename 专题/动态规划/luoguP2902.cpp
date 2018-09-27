//这套题没有special judge真的是不可能调出来的
//不过，对于题目来说，如果一定有解的话，则说明每一种颜色最多只含有n/2个，因此直接排序就可以做了
//不过要用结构体存储原来的编号
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
struct Pearl{
    int col;
    int cnt;
    bool operator<(const Pearl& o)const{
        return cnt>o.cnt;
    }
}num[maxn];
int n,c,tmp;
int ans[maxn];
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=c;i++){
        scanf("%d",&num[i].cnt);
        num[i].col=i;
    }
    sort(num+1,num+1+c);
    n/=2;
    int l=1;
    for(int i=1;i<=n;i++){
        ans[i]=num[l].col;
        num[l].cnt--;
        if(num[l].cnt==0) l++;
    }
    for(int i=1;i<=n;i++){
        printf("%d %d\n",ans[i],num[l].col);
        num[l].cnt--;
        if(num[l].cnt==0) l++;
    }
    return 0;
}
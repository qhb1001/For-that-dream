#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=105;
const int INF=0x3f3f3f3f;
int step[maxn][maxn];
int s,n,m;
int ans;
void dfs(int a,int b,int c,int depth){
    int add,x,y,z;
    //a->b
    add=min(a,n-b);
    x=a-add;y=b+add;z=c;
    if(!(y==0&&z==0)&&(!step[y][z]||step[y][z]>depth+1)){
        step[y][z]=depth+1;
//        cout<<x<<" "<<y<<" "<<z<<" "<<depth+1<<endl;
        if((x==y&&x==s/2)||(x==z&&x==s/2)||(z==y&&z==s/2)){
            ans=min(ans,depth+1);
            return ;
        }
        dfs(x, y, z,depth+1);
    }

    //a->c
    add=min(a,m-c);
    x=a-add;y=b;z=c+add;
    if(!(y==0&&z==0)&&(!step[y][z]||step[y][z]>depth+1)){
        step[y][z]=depth+1;
//        cout<<x<<" "<<y<<" "<<z<<" "<<depth+1<<endl;
        if((x==y&&x==s/2)||(x==z&&x==s/2)||(z==y&&z==s/2)){
            ans=min(ans,depth+1);
            return ;
        }
        dfs(x, y, z,depth+1);
    }

    //b->a
    add=min(b,s-a);
    x=a+add;y=b-add;z=c;
    if(!(y==0&&z==0)&&(!step[y][z]||step[y][z]>depth+1)){
        step[y][z]=depth+1;
//        cout<<x<<" "<<y<<" "<<z<<" "<<depth+1<<endl;
        if((x==y&&x==s/2)||(x==z&&x==s/2)||(z==y&&z==s/2)){
            ans=min(ans,depth+1);
            return ;
        }
        dfs(x, y, z,depth+1);
    }

    //b->c
    add=min(b,m-c);
    x=a;y=b-add;z=c+add;
    if(!(y==0&&z==0)&&(!step[y][z]||step[y][z]>depth+1)){
        step[y][z]=depth+1;
//        cout<<x<<" "<<y<<" "<<z<<" "<<depth+1<<endl;
        if((x==y&&x==s/2)||(x==z&&x==s/2)||(z==y&&z==s/2)){
            ans=min(ans,depth+1);
            return ;
        }
        dfs(x, y, z,depth+1);
    }

    //c->a
    add=min(c,s-a);
    x=a+add;y=b;z=c-add;
    if(!(y==0&&z==0)&&(!step[y][z]||step[y][z]>depth+1)){
        step[y][z]=depth+1;
//        cout<<x<<" "<<y<<" "<<z<<" "<<depth+1<<endl;
        if((x==y&&x==s/2)||(x==z&&x==s/2)||(z==y&&z==s/2)){
            ans=min(ans,depth+1);
            return ;
        }
        dfs(x, y, z,depth+1);
    }

    //c->b
    add=min(c,n-b);
    x=a;y=b+add;z=c-add;
    if(!(y==0&&z==0)&&(!step[y][z]||step[y][z]>depth+1)){
        step[y][z]=depth+1;
//        cout<<x<<" "<<y<<" "<<z<<" "<<depth+1<<endl;
        if((x==y&&x==s/2)||(x==z&&x==s/2)||(z==y&&z==s/2)){
            ans=min(ans,depth+1);
            return ;
        }
        dfs(x, y, z,depth+1);
    }
}

int main(){
    while(scanf("%d%d%d",&s,&n,&m)!=EOF){
        if(!s) break;
        ans=INF;
        memset(step, 0, sizeof(step));
        if(s%2){
            cout<<"NO"<<endl;
            continue;
        }
        dfs(s, 0, 0, 0);
        if(ans==INF){
            cout<<"NO"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}

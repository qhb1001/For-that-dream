#include<cstdio>
#include<iostream>
#include<bitset>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#define mp make_pair
#define pb push_back
#define ll unsigned long long
#define lc no[x].ch[0]
#define rc no[x].ch[1]
#define pa no[x].fa
#define db double
#define ls x<<1
#define rs x<<1|1
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn=1e3+10;
const int maxs=3e5+5;
const int inf=1e9;
const ll mod=1e9+7;
char a[maxn][maxn];
ll vs[maxn][maxn];
ll c[maxn][maxn],r[maxn][maxn];
bool cc[maxn][maxn],rr[maxn][maxn];
int main()
{
    int n,m;
    cin>>n>>m;
 //   cout<<(1ll<<51)<<endl;
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]>='a'&&a[i][j]<='z')vs[i+1][j+1]=a[i][j]-'a';
            else vs[i+1][j+1]=a[i][j]-'A'+26;
        }
    }
/*  for(int i=1;i<=n;i++)
       {for(int j=1;j<=m;j++)
    {
        cout<<vs[i][j]<<"  ";
    }
    cout<<endl;
       }*/
    //  ll vp=1<<31;
      //printf("%lld\n",vp);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int p=1;p<=52&&i+p-1<=n;p++)
                for(int q=1;p*q<=52&&j+q-1<=m;q++)
                    c[i+p-1][j+q-1]=0;
          //  memset(c,0,sizeof(c));
            ll tmp;
            int las=53;
            for(int p=1;p<=52&&i+p-1<=n;p++)
            {
                tmp=0;
                for(int q=1;p*q<=52&&q<las&&j+q-1<=m;q++)
                {
                 //   cout<<i<<"  "<<j<<"  "<<p<<" "<<q<<endl;
                    if((tmp&(1ll<<(vs[i+p-1][j+q-1])))!=0)
                    {
                        las=q;
                     //  cout<<i<<"  "<<j<<"  "<<p<<" "<<q<<"  "<<222<<endl;
                        break;
                    }
                  //  cout<<vs[i+p-1][j+q-1]<<endl;
                    tmp|=(1ll<<vs[i+p-1][j+q-1]);
                    //cout<<tmp<<endl;
                  //  if(i+p-1==2)cout<<vs[i+p-1][j+q-1]<<"  "<<tmp<<endl;
                    if(p!=1)
                    {
                       // cout<<c[1][4]<<endl;
                        if((tmp&c[i+p-2][j+q-1])!=0)
                        {
                            las=q;
                         //   cout<<i<<"  "<<j<<"  "<<p<<" "<<q<<endl;
                       //  cout<<c[i+p-2][j+q-1]<<endl;
                            break;
                        }
                        c[i+p-1][j+q-1]=(tmp|c[i+p-2][j+q-1]);
                    }
                    else
                    {
                        c[i+p-1][j+q-1]=tmp;
                    }
                  //  cout<<c[i+p-1][j+q-1]<<endl;
                    //cout<<tmp<<endl;
                    cnt++;
                }
            }

        }
    }
    cout<<cnt<<"\n";

}
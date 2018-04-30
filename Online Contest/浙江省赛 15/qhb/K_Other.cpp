#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int ll;


int a[1000005];

int main()
{
	freopen("input", "r", stdin);
    int T;
    scanf("%d",&T);
    int N,M;
    while(T--){
        scanf("%d%d",&N,&M);
        a[N]=3*M+1;
        char c;
        int k;
        int index=-1;
        for(int i=0;i<N;i++){
            cin>>c;
            if(c=='C'){
                cin>>k;
                a[i]=k;
            }
            if(c=='B'){
                cin>>k;
                a[i]=M+k;
            }
            if(c=='D')
            {
                cin>>k;
                a[i]=M+M+k;
            }
            if(c=='W'){
                index=i;
            }
        }

        if(N==1){
            cout<<3*M<<endl;
        }
        else{

            if(index==-1){
                if(a[0]>a[1])
                    cout<<1<<endl;
                else
                    cout<<3*M-N+1<<endl;
            }
            else{
                if(index==0){
                    cout<<a[1]-1<<endl;
                }
                else{
                    if(a[0]>a[1]&&index!=1)
                        cout<<1<<endl;
                    else{
                        int sum=a[index+1]-a[index-1]-1;
                        if(index==1)
                            sum++;
                        cout<<sum<<endl;
                    }
                }
            }
        }



    }

    return 0;
}

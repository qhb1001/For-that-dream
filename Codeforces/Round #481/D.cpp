#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int b[maxn];
int c[maxn];
int n;
void Init(){
    for(int i=1;i<=n;i++)
        c[i]=b[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    if(n<=2) cout<<"0"<<endl;
    else{
        int add;bool flag;int ans=n+1;
        int cnt;

        //0 0
        Init();
        add=c[2]-c[1];
        cnt=0;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);

        //1 0
        Init();
        c[1]++;
        add=c[2]-c[1];
        cnt=1;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);

        //0 1
        Init();
        c[2]++;
        add=c[2]-c[1];
        cnt=1;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);

        //-1 0
        Init();
        c[1]--;
        add=c[2]-c[1];
        cnt=1;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);

        //0 -1
        Init();
        c[2]--;
        add=c[2]-c[1];
        cnt=1;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);

        //1 1
        Init();
        c[1]++;c[2]++;
        add=c[2]-c[1];
        cnt=2;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);

        //-1 -1
        Init();
        c[1]--;c[2]--;
        add=c[2]-c[1];
        cnt=2;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);

        //1 -1
        Init();
        c[1]++;c[2]--;
        add=c[2]-c[1];
        cnt=2;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);

        //-1 1
        Init();
        c[1]--;c[2]++;
        add=c[2]-c[1];
        cnt=2;flag=false;
        for(int i=3;i<=n;i++){
            int tmp=c[i]-c[i-1];
            if(tmp==add) continue;
            if(tmp<add){
                if(tmp+1<add) {
                    flag=true;
                    break;
                }
                c[i]++;
                cnt++;
            }
            else{
                if(tmp-1>add){
                    flag=true;
                    break;
                }
                c[i]--;
                cnt++;
            }
        }
        if(!flag) ans=min(cnt,ans);
        if(ans!=(n+1)) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string s,ss;
int n,ans;
int num[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++){
        num[s[i]-'0']++;
    }
    if(n==1) cout<<"-1"<<endl;
    else if(n==2){
        if(((s[0]-'0')*10+(s[1]-'0'))%25==0) cout<<0<<endl;
        else if(((s[1]-'0')*10+(s[0]-'0'))%25==0) cout<<1<<endl;
        else cout<<-1<<endl;
    }else if(n==3){
        if(num[0]>=2){
            cout<<0<<endl;
        }
        else if(num[0]&&num[2]&&num[5]){
            if(s=="205"||s=="520") cout<<1<<endl;
            else if(s=="250") cout<<"0"<<endl;
            else cout<<"2"<<endl;
        }
        else if(num[0]&&num[7]&&num[5]){
            if(s=="570"||s=="705") cout<<1<<endl;
            else if(s=="750") cout<<"0"<<endl;
            else cout<<"2"<<endl;
        }else{
            if(num[5]){
                //x50 x05 50x 5x0
                //0   1   2   1
                if(num[0]){
                    if(s[2]=='0'){
                        if(s[1]=='5')cout<<0<<endl;
                        else cout<<1<<endl;
                    }else if(s[1]=='0'){
                        if(s[2]=='5') cout<<1<<endl;
                        else cout<<2<<endl;
                    }
                }
                //257 275 572 527 725 752
                //1   0   2    2  0   1
                else if(num[2]&&num[7]){
                    if(s[2]=='5') cout<<0<<endl;
                    else if(s[1]=='5') cout<<1<<endl;
                    else cout<<2<<endl;
                }else if(num[2]||num[7]){
                    //x25 x52 25x 2x5 52x 5x2
                    //x75 x57 75x 7x5 57x 5x7
                    //0   1   2   1   3   2
                    if(s[2]=='5'){
                        if(s[1]=='2'||s[1]=='7') cout<<0<<endl;
                        else cout<<1<<endl;
                    }else if(s[1]=='5'){
                        if(s[2]=='2'||s[2]=='7') cout<<1<<endl;
                        else cout<<2<<endl;
                    }else{
                        if(s[1]=='2'||s[1]=='7') cout<<3<<endl;
                        else cout<<2<<endl;
                    }
                }
                else cout<<-1<<endl;
            }
            else cout<<-1<<endl;
        }
    }else{
        ans=-1;
        int tmp=0,cnt=0;
        //00
        if(num[0]>=2){
            for(int i=n-1;i>=0;i--){
                if(s[i]=='0'){
                    tmp+=n-1-i-cnt;cnt++;
                }
                if(cnt==2) break;
            }
//            cout<<"00 "<<tmp<<endl;
            ans=tmp;
        }
        tmp=0;
        int idx=-1;
        ss=s;
        //50
        if(num[5]&&num[0]){
            for(int i=n-1;i>=0;i--)
                if(ss[i]=='0'){
                    idx=i;break;
                }

            for(int i=idx;i<n-1;i++){
                swap(ss[i], ss[i+1]);
                tmp++;
            }
            for(int i=n-1;i>=0;i--)
                if(ss[i]=='5'){
                    idx=i;break;
                }
            tmp+=n-2-idx;
            idx=0;
            while(ss[idx]=='0')idx++,tmp++;
//            cout<<"50 "<<tmp<<endl;
            if(ans==-1) ans=tmp;
            else ans=min(ans,tmp);
        }

        //75
        tmp=0;ss=s;
        if(num[7]&&num[5]){
            for(int i=n-1;i>=0;i--)
                if(ss[i]=='5'){
                    idx=i;break;
                }

            for(int i=idx;i<n-1;i++){
                swap(ss[i], ss[i+1]);
                tmp++;
            }
//            cout<<ss<<" "<<tmp<<endl;
            for(int i=n-1;i>=0;i--)
                if(ss[i]=='7'){
                    idx=i;break;
                }
            tmp+=n-2-idx;
            idx=0;
            while(ss[idx]=='0')idx++,tmp++;
//            cout<<"75 "<<tmp<<endl;
            if(ans==-1) ans=tmp;
            else ans=min(ans,tmp);
        }
        tmp=0;ss=s;
        //25
        if(num[2]&&num[5]){
            for(int i=n-1;i>=0;i--)
                if(ss[i]=='5'){
                    idx=i;break;
                }

            for(int i=idx;i<n-1;i++){
                swap(ss[i], ss[i+1]);
                tmp++;
            }
            for(int i=n-1;i>=0;i--)
                if(ss[i]=='2'){
                    idx=i;break;
                }
            tmp+=n-2-idx;
            idx=0;
            while(ss[idx]=='0')idx++,tmp++;
//            cout<<"25 "<<tmp<<endl;
            if(ans==-1) ans=tmp;
            else ans=min(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}

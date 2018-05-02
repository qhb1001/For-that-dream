//两个函数 lower(x)   upper(x)，分表表示<= x   >= x的第一个元素的大小，用他们来表示将来电梯或者楼梯的位置
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int l[maxn],e[maxn];
int n,m,cl,ce,v,q;
int xx1,yy1,xx2,yy2;
ll tl1,tl2,tl3,tl4;
ll el1,el2,el3,el4;
ll ans[8];
ll tmp;
int idx;
int Left_l(int x){
    int ll=0,rr=cl-1;
    int ans=0;
    while(ll<=rr){
        int mid=(ll+rr)>>1;
        if(l[mid]==x) return l[mid];
        if(l[mid]<x){
            ans=l[mid];
            ll=mid+1;
        }
        else rr=mid-1;
    }
    return ans;
}
int Left_e(int x){
    int ll=0,rr=ce-1;
    int ans=0;
    while(ll<=rr){
        int mid=(ll+rr)>>1;
        if(e[mid]==x) return e[mid];
        if(e[mid]<x){
            ans=e[mid];
            ll=mid+1;
        }
        else rr=mid-1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>cl>>ce>>v;
    for(int i=0;i<cl;i++){
        cin>>l[i];
    }
    for(int i=0;i<ce;i++){
        cin>>e[i];
    }
    sort(l,l+cl);
    sort(e,e+ce);

    cin>>q;
    while(q--){
        idx=0;
        cin>>yy1>>xx1>>yy2>>xx2;
        if(yy2==yy1){
            cout<<abs(xx2-xx1)<<endl;
            continue;
        }

        tmp=abs(yy2-yy1);
        tl1=l[lower_bound(l, l+cl, xx1)-l];
        if(tl1) ans[idx++]=abs(xx1-tl1)+tmp+abs(xx2-tl1);
        tl2=Left_l(xx1);
        if(tl2) ans[idx++]=abs(xx1-tl2)+tmp+abs(xx2-tl2);
        tl3=l[lower_bound(l, l+cl, xx2)-l];
        if(tl3) ans[idx++]=abs(xx1-tl3)+tmp+abs(xx2-tl3);
        tl4=Left_l(xx2);
        if(tl4) ans[3]=abs(xx1-tl4)+tmp+abs(xx2-tl4);
//        cout<<tl1<<" "<<tl2<<" "<<tl3<<" "<<tl4<<endl;

        if(tmp%v) tmp=tmp/v+1;
        else tmp=tmp/v;
        el1=e[lower_bound(e, e+ce, xx1)-e];
        if(el1) ans[idx++]=abs(xx1-el1)+tmp+abs(xx2-el1);
        el2=Left_e(xx1);
        if(el2) ans[idx++]=abs(xx1-el2)+tmp+abs(xx2-el2);
        el3=e[lower_bound(e, e+ce, xx2)-e];
        if(el3) ans[idx++]=abs(xx1-el3)+tmp+abs(xx2-el3);
        el4=Left_e(xx2);
        if(el4) ans[idx++]=abs(xx1-el4)+tmp+abs(xx2-el4);
//        cout<<el1<<" "<<el2<<" "<<el3<<" "<<el4<<endl;

        sort(ans,ans+idx);
//        for(int i=0;i<idx;i++){
//            cout<<ans[i]<<endl;
//        }
        cout<<ans[0]<<endl;
    }
    return 0;
}

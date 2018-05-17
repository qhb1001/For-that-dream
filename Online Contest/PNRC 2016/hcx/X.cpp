#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct ty{
    int x,y;
}Squ[5];
int e[5];
bool samethree(int x,int y,int z){
    if(x==y&&x==z) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<3;i++){
        cin>>Squ[i].x>>Squ[i].y;
        if(Squ[i].x<Squ[i].y) swap(Squ[i].x,Squ[i].y);
    }
    bool flag=false;
    if(samethree(Squ[0].x, Squ[1].x, Squ[2].x)&&(Squ[0].y+Squ[1].y+Squ[2].y==Squ[0].x))
        flag=true;

    int idxMax=0;
    int len=Squ[0].x-Squ[0].y;

    if(Squ[1].x>Squ[0].x&&Squ[1].x>Squ[2].x){
        idxMax=1;
        e[1]=Squ[0].x;e[2]=Squ[0].y;
        e[3]=Squ[2].x;e[4]=Squ[2].y;
    }
    else if(Squ[2].x>Squ[0].x&&Squ[2].x>Squ[1].x){
        idxMax=2;
        e[1]=Squ[0].x;e[2]=Squ[0].y;
        e[3]=Squ[1].x;e[4]=Squ[1].y;
    }
    else{
        e[1]=Squ[1].x;e[2]=Squ[1].y;
        e[3]=Squ[2].x;e[4]=Squ[2].y;
    }

    if(e[1]==e[3]&&e[1]+Squ[idxMax].y==Squ[idxMax].x&&e[2]+e[4]==Squ[idxMax].x)flag=true;
    if(e[2]==e[4]&&e[2]+Squ[idxMax].y==Squ[idxMax].x&&e[1]+e[3]==Squ[idxMax].x)flag=true;
    if(e[1]==e[4]&&e[1]+Squ[idxMax].y==Squ[idxMax].x&&e[2]+e[3]==Squ[idxMax].x)flag=true;
    if(e[2]==e[3]&&e[2]+Squ[idxMax].y==Squ[idxMax].x&&e[1]+e[4]==Squ[idxMax].x)flag=true;
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

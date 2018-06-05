#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
double eps=1e-18;
long double x,y;
long double a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>x>>y;
    b=x*1.0*log(y);
    a=y*1.0*log(x);
    if(a-b>eps) cout<<">"<<endl;
    else if(b-a>eps) cout<<"<"<<endl;
    else cout<<"="<<endl;

    return 0;
}

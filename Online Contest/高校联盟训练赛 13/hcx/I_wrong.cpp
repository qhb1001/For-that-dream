//需要用拉格朗日方程
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long double L;
    while(cin>>L){
        long double tmp=L*L/4.0;
        printf("%.2Lf %.2Lf\n",tmp/3.14159265,tmp/9.0*sqrt(3.0));
    }
    return 0;
}

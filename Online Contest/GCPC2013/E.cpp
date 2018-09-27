#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define pi 3.14159265359
const double eps = 1e-6;
double f(double a, double b, double x){
	double ans = a*exp(-x*x) + b*sqrt(x);
	return ans * ans;
}
double jifen(double a, double b, double h){
	long long cnt = 2;
	double V = h/2 * (f(a,b,0) + f(a,b,h));
	double Vol = V;
	V = V/2 + h*1.0/2*f(a,b,h*1/2);
	while(fabs(V-Vol) > eps){
		cnt *= 2;
		double sum = 0;
		for(int i=1; i<cnt; i+=2){
			sum += f(a,b,h*i/cnt);
		}
		Vol = V;
		V = V/2 + h/cnt*sum;
	}
	return V;
}
int main(){
	double V; int N;
	scanf("%lf%d",&V,&N);
	V /= pi;
	double a, b, h;
	scanf("%lf%lf%lf",&a,&b,&h);
	double imin = fabs(jifen(a,b,h) - V);
	int res = 0;
	for(int i=1; i<N; i++){
		scanf("%lf%lf%lf",&a,&b,&h);
		double cha = fabs(jifen(a,b,h) - V);
		if(cha < imin){
			imin = cha;
			res = i;
		} 
	}
	printf("%d\n",res);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void in(int *a) {
	for (int i = 1; i <= 6; ++i)	cin >> a[i];
}
int main() {
	int a[10], b[10];
	in(a); in(b);

	double win = 0, fair = 0;
	for (int i = 1; i <= 6; ++i)
		for (int j = 1; j <= 6; ++j)
			if (a[i] == b[j])	++fair;
			else if (a[i] > b[j])	++win;
	
	if (fair == 36)	printf("0.00000\n");
	else	printf("%.5f\n", win / (36 - fair));
}

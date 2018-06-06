/**
 *
 * Written by Air
 * 寒域
 * 数论模板
 *
 * 需要include:
 * vector
 * cstdlib
 * Algorithm
 * cstring
 * cmath
 * **/
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
class NumberTheory {
public:
    //  预打标后的数的最小因子
    std::vector<unsigned int> MinFactor;
    //  预打表中搜索到的素数集
    std::vector<unsigned int> Prime;
    //  预打表欧拉函数
    std::vector<unsigned int> Phi;
    //  预打表最大数
    unsigned int MaxNumber;
    //  用于递归传递参数    没有实质作用
    std::vector<long long int> temp;

    //  不打表构造函数
    NumberTheory() {
        MaxNumber = 0;
    }

    //  预打表到MaxNumber构造函数
    explicit NumberTheory(unsigned int MaxNumber) {
        this->MaxNumber = MaxNumber;
        MaxNumber = std::max(MaxNumber + 1, (unsigned int) 2);
        Phi.resize(MaxNumber);
        MinFactor.resize(MaxNumber);
        MinFactor[1] = 1;
        Phi[1] = 1;
        for (unsigned int i = 2; i < MaxNumber; i++) {
            if (Phi[i] == 0) {
                Prime.push_back(i);
                Phi[i] = i - 1;
                MinFactor[i] = i;
            }
            for (unsigned int j = 0; j < Prime.size() && Prime[j] * i < MaxNumber; j++) {
                if (i % Prime[j] == 0) {
                    MinFactor[i * Prime[j]] = Prime[j];
                    Phi[i * Prime[j]] = Phi[i] * Prime[j];
                    break;
                }
                MinFactor[i * Prime[j]] = Prime[j];
                Phi[i * Prime[j]] = Phi[i] * (Prime[j] - 1);
            }
        }
    }

    long long int abs(int x) {
        return x > 0 ? x : -x;
    }

    //  快速幂
    long long fastpower(long long a, long long n) {
        long long res = 1;
        while (n > 0) {
            if (n & 1)res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }

    //  判断是否是素数
    bool IsPrime(long long int n) {
        if (n <= MaxNumber)
            //  在表中O(1)查表
            return MinFactor[n] == n;
        //  不在表中用Miller_Rabin
        return Miller_Rabin(n);
    }

    //  最大公约数
    long long int gcd(long long int a, long long int b) {
        return b ? gcd(b, a % b) : a;
    }

    //  多个数最大公约数
    long long int gcd(std::vector<int> v) {
        if (v.size() < 2)
            return -1;
        long long int res = v[0];
        for (int i = 1; i < v.size(); i++) {
            res = gcd(res, v[i]);
        }
        return res;
    }

    //  最小公倍数
    long long int lcm(long long int a, long long int b) {
        return a * b / gcd(a, b);
    }

    //  带模快速乘法
    long long int modular_multi(long long int x, long long int y, long long int mo) {
        long long int t;
        x %= mo;
        for (t = 0; y; x = (x << 1) % mo, y >>= 1)
            if (y & 1)
                t = (t + x) % mo;
        return t;
    }

    /*long long int modular_exp(char *N, long long int t, long long int mo) {
     //unsure!!!
     return modular_exp(t,PhiMa(N,mo),mo);
     }*/

    //  带模快速幂
    long long int modular_exp(long long int num, long long int t, long long int mo) {
        long long int ret = 1, temp = num % mo;
        for (; t; t >>= 1, temp = modular_multi(temp, temp, mo))
            if (t & 1)
                ret = modular_multi(ret, temp, mo);
        return ret;
    }

    //  费马小定理整理指数
    long long int PhiMa(char *N, int mod) {
        long long ans = 0;
        for (int i = 0; N[i] != '\0'; i++)
            ans = (ans * 10 + N[i] - '0') % mod;
        return ans;
    }

    //  Miller_Rabin判断素数
    bool Miller_Rabin(long long int n) {
        return Miller_Rabin(n, 40);
    }

    //  Miller_Rabin判断素数
    bool Miller_Rabin(long long int n, long long int S) {
        if (n == 2)return true;
        if (n < 2 || !(n & 1))return false;
        int t = 0;
        long long int a, x, y, u = n - 1;
        while ((u & 1) == 0) t++, u >>= 1;
        for (int i = 0; i < S; i++) {
            a = rand() % (n - 1) + 1;
            x = modular_exp(a, u, n);
            for (int j = 0; j < t; j++) {
                y = modular_multi(x, x, n);
                if (y == 1 && x != 1 && x != n - 1)
                    return false;
                x = y;
            }
            if (x != 1)
                return false;
        }
        return true;
    }

    //  扩展欧几里得
    long long int extern_gcd(long long int a, long long int b, long long int &x, long long int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        long long int ans;
        long long int x1, y1;
        ans = extern_gcd(b, a % b, x1, y1);
        if (a * b < 0) {
            x = -y1;
            y = a / b * y1 - x1;
        } else {
            x = y1;
            y = x1 - a / b * y1;
        }
        return ans;

    }

    //  模逆元
    long long int Inverse(long long int a, long long int m) {
        long long int x, y;
        long long int gcd = extern_gcd(a, m, x, y);
        if (1 % gcd != 0) return -1;
        x *= 1 / gcd;
        m = abs(m);
        long long int ans = x % m;
        if (ans <= 0)ans += m;
        return ans;
    }

    //  Pollard_Rho分解因数
    long long Pollard_Rho(long long n, int c) {
        long long i = 1, k = 2, x = rand() % (n - 1) + 1, y = x;
        while (true) {
            i++;
            x = (modular_multi(x, x, n) + c) % n;
            long long p = gcd((y - x + n) % n, n);
            if (p != 1 && p != n) return p;
            if (y == x) return n;
            if (i == k) {
                y = x;
                k <<= 1;
            }
        }
    }

    //  分解质因数   返回值是vector
    std::vector<long long int> DecomposingFactor(long long int n) {
        temp.resize(0);
        if (n <= MaxNumber) {
            while (n != 1) {
                temp.push_back((long long int) MinFactor[n]);
                n /= MinFactor[n];
            }
        } else
            find(n, 103);
        std::sort(temp.begin(), temp.end());
        return temp;
    }

    //  寻找因数
    void find(long long n, int c) {
        if (n == 1) return;
        if (Miller_Rabin(n)) {
            temp.push_back(n);
            return;
        }
        long long p = n, k = c;
        while (p >= n) p = Pollard_Rho(p, c--);
        find(p, k);
        find(n / p, k);
    }

    //  中国剩余定理(参数是向量)
    long long int CRT(std::vector<long long int> a, std::vector<long long int> m) {
        if (a.size() != m.size() || a.empty())return -1;
        int k = a.size();
        long long int N[k];//这个可以删除
        long long int mm = 1;//最小公倍数
        long long int result = 0;
        for (int i = 0; i < k; i++) {
            mm *= m[i];
        }
        for (int j = 0; j < k; j++) {
            long long int L, J;
            extern_gcd(mm / m[j], -m[j], L, J);
            //N[j] = m[j] * J + 1;//1
            N[j] = mm / m[j] * L;//2  1和2这两个值应该是相等的。（可优化）
            result += N[j] * a[j];
        }
        return (result % mm + mm) % mm;//落在(0, mm)之间，这么写是为了防止result初始为负数
    }

    //  不打表硬算欧拉函数
    long long int Euler(long long int n) {
        long long int m = floor(sqrt(n + 0.5));
        long long int ans = n;
        for (int i = 2; i <= m; i++) {
            if (n % i == 0) {
                ans = ans / i * (i - 1);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 1)
            ans = ans / n * (n - 1);
        return ans;
    }

    //  带模快速幂(欧拉函数优化,字符串指数)
    long long int modular_exp(long long int a, char str[], long long int mod) {
        long long int len = strlen(str);
        long long int res = 0;
        long long int t = Euler(mod);
        if (len <= 15) {
            for (int i = 0; i < len; i++) {
                res = res * 10 + str[i] - '0';
            }
        } else {
            for (int i = 0; i < len; i++) {
                res = res * 10 + str[i] - '0';
                res %= t;
            }
            if (res < 0) res += t;   //  Or "+mod"? I'am confused.
        }
        return modular_exp(a, res, mod);
    }
}number(2000000);
using namespace std;
vector<int>temp;
int n;
bool check(int now) {
    for (int i = 0; i < temp.size(); ++i)
        if (now == temp[i]) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    int len=number.Prime.size();

    for (int k = 1; k <= 3; ++k) {
        bool flag = 0;
        for (int i = 0; i < len && number.Prime[i] <= n; ++i) {
            if (n % number.Prime[i] == 0 && check(number.Prime[i])) {
                n /= number.Prime[i];
                temp.push_back(number.Prime[i]);
                flag = 1;
                break;
            }
        }

        if (flag == 0)  {
            cout << "NO\n";
            return 0;
        }
    }

    if (n != 1) cout << "NO\n";
    else    cout << "YES\n";

}


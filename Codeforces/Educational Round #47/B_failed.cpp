#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
/*
first send ones to the front to replace twos
then send twos as end as possible
at last, send zero to the front
*/
string changeOne(string in) {
    string ans = "";
    int num[2] = {0}, len = in.size();
    for (int i = 0; i < len; ++i) {
        num[in[i] - '0'] += 1;
    }

    for (int i = 0; i < num[1]; ++i)    ans += '1';
    for (int i = 0; i < num[0]; ++i)    ans += '0';
    return ans;
}
string one(string in) {
    string ans = "";
    int cnt = 0, len = in.size();
    while (cnt != len) {
        if (in[cnt] == '2') ans += '2';
        else {
            int s = cnt;
            while (cnt != len) {
                if (in[cnt] != '2') cnt += 1;
                else    break;
            }
            ans += changeOne(in.substr(s, cnt - s));
            continue;
        }
        cnt += 1;
    }
    return ans;
}
string changeTwo(string in) {
    string ans = "";
    int num[3] = {0}, len = in.size();
    for (int i = 0;i < len; ++i) {
        num[in[i] - '0'] += 1;
    }

    for (int i = 0; i < num[1]; ++i)    ans += '1';
    for (int i = 0; i < num[2]; ++i)    ans += '2';
    return ans;
}
string two(string in) {
    string ans = "";
    int len = in.size(), cnt = 0;
    while (cnt != len) {
        if (in[cnt] == '0') ans += '0';
        else {
            int s = cnt;
            while (cnt != len) {
                if (in[cnt] != '0') cnt += 1;
                else    break;
            }
            ans += changeTwo(in.substr(s, cnt - s));
            //in this situation, just continue is fine
            continue;
        }
        cnt += 1;
    }
    return ans;
}

string changeZero(string in) {
    string ans = "";
    int num[2] = {0}, len = in.size();
    for (int i = 0; i < len; ++i) {
        num[in[i] - '0'] += 1;
    }

    for (int i = 0; i < num[0]; ++i)    ans += '0';
    for (int i = 0; i < num[1]; ++i)    ans += '1';
    return ans;
}
string zero(string in) {
    string ans = "";
    int cnt = 0, len = in.size();
    while (cnt != len) {
        if (in[cnt] == '2') {
            ans += '2';
        } else {
            int s = cnt;
            while (cnt != len) {
                if (in[cnt] != '2') cnt += 1;
                else    break;
            }
            ans += changeZero(in.substr(s, cnt - s));
            continue;
        }
        cnt += 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    //testing the substring function
    // string a = "00010101110";
    // cout << a.substr(1, 1) << endl;
    //substr(begin_position, string_length)

    string in;
    cin >> in;

    string ans;
    ans = one(in);
    ans = two(ans);
    ans = zero(ans);
    cout << ans << endl;
}
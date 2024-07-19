/*
Một số được coi là số đẹp nếu nó chỉ bao gồm 2 số là 8 và 0. Bạn được cấp một số nguyên dương X, nhiệm vụ của bạn là tìm bội dương nhỏ nhất của X thỏa mãn bội này là số đẹp.

Gợi ý : Sinh ra xâu nhị phân gồm 2 chữ số 0 và 8 với độ dài đủ lớn, đủ để có hết các bội tới số 300. Sau đó chuyển chuỗi thành số
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string s;
vector<ll> v;
bool final = false;
void khoitao()
{
    for(int i = 0; i < s.size(); i++)
    {
        s[i] = '0';
    }
}

void sinh()
{
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '8')
    {
        s[i] = '0';
        i--;
    }
    if(i == -1)
    {
        final = true;
    }else {
        s[i] = '8';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    s = string(19, '0');
    s[s.size() - 1] = '8';
    while(!final)
    {
        v.push_back(stoll(s));
        sinh();
    }
    ll ans[303];
    for(int i = 1; i <= 300; i++)
    {
        for(ll x : v)
        {
            if(x % i == 0)
            {
                ans[i] = x;
                break;
            }
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
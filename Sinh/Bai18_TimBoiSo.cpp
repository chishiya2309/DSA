/*
Một số được coi là số đẹp nếu nó chỉ bao gồm 2 số là 8 và 0. Bạn được cấp một số nguyên dương X, nhiệm vụ của bạn là tìm bội dương nhỏ nhất của X thỏa mãn bội này là số đẹp.

Gợi ý : Sinh ra xâu nhị phân gồm 2 chữ số 0 và 8 với độ dài đủ lớn, đủ để có hết các bội tới số 300. Sau đó chuyển chuỗi thành số.

Đầu vào
Dòng đầu tiên là số bộ test T.

T dòng tiếp theo mỗi dòng là một số nguyên dương N.

Giới hạn
1<=T<=300

1<=N<=300

Đầu ra
Mỗi test in kết quả trên 1 dòng

Ví dụ :
Input 01
6
240
19
55
47
287
247
Output 01
8880
88008
880
80088
8088808
8000000008
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string s;
bool final = false;
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
    vector<ll> v;
    s = string(19, '0');
    s[s.size() - 1] = '8';
    while(!final)
    {
        v.push_back(stoll(s));
        sinh();
    }
    sort(v.begin(), v.end());
    ll ans[303];
    for(int i = 1; i <= 300; i++)
    {
        for(ll num : v)
        {
            if(num % i == 0)
            {
                ans[i] = num;
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
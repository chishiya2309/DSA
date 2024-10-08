/*
Cho số nguyên dương N và K, nhiệm vụ của bạn là liệt kê các xâu nhị phân có độ dài N và có K bit 1 theo thứ tự từ điển tăng dần.

Sau đó tiếp tục liệt kê các xâu nhị phân mà chỉ có duy nhất K bit 1 liên tiếp.

Lưu ý rằng xâu 1101111 sẽ có 2 nhóm 3 bit 1 liên tiếp do có nhóm 1111

Đầu vào
1 dòng chứa 2 số nguyên dương N và K.

Giới hạn
1<=K<=N<=15

Đầu ra
Dòng đầu tiên in ra các xâu nhị phân có K bit 1.

Dòng thứ 2 in ra các xâu nhị phân có duy nhất K bit 1 liên tiếp.

Ví dụ :
Input 01
3 2
Output 01
011 101 110 
011 110
*/

#include <bits/stdc++.h>

using namespace std;
int n, k, x[16];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
}
void sinh()
{
    int i = n;
    while(i >= 1 && x[i] == 1)
    {
        x[i] = 0;
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        x[i] = 1;
    }
}
bool check1()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt += x[i];
        if(cnt > k)
        {
            return false;
        }
    }
    return cnt == k;
}
bool check2()
{
    int cnt = 0, dem = 0;
    for(int i = 1; i <= n; i++)
    {
        if(x[i] == 1)
        {
            cnt++;
        }else {
            if(cnt > k)
            {
                return false;
            }
            if(cnt == k)
            {
                dem++;
            }
            cnt = 0;
        }
    }
    if(cnt == k)
    {
        dem++;
    }
    if(cnt > k)
    {
        return false;
    }
    return dem == 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    khoitao();
    while(!final)
    {
        if(check1())
        {
            for(int i = 1; i <= n; i++)
            {
                cout << x[i];
            }
            cout << " ";
        }
        sinh();
    }
    cout << endl;
    khoitao();
    final = false;
    vector<vector<int>> v;
    while(!final)
    {
        if(check2())
        {
            vector<int> tmp(x + 1, x + n + 1);
            v.push_back(tmp);
        }
        sinh();
    }
    sort(v.begin(), v.end());
    for(auto x : v)
    {
        for(int num : x)
        {
            cout << num;
        }
        cout << " ";
    }
    return 0;
}
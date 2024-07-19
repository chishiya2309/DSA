/*
Cho số nguyên dương N và K, nhiệm vụ của bạn là liệt kê các xâu nhị phân có độ dài N và có K bit 1 theo thứ tự từ điển tăng dần.

Sau đó tiếp tục liệt kê các xâu nhị phân mà chỉ có duy nhất K bit 1 liên tiếp.

Lưu ý rằng xâu 1101111 sẽ có 2 nhóm 3 bit 1 liên tiếp do có nhóm 1111
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
    int dem = 0;
    for(int i = 1; i <= n; i++)
    {
       dem += x[i];
    }
    return dem == k;
}

bool check2()
{
    int cnt = 0, dem = 0;
    for(int i = 1; i <= n; i++)
    {
        if(x[i] == 1)
        {
            dem++;
        }else {
            if(dem > k)
            {
                return false;
            }
            if(dem == k)
            {
                cnt++;
            }
            dem = 0;
        }
    }
    if(dem > k)
    {
        return false;
    }
    if(dem == k)
    {
        cnt++;
    }
    return cnt == 1;
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
    final = false;
    khoitao();
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
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }
        cout << " ";
    }
    return 0;
}
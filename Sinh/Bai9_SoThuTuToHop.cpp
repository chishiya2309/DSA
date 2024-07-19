/*
Cho các số tự nhiên từ 1 tới N và số nguyên K, bạn được cung cấp một cấu hình tập con K phần tử của N phần tử. Hãy xác định xem cấu hình này là cấu hình thứ bao nhiêu theo thứ tự ngược.
*/

#include <bits/stdc++.h>

using namespace std;
int n, k, a[18];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}

void sinh()
{
    int i = k;
    while(i >= 1 && a[i] == n - k + i)
    {
        i--;
    }

    if(i == 0)
    {
        final = true;
    }else {
        a[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<int> x(k);
    for(int i = 0; i < k; i++)
    {
        cin >> x[i];
    }
    khoitao();
    vector<vector<int>> v;
    
    while(!final)
    {
        vector<int> tmp(a + 1, a + k + 1);
        v.push_back(tmp);
        sinh();
    }
    int cnt = 0;
    for(int i = v.size() - 1; i >= 0; i--)
    {
        cnt++;
        if(v[i] == x)
        {
            cout << cnt;
            return 0;
        }
    }
    return 0;
}
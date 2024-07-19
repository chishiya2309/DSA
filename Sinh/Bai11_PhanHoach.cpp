/*
Cho số nguyên dương N, bạn hãy in ra các cách biểu diễn N dưới dạng tổng của các số tự nhiên <= N.
*/

#include <bits/stdc++.h>
#define endl '\n'
int n, k, a[21], cnt;
bool final = false;

void khoitao()
{
    cnt = 1;
    a[1] = n;
}

void sinh()
{
    int i = cnt;
    while(i >= 1 && a[i] == 1)
    {
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        a[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / a[i], r = d % a[i];
        if(q > 0 )
        {
            for(int j = 1; j <= q; j++)
            {
                ++cnt; a[cnt] = a[i];
            }
        }

        if(r > 0)
        {
            ++cnt; a[cnt] = r;
        }
    }
}
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    khoitao();
    vector<vector<int>> res;
    while(!final)
    {
        vector<int> tmp(a + 1, a + cnt + 1);
        res.push_back(tmp);
        sinh();
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if(j != res[i].size() - 1)
            {
                cout << "+";
            }
        }
        cout << endl;
    }
    return 0;
}
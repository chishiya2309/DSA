/*
Cho N số nguyên tự nhiên từ 1 tới N, bạn hãy sinh ra các tập con có K phần tử của tập N phần tử này theo thuật toán sinh kế tiếp.
*/

#include <bits/stdc++.h>

using namespace std;
int n, k, x[23];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= k; i++)
    {
        x[i] = i;
    }
}

void sinh()
{
    int i = k;
    while(i >= 1 && x[i] == n - k + i)
    {
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        x[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            x[j] = x[j - 1] + 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    khoitao();
    while(!final)
    {
        for(int i = 1; i <= k; i++)
        {
            cout << x[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n, k, x[20];
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
signed main()
{
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
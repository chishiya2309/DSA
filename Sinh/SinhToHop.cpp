#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, k;
int x[100];
bool final = false;

void init()
{
    for(int i = 1; i <= k; i++)
    {
        x[i] = i;
    }
}

void sinh()
{
    int i = k;
    while(i > 0 && x[i] == n - k + i)
    {
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else 
    {
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
    init();

    while(!final)
    {
        for(int i = 1; i <= k; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
        sinh();
    }

    return 0;

}
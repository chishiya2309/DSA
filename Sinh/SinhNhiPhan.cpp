#include<bits/stdc++.h>
using namespace std;
int n, x[20];
bool final = false;
void ktao()
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
    }else{
        x[i] = 1;
    }
}
signed main()
{
    cin >> n;
    ktao();
    while(!final)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << x[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}
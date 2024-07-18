#include<bits/stdc++.h>
using namespace std;
int n, a[100];
bool final = false;
void init()
{
    for(int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}

void sinh()
{
    int i = n; 
    while(i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }

    if(i == 0)
    {
        final = true;
    }else {
        a[i] = 1;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    init();
    while(!final)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}
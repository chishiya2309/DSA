#include<bits/stdc++.h>
using namespace std;

int n, X[100];
bool final = false;
void init()
{
    for(int i= 1; i <= n; i++)
    {
        X[i] = i;
    }
}
void sinh()
{
    int i = n; 
    while(i >= 1 && X[i] > X[i + 1])
    {
        i--;
    }
    if(i == 0)
    {
        final = true;
    }
    else {
        int j = n;
        while(X[i] > X[j])
        {
            --j;
        }
        swap(X[i], X[j]);
        reverse(X + i + 1, X + n + 1);
    }
}
signed main()
{
    cin >> n;
    init();
    while(!final)
    {
        for(int i = 1; i <= n; ++i)
        {
            cout << X[i];
        }
        cout << endl;
        sinh();
    } 
}
#include <bits/stdc++.h>

using namespace std;
int n, X[10003], k;
bool final = false;
void sinh()
{
    int i = k;
    while(i >= 1 && X[i] == n - k + i)
    {
        --i;
    }
    if(i == 0)
    {
        final = true;
    }else {
        X[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            X[j] = X[j - 1] + 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
    {
        cin >> X[i];
    }
    sinh();
    if(final)
    {
        for(int i = 1; i <= k; i++)
        {
            cout << i << " ";
        }
    }else {
        for(int i = 1; i <= k; i++)
        {
            cout << X[i] << " ";
        }
    }
    return 0;
}
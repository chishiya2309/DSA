/*
Cho số nguyên dương N, bạn hãy in ra các xâu gồm N kí tự 'A' và 'B' theo thứ tự từ điển giảm dần.
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, X[23];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= n; i++)
    {
        X[i] = 0;
    }
}

void sinh()
{
    int i = n;
    while(i >= 1 && X[i] == 1)
    {
        X[i] = 0;
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        X[i] = 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<string> XauAB;
    while(!final)
    {
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            if(X[i] == 0)
            {
                s += "A";
            }else {
                s += "B";
            }
        }
        XauAB.push_back(s);
        sinh();
    }
    sort(XauAB.begin(), XauAB.end(), greater<string>());
    for(int i = 0; i < XauAB.size(); i++)
    {
        cout << XauAB[i] << endl;
    }
    return 0;
}
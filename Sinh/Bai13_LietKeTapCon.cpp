/*
Cho một tập gồm N phần tử được đánh số từ 1 đến N. Nhiệm vụ của bạn là liệt kê tất cả các tập con khác rỗng của N theo thứ tự từ điển tăng dần.
*/

#include <bits/stdc++.h>

using namespace std;
int n, a[20];
bool final = false;
void ktao()
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
        i--;
    }
    if(i == 0)
    {
        final = 1;
    }else {
        a[i] = 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ktao();
    vector<vector<int>> v;
    while(!final)
    {
        vector<int> tmp;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == 1)
            {
                tmp.push_back(i);
            }
        }
        v.push_back(tmp);
        sinh();
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        for(int x : v[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

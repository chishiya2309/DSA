#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, a[20];
vector<vector<int>> res;
int used[20];
bool check(vector<int> v)
{
    int sum = 0;
    for(int x : v)
    {
        sum += x;
    }
    return sum % 2;
}

void Try(vector<int> v, int pos)
{
    if(v.size() && check(v))
    {
        res.push_back(v);
    }

    for(int i = pos + 1; i < n; i++)
    {
        if(!used[i])
        {
            v.push_back(a[i]);
            used[i] = 1;
            Try(v, i);
            v.pop_back();
            used[i] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> v;
    Try(v, -1);
    if(res.empty())
    {
        cout << "NOT FOUND";
        return 0;
    }else {
        sort(res.begin(), res.end());
        for(auto x : res)
        {
            for(int num : x)
            {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

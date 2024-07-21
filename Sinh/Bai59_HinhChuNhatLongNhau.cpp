#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first)
    {
        return a.first < b.first;
    }else {
        return a.second < b.second;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<pair<int, int>> hinhChuNhat(n);
    for(int i=0; i<n; i++)
    {
        cin >> hinhChuNhat[i].first >> hinhChuNhat[i].second;
    }
    sort(hinhChuNhat.begin(), hinhChuNhat.end(), cmp);
    vector<int> lis;

    for(auto hcn : hinhChuNhat)
    {
        auto it = lower_bound(lis.begin(), lis.end(), hcn.second);
        if(it == lis.end())
        {
            lis.push_back(hcn.second);
        }else {
            *it = hcn.second;
        }
    }
    cout << lis.size();
    return 0;
}
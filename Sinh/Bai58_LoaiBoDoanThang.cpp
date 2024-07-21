#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> Length(n);
    for(int i = 0; i < n; i++)
    {
        cin >> Length[i].first >> Length[i].second;
    }
    sort(Length.begin(), Length.end(), cmp);;
    int cnt = 0;
    int tmp = Length[0].second;
    for(int i = 1; i < n; i++)
    {
        if(tmp > Length[i].first)
        {
            cnt++;
        }else {
            tmp = Length[i].second;
        }
    }
    cout << cnt;
    return 0;
}
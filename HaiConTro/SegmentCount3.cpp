/*Cho mảng A[] gồm N số nguyên và số nguyên K, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các phần tử liên tiếp trong mảng mà số lượng phần từ khác nhau trong mảng con này không vượt quá K.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0;
    ll res = 0;
    map<int, int> mp;
    for(int r = 0; r < n; r++)
    {
        mp[a[r]]++;
        while(mp.size() > k)
        {
            mp[a[l]]--;
            if(mp[a[l]] == 0)
            {
                mp.erase(a[l]);
            }
            l++;
        }
        res += r - l + 1;
    }
    cout << res;
    return 0;
}
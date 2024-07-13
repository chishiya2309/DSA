/*
Cho mảng A[] gồm N số nguyên và số nguyên K, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các phần tử liên tiếp trong mảng mà độ chênh lệch giữa phần tử lớn nhất và phần tử nhỏ nhất trong mảng con đó không vượt quá K


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
    multiset<int> se;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int l = 0;
    ll res = 0;
    for(int r = 0; r < n; r++)
    {
        se.insert(a[r]);
        while(*se.rbegin() - *se.begin() > k)
        {
            auto it = se.find(a[l]);
            se.erase(it);
            l++;
        }
        res += r - l + 1;
    }
    cout << res;
    return 0;
}
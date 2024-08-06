/*
Cho mảng A[] gồm N số nguyên và số nguyên K, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các phần tử liên tiếp trong mảng mà số lượng phần từ khác nhau trong mảng con này không vượt quá K.

Đầu vào
• Dòng đầu tiên là N và K

• Dòng thứ 2 là N số trong mảng A[]

Giới hạn
• 1<=K<=N<=10^5

• 1<=A[i]<=10^6

Đầu ra
In ra số lượng mảng con thỏa mãn đề bài

Ví dụ :
Input 01
4 2
1 1 2 4
Output 01
8
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }
    map<int, int> mp;
    int left = 0;
    ll soMangCon = 0;
    for(int right = 0; right < n; ++right)
    {
        mp[a[right]]++;
        while(mp.size() > k)
        {
            mp[a[left]]--;
            if(mp[a[left]] == 0)
            {
                mp.erase(a[left]);
            }
            left++;
        }
        soMangCon += right - left + 1;
    }
    cout << soMangCon;
    return 0;
}


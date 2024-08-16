/*
Cho mảng A[] gồm N số nguyên và số nguyên K, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các phần tử liên tiếp trong mảng mà độ chênh lệch giữa phần tử lớn nhất và phần tử nhỏ nhất trong mảng con đó không vượt quá K

Đầu vào
• Dòng đầu tiên là N và K

• Dòng thứ 2 là N số trong mảng A[]

Giới hạn
• 1<=N<=10^5

• 1<=A[i],K<=10^6

Đầu ra
In ra số lượng mảng con thỏa mãn đề bài

Ví dụ :
Input 01
Copy
10 1
2 3 1 3 1 4 1 3 1 2
Output 01
Copy
12
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

    multiset<int> se;
    int left = 0;
    ll soMangCon = 0;
    for(int right = 0; right < n; right++)
    {
        se.insert(a[right]);
        while(*se.rbegin() - *se.begin() > k)
        {
            auto it = se.find(a[left]);
            se.erase(it);
            left++;
        }
        soMangCon += right - left + 1;
    }

    cout << soMangCon;

    return 0;
}
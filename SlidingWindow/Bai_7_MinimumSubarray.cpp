/*
Cho mảng A[] có N phần tử, bạn hãy tìm ra dãy con các phần tử liên tiếp có tổng tối thiểu bằng K. Nếu có nhiều dãy con thỏa mãn hãy in ra dãy con ngắn nhất xuất hiện đầu tiên, trong trường hợp không tồn tại dãy con thỏa mãn in ra -1.

Đầu vào
• Dòng 1 là N và K

• Dòng 2 gồm N số trong mảng A[]

Giới hạn
• 1<=N<=10^6

• 0<=A[i]<=10^6

• 0<=K<=10^9

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
11 7
2 4 0 4 2 3 3 2 0 0 3
Output 01
4 0 4
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
    int minLength = INT_MAX;
    int start_index = -1;
    int left = 0;
    ll sum = 0;
    for(int right = 0; right < n; right++)
    {
        sum += a[right];
        while(sum >= k)
        {
            if(right - left + 1 < minLength)
            {
                minLength = right - left + 1;
                start_index = left;
            }   
            sum -= a[left];
            left++;
        }
    }
    if(start_index == -1)
    {
        cout << -1;
    }else {
        for(int i = start_index; i < start_index + minLength; i++)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}
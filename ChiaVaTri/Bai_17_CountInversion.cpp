/*
Cho mảng A[] gồm N phần tử, hãy đếm số lượng cặp A[i], A[j] sao cho i < j và A[i] > A[j]

Đầu vào
Dòng đầu tiên chứa số nguyên dương N

Dòng thứ 2 gồm N phần tử của mảng A[]

Giới hạn
1<=N<=10^6

1<=A[i]<=10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
9
16 14 10 13 19 14 17 18 16
Output 01
12
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int merge(int a[], int l, int m, int r)
{
    int dem = 0;
    vector<int> left(a + l, a + m + 1);
    vector<int> right(a + m + 1, a + r + 1);
    int index = l, i = 0, j = 0;
    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
        {
            a[index] = left[i];
            index++;
            i++;
        }else 
        {
            dem += left.size() - i;
            a[index] = right[j];
            index++;
            j++;
        }
    }

    while(i < left.size())
    {
        a[index] = left[i];
        index++;
        i++;
    }

    while(j < right.size())
    {
        a[index] = right[j];
        index++;
        j++;
    }
    return dem;
}

ll mergesort(int a[], int l, int r)
{
    if(l < r)
    {
        ll ans = 0;
        int m = (l + r) / 2;
        ans += mergesort(a, l, m);
        ans += mergesort(a, m + 1, r);
        ans += merge(a, l, m, r);
        return ans;
    }else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int a[n];
    for(int &x : a)
    {
        cin >> x;
    }

    ll res = mergesort(a, 0, n - 1);
    cout << res;

    return 0;
}
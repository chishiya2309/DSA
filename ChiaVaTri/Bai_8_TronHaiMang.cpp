/*
Cho hai mảng đã được sắp xếp A[], B[] gồm N, M phần tử theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

Đầu vào
Dòng đầu tiên chứa 3 số N, M, K

Dòng thứ 2 chứa N số nguyên của mảng A[]

Dòng thứ 3 chứa M số nguyên của mảng B[]

Giới hạn
1<=N,M<=10^4

1<=K<=N+M

1<=A[i],B[i]<=10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
7 9 14
4 6 7 9 10 10 10 
1 1 2 5 7 8 8 9 10
Output 01
Copy
10
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    int dem = -1;
    int a[n], b[m];

    for(int &x : a)
    {
        cin >> x;
    }

    for(int &x : b)
    {
        cin >> x;
    }

    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(a[i] <= b[j])
        {
            dem++;
            if(dem == k)
            {
                cout << a[i];
                return 0;
            }
            i++;
        }else {
            dem++;
            if(dem == k)
            {
                cout << b[j];
                return 0;
            }
            j++;
        }
    }

    while(i < n)
    {
        dem++;
        if(dem == k)
        {
            cout << a[i];
            return 0;
        }
        i++;
    }

    while(j < m)
    {
        dem++;
        if(dem == k)
        {
            cout << b[j];
            return 0;
        }
        j++;
    }

    return 0;
}
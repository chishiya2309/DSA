/*
Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn làm tìm phần tử đầu tiên bên phải lớn hơn của mọi phần tử A[i] trong mảng, nếu phần tử nào không có phần tử bên phải lớn hơn thì in ra -1.

Đầu vào
Dòng đầu tiên chứa N : Số lượng phần tử trong mảng.

Dòng thứ 2 chứa N số nguyên, mỗi số cách nhau một khoảng trắng.

Giới hạn
1<=N<=10^6

1<=A[i]<=10^6

Đầu ra
In ra đáp án của bài toán trên 1 dòng.

Ví dụ :
Input 01
Copy
8
19 11 11 15 13 18 19 18
Output 01
Copy
-1 15 15 18 18 19 -1 -1
*/

#include <bits/stdc++.h>

using namespace std;

void xuly(int a[], int d[], int n)
{
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && a[i] > a[st.top()])
        {
            d[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        d[st.top()] = -1;
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int a[n], d[n];
    for(int &x : a)
    {
        cin >> x;
    }

    xuly(a, d, n);
    for(int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }
    return 0;
}
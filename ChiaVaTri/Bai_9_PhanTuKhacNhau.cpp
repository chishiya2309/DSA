/*
Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

Đầu vào
Dòng đầu chứa số nguyên dương N

Dòng thứ 2 chứa các phần tử của mảng A[]

Dòng thứ 3 chứa các phần tử của mảng B[]

Giới hạn
1<=N<=10^5

1<=A[i], B[i]<=10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
8
1 2 3 4 5 6 7 8 
1 2 3 4 5 6 8
Output 01
Copy
7
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int a[n], b[n - 1];
    for(int &x : a)
    {
        cin >> x;
    }

    for(int &x : b)
    {
        cin >> x;
    }

    int i = 0, j = 0;
    while(i < n && j < n - 1)
    {
        if(a[i] != b[j])
        {
            cout << i + 1;
            return 0;
        }else {
            i++;
            j++;
        }
    }

    return 0;
}
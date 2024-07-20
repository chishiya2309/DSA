/*
Cho mảng A[] gồm n số nguyên dương. Nhiệm vụ của bạn là hãy sắp xếp lại các phần tử của mảng sao cho A[i] ≥A[i-1] nếu i chẵn, A[i] ≤A[i-1] nếu i lẻ.

Ví dụ với mảng A[] = {1, 2, 2, 1} ta được mảng được sắp A[] = { 1, 2, 1, 2}. Bài này các bạn có thể sub không AC nhưng vẫn đúng nhé.

Đầu vào
Dòng đầu tiên đưa vào n là số phần tử của mảng A[]

Dòng kế tiếp đưa vào n số A[i] của mảng

Giới hạn
1≤ N ≤10^6

1≤ A[i] ≤10^6

Đầu ra
In ra kết quả trên một dòng

Ví dụ :
Input 01
4
1 2 3 4
Output 01
1 4 2 3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int odd = 1, even = 0;
    vector<int> res(n);
    for(int i = 0; i < n; i++)
    {
        if(even < n)
        {
            res[even] = a[i];
            even += 2;
        }else {
            res[odd] = a[i];
            odd += 2;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

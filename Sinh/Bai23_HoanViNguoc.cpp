/*
Cho mảng số nguyên gồm N phần tử, các phần tử trong mảng không quá 100. Hãy liệt kê các hoán vị của các phần tử khác nhau trong mảng theo thứ tự ngược.

Đầu vào
Dòng đầu tiên là N

Dòng thứ 2 là các phần tử trong mảng;

Giới hạn
1<=N<=15

Đầu ra
In ra các hoán vị ngược của các phần tử khác nhau trong mảng.

Ví dụ :
Input 01
Copy
2
1 2
Output 01
Copy
2 1
1 2
*/

#include <bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    set<int> unique_elements;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        unique_elements.insert(x);
    }
    
    vector<int> x(unique_elements.begin(), unique_elements.end());
    sort(x.begin(), x.end(), greater<int>());
    do
    {
        for(int i = 0; i < x.size(); i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }while(prev_permutation(x.begin(), x.end()));
    return 0;
}
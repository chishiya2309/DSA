/*
Cho đồ thị vô hướng G = <V, E> gồm n đỉnh và m cạnh được biểu diễn dưới dạng danh sách kề.

Hãy chuyển đổi đồ thị dưới dạng danh sách kề này sang danh sách cạnh tương ứng.

Gợi ý : Đối với mỗi dòng đọc như 1 chuỗi rồi tách các số trong dòng đó để thu được danh sách kề

Đầu vào
Dòng đầu tiên là số nguyên dương n, tương ứng với số đỉnh của đồ thị.

n dòng tiếp theo mỗi dòng chứa nhiều số nguyên, dòng thứ i tương ứng với các đỉnh trong danh sách kề của đỉnh i.

Giới hạn
1<=n<=1000

Đầu ra
In ra các cạnh trong đồ thị trên từng dòng, các cạnh được liệt kê tăng dần. Chú ý mỗi cạnh chỉ liệt kê một lần.

Ví dụ :
Input 01
5
4 
3 4 5 
2 5 
1 2 
2 3
Output 01
1 4
2 3
2 4
2 5
3 5
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
set<int> ke[1003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int num;
        while(ss >> num)
        {
            if(i < num)
            {
                ke[i].insert(num);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j : ke[i])
        {
            cout << i << " " << j;
            cout << endl;
        }
    }

    return 0;
}
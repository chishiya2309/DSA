/*
Cho mảng A[] gồm N phần tử, liệt kê các tập con (giữ đúng thứ tự trước sau) của mảng A[] có tổng các phần tử là số lẻ, mỗi phần tử chỉ được lấy 1 lần. Chú ý nếu 2 tập hợp chứa 2 phần tử có giá trị giống nhau nhưng ở vị trí khác nhau thì được tính 2 tập hợp khác nhau.

Đầu vào
• Dòng 1 là N : số lượng phần tử trong mảng

• Dòng 2 gồm N số trong mảng A[]

Giới hạn
• 2 <= N <= 15

• 1 <= A[i] <= 1000

Đầu ra
• In ra các tập con thỏa mãn theo thứ tự từ điển tăng dần, nếu không tồn tại dãy con in ra NOT FOUND

Ví dụ :
Input 01
4
9 7 9 9
Output 01
7 
7 9 9 
9 
9 
9 
9 7 9 
9 7 9 
9 9 9
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, a[20];
bool check(vector<int> v)
{
    int res = 0;
    for(int x : v)
    {
        res += x;
    }
    return res % 2;
}
vector<vector<int>> ans;
bool used[16];
void Try(vector<int> v, int last)
{
    if(v.size() && check(v))
    {
        ans.push_back(v);
    }

    for(int i = last + 1; i < n; i++)
    {
        if(!used[i])
        {
            v.push_back(a[i]);
            used[i] = 1;
            Try(v, i);
            v.pop_back();
            used[i] = 0;

        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    Try(v, -1);
    if(ans.empty())
    {
        cout << "NOT FOUND";
        return 0;
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans)
    {
        for(int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
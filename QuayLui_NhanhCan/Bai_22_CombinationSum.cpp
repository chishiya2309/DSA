/*
Cho 2 số nguyên dương N và K, bạn hãy liệt kê các các tổ hợp K phần tử các số có 1 chữ số mà có tổng bằng N. Mỗi tổ hợp chỉ tính 1 lần và được in ra theo thứ tự từ bé đến lớn, các tổ hợp cũng được liệt kê theo thứ tự từ điển tăng dần. Nếu không tồn tại tổ hợp K phần tử thỏa mãn có tổng bằng N in ra NOT FOUND

Đầu vào
• Dòng duy nhất chứa N và K

Giới hạn
• 2<=K<=9

• 1<=N<=60

Đầu ra
In ra các cấu hình thỏa mãn trên từng dòng

Ví dụ :
Input 01
38 7
Output 01
1 + 2 + 5 + 6 + 7 + 8 + 9
1 + 3 + 4 + 6 + 7 + 8 + 9
2 + 3 + 4 + 5 + 7 + 8 + 9
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k;
bool final = false;
void Try(vector<int> v)
{
    if(v.size() == k)
    {
        int sum = 0;
        for(int num : v)
        {
            sum += num;
        }
        if(sum == n)
        {
            final = true;
            for(int i = 0; i < v.size(); i++)
            {
                cout << v[i];
                if(i == v.size() - 1)
                {
                    cout << endl;
                }else {
                    cout << " + ";
                }
            }
        }
        return;
    }
    for(int i = 1; i < 10; i++)
    {
        if(v.empty() || i > v.back())
        {
            v.push_back(i);
            Try(v);
            v.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<int> v;
    Try(v);
    if(!final)
    {
        cout << "NOT FOUND";
    }
    return 0;
}
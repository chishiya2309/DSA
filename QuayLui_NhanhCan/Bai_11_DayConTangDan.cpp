/*
Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau đôi một. Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] thỏa mãn tính chất tăng dần. Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng vẫn giữ nguyên thứ tự ban đầu. Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, hãy liệt kê theo thứ tự từ điển

Đầu vào
Dòng đầu ghi số n

Dòng thứ 2 ghi n số của dãy a[]

Giới hạn
2<=n<=20

1<=a[i]<=100

Đầu ra
Đưa ra các dãy con hợp lệ theo thứ tự từ điển tăng dần.

Ví dụ :
Input 01
7
4 8 6 7 3 5 2
Output 01
3 5 
4 5 
4 6 
4 6 7 
4 7 
4 8 
6 7
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<string> ans;
int n;
void Try(vector<int> &a, int start, vector<int> &res)
{
    if(res.size() >= 2)
    {
        bool isIncreasing = true;
        for(int i = 1; i < res.size(); i++)
        {
            if(res[i] <= res[i - 1])
            {
                isIncreasing = false;
                return;
            }
        }

        if(isIncreasing)
        {
            string tmp = "";
            for(int num : res)
            {
                tmp += to_string(num) + " ";
            }
            tmp.pop_back();
            ans.push_back(tmp);
        }

    }
    
    for(int i = start; i < n; i++)
    {
        res.push_back(a[i]);
        Try(a, i + 1, res);
        res.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }
    vector<int> res;
    Try(a, 0, res);
    sort(ans.begin(), ans.end());
    for(auto b : ans)
    {
        cout << b << endl;
    }
    return 0;
}
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
int n;
vector<string> v;
void Try(vector<int> &a, int start, vector<int> ans)
{
    if(ans.size() >= 2)
    {
        bool increasing = true;
        for(int i = 1; i < ans.size(); i++)
        {
            if(ans[i] <= ans[i - 1])
            {
                increasing = false;
                return;
            }
        }

        if(increasing)
        {
            string res = "";
            for(int num : ans)
            {
                res += to_string(num) + " ";
            }
            res.pop_back();
            v.push_back(res);
        }
    }

    for(int i = start; i < a.size(); i++)
    {
        ans.push_back(a[i]);
        Try(a, i + 1, ans);
        ans.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ans;
    Try(a, 0, ans);
    sort(v.begin(), v.end());
    for(string x : v)
    {
        cout << x << endl;
    }
    return 0;
}
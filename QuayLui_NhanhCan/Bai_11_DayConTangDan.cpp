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
vector<int> a;
vector<string> res;
void Try(int index, vector<int> ans)
{
    if(ans.size() >= 2)
    {
        bool isIncreasing = true;
        for(int i = 1; i < ans.size(); i++)
        {
            if(ans[i] <= ans[i - 1])
            {
                isIncreasing = false;
                break;
            }
        }

        if(isIncreasing)
        {
            string tmp = "";
            for(int num : ans)
            {
                tmp += to_string(num) + " ";
            }
            tmp.pop_back();
            res.push_back(tmp);
        }
    }

    for(int i = index; i < n; i++)
    {
        ans.push_back(a[i]);
        Try(i + 1, ans);
        ans.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.resize(n);
    for(int &x : a)
    {
        cin >> x;
    }
    vector<int> ans;
    Try(0, ans);
    sort(res.begin(), res.end());
    for(string x : res)
    {
        cout << x << endl;
    }
    return 0;
}
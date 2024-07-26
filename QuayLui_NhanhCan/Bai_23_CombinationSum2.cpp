/*
Cho 2 số nguyên dương N và K, bạn hãy liệt kê các các tổ hợp K phần tử các số nguyên tố mà có tổng bằng N. Mỗi tổ hợp chỉ tính 1 lần và được in ra theo thứ tự từ bé đến lớn, các tổ hợp cũng được liệt kê theo thứ tự từ điển tăng dần. Nếu không tồn tại tổ hợp K phần tử thỏa mãn có tổng bằng N in ra NOT FOUND

Đầu vào
• Dòng duy nhất chứa N và K

Giới hạn
• 1<=K<=9

• 1<=N<=500

Đầu ra
In ra các cấu hình thỏa mãn trên từng dòng

Ví dụ :
Input 01
Copy
91 3
Output 01
Copy
3 + 5 + 83
3 + 17 + 71
3 + 29 + 59
3 + 41 + 47
5 + 7 + 79
5 + 13 + 73
5 + 19 + 67
7 + 11 + 73
7 + 13 + 71
7 + 17 + 67
7 + 23 + 61
7 + 31 + 53
7 + 37 + 47
7 + 41 + 43
11 + 13 + 67
11 + 19 + 61
11 + 37 + 43
13 + 17 + 61
13 + 19 + 59
13 + 31 + 47
13 + 37 + 41
17 + 31 + 43
19 + 29 + 43
19 + 31 + 41
23 + 31 + 37
*/

#include <bits/stdc++.h>

using namespace std;
vector<int> prime;
bool check(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return n > 1;
}
void init()
{
    for(int i = 2; i <= 500; i++)
    {
        if(check(i))
        {
            prime.push_back(i);
        }
    }
}

int n, k;
bool final = false;
void Try(vector<int> v, int res)
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
            for(int i = 0; i < k; i++)
            {
                cout << v[i];
                if(i == k - 1)
                {
                    cout << endl;
                }else {
                    cout << " + ";
                }
            }
        }
        return;
    }
    if(res >= n) return;
    for(int num : prime)
    {
        if(v.empty() || num > v.back())
        {
            v.push_back(num);
            Try(v, res + num);
            v.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    vector<int> v;
    init();
    Try(v);
    if(!final)
    {
        cout << "NOT FOUND";
    }
    return 0;
}
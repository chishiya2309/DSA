/*
Tèo có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. Không có 2 thẻ nào ghi hai số trùng nhau. Tèo muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.

Đầu vào
Số nguyên dương N

Giới hạn
4<=N<=10

Đầu ra
In ra các cấu hình thỏa mãn theo thứ tự từ điển tăng dần

Ví dụ :
Input 01
Copy
4
Output 01
Copy
2413
3142
*/

#include <bits/stdc++.h>

using namespace std;
vector<int> a;
bool check()
{
    for(int i = 1; i < a.size(); i++)
    {
        if(abs(a[i] - a[i - 1]) == 1)
        {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = 1 + i;
    }
    do
    {
        if(check())
        {
            for(int i = 0; i < n; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
    } while (next_permutation(a.begin(), a.end()));
    
    return 0;
}
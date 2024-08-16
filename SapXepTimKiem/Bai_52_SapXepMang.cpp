/*
Cho mảng A[] gồm N phần tử, 28tech muốn bạn kiểm tra xem liệu có thể lật ngược 1 dãy con liên tiếp bất kỳ trong mảng 1 lần duy nhất để tạo thành mảng tăng dần hay không?

Ví dụ A = [1, 2, 5, 4, 3, 7, 8 ,9] bạn có thể lật ngược lại đoạn [2, 5, 4] để tạo thành mảng [1, 2, 3, 4, 5, 7, 8, 9]

Gợi ý : Tìm left là chỉ số bắt đầu của dãy còn cần lật (a[left] > a[left + 1]) và chỉ số right là chỉ số cuối cùng của dãy con cần lật (a[right] < a[right - 1]). Nếu left ko tồn tại tức mảng đã tăng dần rồi, còn nếu left và right tồn tại thì lật ngược đoạn đó là và kiểm tra xem sau khi lật thì mảng có tăng dần không?

Đầu vào
Dòng 1 là N : các phần tử trong mảng

Dòng 2 là N số trong mảng

Giới hạn
1<=N<=10^6

0<=A[i] <= 10^9

Đầu ra
In ra 28tech nếu có thể lật ngược mảng con để tạo thành mảng tăng dần, ngược lại in ra 29tech

Ví dụ :
Input 01
Copy
5
1 4 3 2 5
Output 01
Copy
28tech
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

bool checkTangDan(vector<int>a, int n)
{
    int left = 0;
    while(left < n - 1 && a[left] <= a[left + 1])
    {
        left++;
    }

    if(left == n - 1)
    {
        return true;
    }

    int right = n - 1;
    while(right > 0 && a[right] >= a[right - 1])
    {
        right--;
    }

    reverse(a.begin() + left, a.begin() + right + 1);

    for(int i = 1; i < n; i++)
    {
        if(a[i] <= a[i - 1])
        {
            return false;
        }
    }

    return true;
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

    if(checkTangDan(a, n))
    {
        cout << "28tech";
    }else 
    {
        cout << "29tech";
    }

    return 0;
}
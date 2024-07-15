/*
Cho mảng A[] gồm N phần tử, 28tech muốn bạn kiểm tra xem liệu có thể lật ngược 1 dãy con liên tiếp bất kỳ trong mảng 1 lần duy nhất để tạo thành mảng tăng dần hay không?

Ví dụ A = [1, 2, 5, 4, 3, 7, 8 ,9] bạn có thể lật ngược lại đoạn [2, 5, 4] để tạo thành mảng [1, 2, 3, 4, 5, 7, 8, 9]

Gợi ý : Tìm left là chỉ số bắt đầu của dãy còn cần lật (a[left] > a[left + 1]) và chỉ số right là chỉ số cuối cùng của dãy con cần lật (a[right] < a[right - 1]). Nếu left ko tồn tại tức mảng đã tăng dần rồi, còn nếu left và right tồn tại thì lật ngược đoạn đó là và kiểm tra xem sau khi lật thì mảng có tăng dần không?
*/
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>& a, int n)
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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i < n; i++) {
        cin >> a[i];
    }
    if(check(a, n))
    {
        cout << "28tech";
    }else {
        cout << "29tech";
    }
    return 0;
}
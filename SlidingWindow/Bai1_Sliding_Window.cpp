#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int &x : arr)
    {
        cin >> x;
    }

    //Bước 1: Tính tổng của k phần tử đầu tiên trong mảng
    ll window_sum = 0;
    for(int i = 0; i < k; i++)
    {
        window_sum += arr[i];
    }

    ll max_sum = window_sum;
    int start_index = 0;

    //Trượt cửa sổ qua mảng, mỗi lần trừ đi phần tử đầu của cửa sổ cũ và cộng thêm phần tử mới
    //Cập nhật tổng lớn nhất và vị trí bắt đầu của dãy con có tổng lớn nhất khi tìm thấy 1 tổng lớn hơn
    for(int i = k; i < n; i++)
    {
        window_sum = window_sum - arr[i - k] + arr[i];
        if(window_sum > max_sum)
        {
            max_sum = window_sum;
            start_index = i - k + 1;
        }
    }
    cout << max_sum << endl;
    for(int i = start_index; i < start_index + k; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
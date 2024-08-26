/*
Bạn được cung cấp một danh sách phát của một đài phát thanh kể từ khi đài đó được thành lập. Danh sách bài hát có tổng cộng n bài hát. Chuỗi các bài hát liên tiếp dài nhất mà mỗi bài hát là duy nhất?

Đầu vào
Dòng đầu tiên chứa một số nguyên n: số lượng bài hát.

Dòng tiếp theo có n số nguyên k1, k2,…, kn: số id của mỗi bài hát.

Giới hạn
1≤n≤2⋅10^5

1≤ki≤10^9

Đầu ra
In độ dài của chuỗi bài hát dài nhất mà các bài hát này mỗi bài hát chỉ xuất hiện 1 lần.

Ví dụ :
Input 01
Copy
5
1 2 2 4 5
Output 01
Copy
3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> k(n);
    for(int &x : k)
    {
        cin >> x;
    }

    map<int, int> mp;
    int left = 0;
    int maxLength = INT_MIN;

    for(int right = 0; right < n; right++)
    {
        mp[k[right]]++;
        while(mp[k[right]] == 2)
        {
            mp[k[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength;

    return 0;
}
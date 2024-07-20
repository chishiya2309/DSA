/*
• Kirito đang bị mắc kẹt ở cấp độ của MMORPG mà anh ấy đang chơi hiện tại. Để tiếp tục trò chơi, anh ta phải đánh bại tất cả n con rồng sống ở cấp độ này. Kirito và những con rồng có sức mạnh, được biểu thị bằng một số nguyên. Trong cuộc đọ sức giữa hai đối thủ, kết quả của cuộc đọ sức được quyết định bởi sức mạnh của họ. Ban đầu, sức mạnh của Kirito bằng s.

• Nếu Kirito bắt đầu đấu tay đôi với rồng thứ i (1 ≤ i ≤ n) và sức mạnh của Kirito không lớn hơn sức mạnh của rồng có sức mạnh là xi, thì Kirito thua trận đấu và chết. Nhưng nếu sức mạnh của Kirito lớn hơn sức mạnh của con rồng, thì anh ta sẽ đánh bại con rồng và được tăng thêm sức mạnh theo là yi.

• Kirito có thể chiến đấu với những con rồng theo bất kỳ thứ tự nào. Xác định xem liệu anh ta có thể chuyển sang cấp độ tiếp theo của trò chơi hay không, tức là đánh bại tất cả những con rồng mà không bị thua một lần nào.

Gợi ý : Đánh con rồng yếu hơn trước

Đầu vào
• Dòng đầu tiên chứa hai số nguyên được phân tách bằng dấu cách n và s (1 ≤ s ≤ 10^6, 1 ≤ n ≤ 10^5).

• Sau đó n dòng tiếp theo: dòng thứ i chứa các số nguyên được phân tách bằng dấu cách là xi và yi (1 ≤ xi ≤ 10^4, 0 ≤ yi ≤ 10^4) - sức mạnh của con rồng thứ i và sức mạnh được tăng thêm khi đánh bại nó.

Giới hạn
• 1 ≤ s ≤ 10^6, 1 ≤ n ≤ 10^5

• 1 ≤ xi ≤ 10^4, 0 ≤ yi ≤ 10^4

Đầu ra
Trên một dòng duy nhất in "YES" (không có dấu ngoặc kép), nếu Kirito có thể chuyển sang cấp độ tiếp theo và in "NO" (không có dấu ngoặc kép), nếu anh ta không thể.

Ví dụ :
Input 01
Copy
3 3
2 3
3 5
7 2
Output 01
Copy
YES

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp);
    ll sum = s;
    for(int i = 0; i < n; i++)
    {
        if(sum <= v[i].first)
        {
            cout << "NO";
            return 0;
        }else {
            sum += v[i].second;
        }
    }
    cout << "YES";
    return 0;
}

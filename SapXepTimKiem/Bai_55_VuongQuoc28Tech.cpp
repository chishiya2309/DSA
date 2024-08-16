/*
Tại Vương Quốc 28Tech có N cư dân, mỗi cư dân có một chiều cao . Vì yêu thích sự công bằng nên Quốc Vương của 28Tech muốn tất cả mọi người đều có phải có cùng chiều cao với nhau để tránh tình trạng body shaming giữa các cư dân.

Bây giờ Quốc Vương sẽ đi tìm 1 người bất kỳ mà ông ta thích trong N người đó và chọn làm hạt giống, người này và những người có cùng chiều cao với hạt giống kia thực sự may mắn bởi vì Quốc Vương có một ý tưởng thực sự rất đáng sợ. Ông ta sẽ cắt bớt chân của những người cao hơn người hạt giống hoặc kéo chân những người thấp hơn người hạt giống sao cho tất cả mọi người có cùng chiều cao với người hạt giống. Tuy nhiên ý tưởng của Quốc Vương bị phản đối bởi cư dân trong Vương Quốc của mình thành ra Quốc Vương phải đi tìm một hạt giống sao cho việc cắt bớt chân và kéo dài chân gây ít đau đớn nhất. Quốc Vương nhờ bạn tìm giúp hạt giống này !

Biết rằng khi chiều cao của 1 dân cư là X cao(thấp) hơn người hạt giống có chiều cao là Y thì sự đau đớn khi cắt (kéo dài) chân sẽ là |X - Y| (Đây là ý nghĩa của giá trị tuyệt đối).

Bạn hãy xác định xem với hạt giống tối ưu thì tổng sự đau đớn của mọi dân cư trong Vương Quốc 28Tech sẽ là bao nhiêu để tất cả mọi người có cùng chiều cao với người hạt giống đó.



Đầu vào
Dòng 1 là N : số lượng dân cư

Dòng 2 gồm N số là chiều cao của các cư dân

Giới hạn
Vương Quốc có không quá 1 triệu cư dân

Chiều cao của cư dân thuộc đoạn [1, 999999999]

Đầu ra
In ra tổng số đau đớn của mọi cư dân được coi là phương án tối ưu
Ví dụ :
Input 01
Copy
5
3 9 10 1 8
Output 01
Copy
15
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    a.resize(n);

    for(int &x : a)
    {
        cin >> x;
    }

    sort(a.begin(), a.end());
    ll median = a[n / 2];
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        res += abs(a[i] - median);
    }

    cout << res;

    return 0;
}
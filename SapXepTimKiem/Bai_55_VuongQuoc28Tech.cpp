/*
Tại Vương Quốc 28Tech có N cư dân, mỗi cư dân có một chiều cao . Vì yêu thích sự công bằng nên Quốc Vương của 28Tech muốn tất cả mọi người đều có phải có cùng chiều cao với nhau để tránh tình trạng body shaming giữa các cư dân.

Bây giờ Quốc Vương sẽ đi tìm 1 người bất kỳ mà ông ta thích trong N người đó và chọn làm hạt giống, người này và những người có cùng chiều cao với hạt giống kia thực sự may mắn bởi vì Quốc Vương có một ý tưởng thực sự rất đáng sợ. Ông ta sẽ cắt bớt chân của những người cao hơn người hạt giống hoặc kéo chân những người thấp hơn người hạt giống sao cho tất cả mọi người có cùng chiều cao với người hạt giống. Tuy nhiên ý tưởng của Quốc Vương bị phản đối bởi cư dân trong Vương Quốc của mình thành ra Quốc Vương phải đi tìm một hạt giống sao cho việc cắt bớt chân và kéo dài chân gây ít đau đớn nhất. Quốc Vương nhờ bạn tìm giúp hạt giống này !

Biết rằng khi chiều cao của 1 dân cư là X cao(thấp) hơn người hạt giống có chiều cao là Y thì sự đau đớn khi cắt (kéo dài) chân sẽ là |X - Y| (Đây là ý nghĩa của giá trị tuyệt đối).

Bạn hãy xác định xem với hạt giống tối ưu thì tổng sự đau đớn của mọi dân cư trong Vương Quốc 28Tech sẽ là bao nhiêu để tất cả mọi người có cùng chiều cao với người hạt giống đó.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int medium = a[n/2];
    long long res = 0;
    for(int i = 0; i < n; i++)
    {
        res += abs(medium - a[i]);
    }
    cout << res;
    return 0;
}
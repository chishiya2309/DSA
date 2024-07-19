/*
Tại Mai Lĩnh Resort, vào nửa đêm, cả trung đội nhận lệnh tập trung ở sân. Mỗi chiến sỹ được đánh số từ 1 đến N. Giám thị yêu cầu chọn ra một dãy K chiến sỹ để tập đội ngũ và cứ lần lượt duyệt hết tất cả các khả năng chọn K người như vậy từ nhỏ đến lớn (theo số thứ tự). Bài toán đặt ra là cho một nhóm K chiến sỹ hiện đang phải tập đội ngũ, hãy tính xem trong lượt chọn K người tiếp theo thì mấy người trong nhóm cũ sẽ được nghỉ. Nếu đã là nhóm cuối cùng thì tất cả đều được nghỉ

Gợi ý : Xét cấu hình tập con hiện tại và kế tiếp khác nhau bao nhiêu phần tử
Đầu vào
Dòng 1: hai số nguyên dương N và K

Dòng 2 ghi K số thứ tự của các chiến sỹ đang phải tập đội ngũ

Giới hạn
1<=K<=N<=1000

Đầu ra
In ra số lượng chiến sỹ được nghỉ

Ví dụ :
Input 01
8 3
4 6 7
Output 01
1
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    set<int> se;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }
    
    int i = k;
    while(i >= 1 && a[i] == n - k + i)
    {
        --i;
    }
    if(i == 0)
    {
        cout << k << endl;
    }else {
        a[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
        int dem = 0;
        for(int i = 1; i <= n; i++)
        {
            if(se.count(a[i]) == 0)
            {
                dem++;
            }
        }
        cout << dem;
    }
    return 0;
}
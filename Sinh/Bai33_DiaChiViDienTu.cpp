/*
28tech đang muốn phát triển đồng tiền điện tử là 28coin, anh ta cần tạo ra các địa chỉ ví để gửi và nhận đồng tiền này. Mỗi địa chỉ ví là sự kết hợp của hoán vị các chữ cái từ 'a' tới X với X là chữ cái in thường cho trước với các tổ hợp chập K của N phần tử các số nguyên từ 1 tới N.

Nhiệm vụ của bạn là hãy liệt kê tất cả các địa chỉ có thể có.

Đầu vào
Dòng duy nhất chứa 2 số N, K và kí tự X

Giới hạn
1<=K<=N<=15

Đầu ra
In ra các địa chỉ ví

Ví dụ :
Input 01
Copy
5 3 c
Output 01
Copy
abc123
abc124
abc125
abc134
abc135
abc145
abc234
abc235
abc245
abc345
acb123
acb124
acb125
acb134
acb135
acb145
acb234
acb235
acb245
acb345
bac123
bac124
bac125
bac134
bac135
bac145
bac234
bac235
bac245
bac345
bca123
bca124
bca125
bca134
bca135
bca145
bca234
bca235
bca245
bca345
cab123
cab124
cab125
cab134
cab135
cab145
cab234
cab235
cab245
cab345
cba123
cba124
cba125
cba134
cba135
cba145
cba234
cba235
cba245
cba345
*/

#include <bits/stdc++.h>

using namespace std;
vector<char> kitu;
vector<int> x;
int n, k;
char c;
bool final = false;
void khoitao()
{
    for(int i = 1; i <= n; i++)
    {
        x[i] = i;
    }
}
void sinh()
{
    int i = k;
    while(i >= 1 && x[i] == n - k + i)
    {
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        x[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            x[j] = x[j - 1] + 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    x.resize(k + 1);

    cin >> c;
    int dis = (int)c - 96;
    kitu.resize(dis);
    for(int i = 0; i < dis; i++)
    {
        kitu[i] = 'a' + i;
    }
    do
    {
        final = false;
        khoitao();
        while(!final)
        {
            for(int i = 0; i < dis; i++)
            {
                cout << kitu[i];
            }
            for(int i = 1; i <= k; i++)
            {
                cout << x[i];
            }
            cout << endl;
            sinh();
        }
    } while (next_permutation(kitu.begin(), kitu.end()));
    
    return 0;
}
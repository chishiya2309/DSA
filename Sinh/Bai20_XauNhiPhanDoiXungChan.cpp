/*
Nhiệm vụ của bạn là hãy liệt kê các xâu nhị phân thuận nghịch có độ dài chẵn theo thứ tự từ điển với chiều dài không quá n kí tự.

Gợi ý : Để sinh xâu nhị phân có độ dài chẵn đối xứng n bạn chỉ cần sinh xâu nhị phân có độ dài n / 2, lật ngược lại xâu và nối vào xâu ban đầu sẽ thu được xâu có độ dài chẵn mà đối xứng.

Đầu vào
Dòng duy nhất chứa số nguyên N.

Giới hạn
2<=N<=30

Đầu ra
In ra các xâu nhị phân đối xứng có độ dài chẵn theo thứ tự từ điển.

Ví dụ :
Input 01
4
Output 01
00
0000
0110
1001
11
1111
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
bool final = false;
void sinh()
{
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    if(i == -1)
    {
        final = true;
    }else 
    {
        s[i] = '1';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> v;
    int res = n/2;
    for(int i = 1; i <= res; i++)
    {
        s = string(i, '0');
        final = false;
        while(!final)
        {
            string t = s;
            reverse(t.begin(), t.end());
            v.push_back(t + s);
            sinh();
        }

    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}

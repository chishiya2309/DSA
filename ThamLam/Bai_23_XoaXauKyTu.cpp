/*
Tí vào Tèo cùng chơi một trò chơi với xâu nhị phân S. Xâu nhị phân S chỉ bao gồm các kí tự 0 và 1. Ở mỗi bước đi, 2 bạn nhỏ có thể chọn 1 xâu con liên tiếp các kí tự giống nhau ở xâu S và xóa nó khỏi xâu S. Sau khi xóa 1 xâu thì 2 xâu bên trái và phải của xâu vừa xóa sẽ trở thành liền kề. Ban đầu Tí là người đi trước, sau đó 2 bạn lần lượt thực hiện bước đi của mình cho tới khi xâu S trở thành xâu rỗng. Bạn hãy xác định xem Tí có thể xóa tối đa bao nhiêu kí tự 1 biết rằng cả 2 bạn đều chơi tối ưu

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
1<=len(S)<=100000

Đầu ra
In ra số lượng số 1 tối đa mà Tí có thể xóa được

Ví dụ :
Input 01
1000101110011111
Output 01
6
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    s += "0";

    vector<int> ans;
    int dem = 0;
    for(char c : s)
    {
        if(c == '1')
        {
            dem++;
        }else
        {
            if(dem != 0)
            {
                ans.push_back(dem);
                dem = 0;
            }
        }
    }

    int soKiTu = 0;
    sort(ans.begin(), ans.end(), greater<int>());
    for(int i = 0; i < ans.size(); i+=2)
    {
        soKiTu += ans[i];
    }
    cout << soKiTu;

    return 0;
}
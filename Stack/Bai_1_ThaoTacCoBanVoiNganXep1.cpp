/*
Cho một ngăn xếp các số nguyên. Các thao tác gồm 3 lệnh: push, pop và show.

Trong đó thao tác push kèm theo một giá trị cần thêm .

Hãy viết chương trình ghi ra kết quả của các lệnh show. Trong trường hợp lệnh pop thì ngăn xếp rỗng sẽ không được thực hiện

Đầu vào
Dòng đầu là số thao tác T

T dòng tiếp theo mỗi dòng chứa một lệnh push, pop hoặc show.

Giới hạn
1<=T<=100

Đầu ra
Ghi ra màn hình các phần tử đang có trong stack theo thứ tự lưu trữ mỗi khi gặp lệnh show.

Các số viết cách nhau đúng một khoảng trống. Nếu stack rỗng thì in ra EMPTY

Ví dụ :
Input 01
Copy
9
show
push 346
push 196
push 946
show
show
push 943
push 265
push 225
Output 01
Copy
EMPTY
346 196 946 
346 196 946
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    stack<int> s;
    while(t--)
    {
        string tmp;
        cin >> tmp;

        if(tmp == "show")
        {
            if(s.empty())
            {
                cout << "EMPTY\n";
            }else 
            {
                for(int i = 0; i < s.size(); i++)
                {
                    cout << s[i] << " ";
                }
            }
        }
    }

    return 0;
}
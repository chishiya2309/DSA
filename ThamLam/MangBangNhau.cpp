/*
28Tech định nghĩa 2 mảng bằng nhau là 2 mảng mà tích các phần tử trong 2 mảng này bằng nhau. Cho 2 mảng A[], B[] gồm N, M phần tử, bạn hãy xác định xem mảng A[], B[] có bằng nhau hay không, nếu có in 28tech, ngược lại in ra 29tech.

Gợi ý : Phân tích thừa số nguyên tố của N và M bằng các phần tích thừa số nguyên tố từng số trong mảng A[] và B[], sau đó so sánh số lần xuất hiện của từng chữ số nguyên tố của 2 số N và M, nếu tất cả các thừa số nguyên tố của N và M đều bằng nhau thì 2 mảng bằng nhau.
*/


#include <bits/stdc++.h>

using namespace std;
void phanTichThuaSoNguyenTo(int n, map<int, int> &mp)
{
    while(n % 2 == 0)
    {
        mp[2]++;
        n /= 2;
    }
    for(int i = 3; i<= sqrt(n); i+=2)
    {
        if(n % i  == 0)
        {
            mp[i]++;
            n /= i;
        }
    }
    if(n > 2)
    {
        mp[n]++;
    }
}
bool haiMangBangNhau(vector<int> &a, vector<int> &b)
{
    map<int, int> mpA, mpB;
    for(int num : a)
    {
        phanTichThuaSoNguyenTo(num, mpA);
    }
    for(int num : b)
    {
        phanTichThuaSoNguyenTo(num, mpB);
    }
    return mpA == mpB;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<m; i++)
    {
        cin >> b[i];
    }
    if(haiMangBangNhau(a, b))
    {
        cout << "28tech";
    }else {
        cout << "29tech";
    }
    return 0;
}
/*
Lê Quang Hưng
23110110
 */
int bs(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    int res = -1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] == x)
        {
            res = m;
            r = m - 1;
        }else if(a[m] > x)
        {
            l = m + 1;
        }else 
        {
            r = m - 1;
        }
    }
    return res;
}
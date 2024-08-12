#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    vector<int> left(a + l, a + m + 1);
    vector<int> right(a + m + 1, a + r + 1);
    int index = l, i = 0, j = 0;
    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
        {
            a[index] = left[i];
            index++;
            i++;
        }else {
            a[index] = right[j];
            index++;
            j++;
        }
    }

    while(i < left.size())
    {
        a[index] = left[i];
        index++;
        i++;
    }

    while(j < right.size())
    {
        a[index] = right[j];
        index++;
        j++;
    }
}

void mergesort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r ) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

signed main()
{
    int a[] = {3, 1, 2, 9, 8 , 5, 7, 6, 10,4};
    mergesort(a, 0, 9);
    for(int num : a)
    {
        cout << num << " ";
    }
}
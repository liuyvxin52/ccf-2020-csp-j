/*2.（最小区间覆盖）给出 n 个区间，第 i 个区间的左右端点是 [ai,bi]。
现在要在这些区间中选出若干个，使得区间 [0,m]被所选区间的并覆盖（即每一个 0≤i≤m都在某个所选的区间中）。
保证答案存在，求所选区间个数的最小值。
输入第一行包含两个整数 n和 m（1≤n≤5000,1≤m≤109）接下来 n行，每行两个整数 ai，bi（0≤ai,bi≤m）。
提示：使用贪心法解决这个问题。先用 O(n2)的时间复杂度排序，然后贪心选择这些区间。
试补全程序。
*/
#include <iostream>

using namespace std;

const int MAXN = 5000;
int n, m;

struct segment { int a, b; } A[MAXN];

void sort() // 排序
   {
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            if (/*1->*/A[j].a < A[j - 1].a/*<-1*/)
            {
                segment t = A[j];
                /*2->*/A[j] = A[j - 1]; A[j - 1] = t;/*<-2*/
            }
    }   

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> A[i].a >> A[i].b;
    sort();
    int p = 1;
    for (int i = 1; i < n; i++)
        if (/*3->*/A[i].b > A[p - 1].b/*<-3*/)
            A[p++] = A[i];
    n = p;
    int ans =0, r = 0;
    int q = 0;
    while (r < m)
    {
        while (/*4->*/q + 1 < n && A[q + 1].a <= r/*<-4*/)
        q++;
        /*5->*/r = max(r, A[q].b)/*<-5*/;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
/*
参考答案:
A[j].a < A[j - 1].a
A[j] = A[j - 1]; A[j - 1] = t;
A[i].b > A[p - 1].b
q + 1 < n && A[q + 1].a <= r
r = max(r, A[q].b)
*/
/*==================================
 Problem 719 : Using Suffix Array
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <bits/stdc++.h>
using namespace std;
#define clr(a,n) memset(a, 0, n * sizeof(*a))
#define cpy(d,s,n) memcpy(d, s, n * sizeof(*s))
/*--------------------------------------------------*/
 
int test, cas = 1;
const int SIZ = 20050;
 
int n; // text length
char T[SIZ]; // text string
int SA[SIZ], tempSA[SIZ]; // the sorted suffixes
int RA[SIZ], tempRA[SIZ]; // ranks of suffix array
int L[SIZ]; // used in counting sort
 
inline int getRA(int i)
{
    return (i < n) ? RA[i] : 0;
}
 
void radix_sort(int k)
{
    int mx = max(n, 130);
    clr(L, mx);
 
    // count frequencies
    for(int i = 0; i < n; ++i)
    {
        L[getRA(i + k)]++;
    }
    // save first index of every characters
    for(int i = 0, s = 0; i < mx; ++i)
    {
        int x = L[i];
        L[i] = s;
        s += x;
    }
    // build sorted tempSA
    for(int i = 0; i < n; ++i)
    {
        int& x = L[getRA(SA[i] + k)];
        tempSA[x++] = SA[i];
    }
    // copy tempSA to SA
    cpy(SA, tempSA, n);
}
// text must ends with a $
void buildSA()
{
    for(int i = 0; i < n; ++i)
    {
        SA[i] = i;
        RA[i] = T[i];
    }
    // algorithm loop
    for(int k = 1; k < n; k <<= 1)
    {
        // sort by k-th ranks
        radix_sort(k);
        radix_sort(0);
 
        // compute new ranks
        tempRA[SA[0]] = 0;
        for(int i = 1, r = 0; i < n; ++i)
        {
            if(getRA(SA[i-1]) != getRA(SA[i])
              || getRA(SA[i-1]+k) != getRA(SA[i]+k)) {
                r++;
            } 
            tempRA[SA[i]] = r;
        }
        cpy(RA, tempRA, n);
        if(RA[SA[n - 1]] == n - 1) break;
    }
}
 
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", T);
        int m = strlen(T);
 
        cpy(T + m, T, m);
        n = m << 1;
        T[n++] = '$';
        T[n] = 0;
 
        buildSA();
 
        int i = 0;
        while(i < n && n - SA[i] <= m) i++;
        printf("%d\n", SA[i] + 1);
    }
 
    return 0;
}

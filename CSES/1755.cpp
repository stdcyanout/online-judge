#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
//#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define putchar_unlocked putchar
//#define getchar_unlocked getchar

using namespace std;

int a[26];

inline void put(int c,int n)
{
    while(n--)
        putchar_unlocked(char(c+'A'));
}

int main()
{
    char c;
    int i,mid=-1;
    while(c=getchar_unlocked())
    {
        if(c!='\n')
            ++a[int(c-'A')];
        else
            break;
    }

    for(i=0;i<26;++i)
    {
        if(a[i]&1)
        {
            if(mid==-1)
            {
                mid=i;
                a[i]>>=1;
            }
            else
            {
                printf("NO SOLUTION");
                return 0;
            }
        }
        else
        {
            a[i]>>=1;
        }
    }

    for(i=0;i<26;++i)
    {
        put(i,a[i]);
    }

    if(mid!=-1)
        putchar_unlocked(char(mid+'A'));

    for(i=25;i>=0;--i)
    {
        put(i,a[i]);
    }
}

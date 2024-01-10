#include <bits/stdc++.h>

using namespace std;

int main()
{
    bitset<3> bit;
    string s[45]={""};
    int n,i,j;
    for(i=0;i<9;i++)
    {
        cin >> n;
        for(j=0;j<n;j++)
            cin >> s[i+j*9];
    }

    int score=0,b,bprime=0;
    cin >> b;
    for(i=0;b>bprime;i++)
    {
        if(s[i]=="SO"||s[i]=="FO"||s[i]=="GO")
        {
            bprime+=1;
            if(bprime%3==0)
                bit<<=4;
        }

        if(s[i]=="1B")
        {
            score+=bit[2];
            bit<<=1;
            bit[0]=1;
        }

        if(s[i]=="2B")
        {
            score+=bit[1]+bit[2];
            bit<<=2;
            bit[1]=1;
        }

        if(s[i]=="3B")
        {
            score+=bit[0]+bit[1]+bit[2];
            bit<<=3;
            bit[2]=1;
        }

        if(s[i]=="HR")
        {
            score+=bit[0]+bit[1]+bit[2]+1;
            bit<<=4;
        }
    }

    cout << score << endl;
}

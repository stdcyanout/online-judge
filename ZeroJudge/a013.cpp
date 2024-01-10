#include <bits/stdc++.h>

using namespace std;

int num(char c)
{
    if(c=='I')
        return 1;
    if(c=='V')
        return 5;
    if(c=='X')
        return 10;
    if(c=='L')
        return 50;
    if(c=='C')
        return 100;
    if(c=='D')
        return 500;
    if(c=='M')
        return 1000;

}

int main()
{
    string s[3]={""};
    while(cin >> s[0])
    {
        if(s[0]=="#")
            break;
        else
            cin >> s[1];
        int i;
        s[2]="";
        int n[3]={};
        int len[2]={s[0].length(),s[1].length()};

        for(i=0;i<len[0];i++)
        {
            if(i!=len[0]-1)
            {
                if(num(s[0][i+1])>num(s[0][i]))
                {
                    n[0]+=num(s[0][i+1])-num(s[0][i]);
                    i++;
                    continue;
                }
            }
            n[0]+=num(s[0][i]);
        }

        for(i=0;i<len[1];i++)
        {
            if(i!=len[1]-1)
            {
                if(num(s[1][i+1])>num(s[1][i]))
                {
                    n[1]+=num(s[1][i+1])-num(s[1][i]);
                    i++;
                    continue;
                }
            }
            n[1]+=num(s[1][i]);
        }

        n[2]=abs(n[0]-n[1]);
        if(n[2]==0)
            cout << "ZERO" << endl;
        else
        {
            while(n[2]>=1000)
            {
                s[2]+="M";
                n[2]-=1000;
            }

            while(n[2]>=900)
            {
                s[2]+="CM";
                n[2]-=900;
            }

            while(n[2]>=500)
            {
                s[2]+="D";
                n[2]-=500;
            }

            while(n[2]>=400)
            {
                s[2]+="CD";
                n[2]-=400;
            }

            while(n[2]>=100)
            {
                s[2]+="C";
                n[2]-=100;
            }

            while(n[2]>=90)
            {
                s[2]+="XC";
                n[2]-=90;
            }

            while(n[2]>=50)
            {
                s[2]+="L";
                n[2]-=50;
            }

            while(n[2]>=40)
            {
                s[2]+="XL";
                n[2]-=40;
            }

            while(n[2]>=10)
            {
                s[2]+="X";
                n[2]-=10;
            }

            while(n[2]>=9)
            {
                s[2]+="IX";
                n[2]-=9;
            }

            while(n[2]>=5)
            {
                s[2]+="V";
                n[2]-=5;
            }

            while(n[2]>=4)
            {
                s[2]+="IV";
                n[2]-=4;
            }

            while(n[2]>=1)
            {
                s[2]+="I";
                n[2]-=1;
            }

            cout << s[2] << endl;
        }
    }
}

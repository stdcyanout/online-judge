#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int solutions;

int row[]={0,0,0,0,0,0,0,0,0,
           1,1,1,1,1,1,1,1,1,
           2,2,2,2,2,2,2,2,2,
           3,3,3,3,3,3,3,3,3,
           4,4,4,4,4,4,4,4,4,
           5,5,5,5,5,5,5,5,5,
           6,6,6,6,6,6,6,6,6,
           7,7,7,7,7,7,7,7,7,
           8,8,8,8,8,8,8,8,8};

int column[]={9,10,11,12,13,14,15,16,17,
              9,10,11,12,13,14,15,16,17,
              9,10,11,12,13,14,15,16,17,
              9,10,11,12,13,14,15,16,17,
              9,10,11,12,13,14,15,16,17,
              9,10,11,12,13,14,15,16,17,
              9,10,11,12,13,14,15,16,17,
              9,10,11,12,13,14,15,16,17,
              9,10,11,12,13,14,15,16,17};

int block[]={18,18,18,19,19,19,20,20,20,
             18,18,18,19,19,19,20,20,20,
             18,18,18,19,19,19,20,20,20,
             21,21,21,22,22,22,23,23,23,
             21,21,21,22,22,22,23,23,23,
             21,21,21,22,22,22,23,23,23,
             24,24,24,25,25,25,26,26,26,
             24,24,24,25,25,25,26,26,26,
             24,24,24,25,25,25,26,26,26};

bitset<10> setted[27];
int num[81];

void solve(int i)
{
    int j,k;
    if(i==81)
    {
        ++solutions;
        for(j=0;j<9;j++)
        {
            for(k=0;k<9;k++)
            {
                cout << num[9*j+k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
    if(!num[i])
    {
        for(j=1;j<=9;j++)
        {
            if(!(setted[row[i]][j] || setted[column[i]][j] || setted[block[i]][j]))
            {
                num[i]=j;
                setted[row[i]][j]=setted[column[i]][j]=setted[block[i]][j]=1;
                solve(i+1);
                num[i]=0;
                setted[row[i]][j]=setted[column[i]][j]=setted[block[i]][j]=0;
            }
        }
    }
    else
    {
        solve(i+1);
    }
}

int main()
{
    fastIO
    int n,i,j;
    for(i=0;i<81;i++)
    {
        cin >> num[i];
        setted[row[i]][num[i]]=setted[column[i]][num[i]]=setted[block[i]][num[i]]=1;
    }
    solve(0);
    cout << "there are a total of " << solutions << " solution(s).\n";
}
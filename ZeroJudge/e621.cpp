#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int n,a,b,c,i;
	bool no;
	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c;
		no=1;
		for(a++;a<b;a++)
		{
			if(a%c)
			{
				cout << a << " ";
				no=0;
			}
		}
		if(no)
			cout << "No free parking spaces.";
		cout << "\n";
	}
}

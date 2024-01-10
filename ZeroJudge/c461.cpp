#include <iostream>

using namespace std;

int main()
{
    int a,b,c,im=1;
    cin >> a >> b >> c;
    if((a&&b)==c)
    {
        cout << "AND" << endl;
        im=0;
    }

    if((a||b)==c)
    {
        cout << "OR" << endl;
        im=0;
    }

    if(((a||b)&&(!(a&&b)))==c)
    {
        cout << "XOR" << endl;
        im=0;
    }

    if(im)
        cout << "IMPOSSIBLE" << endl;
}

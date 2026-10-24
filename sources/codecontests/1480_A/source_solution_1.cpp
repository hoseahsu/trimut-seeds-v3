#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int t = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (t == 1)
            {
                t = 0;
                if (s[i] == 'a')
                {
                    s[i] = 'b';
                }
                else
                {
                    s[i] = 'a';
                }
            }
            else
            {
                t = 1;
                if (s[i] == 'z')
                {
                    s[i] = 'y';
                }
                else
                {
                    s[i] = 'z';
                }
            }
        }
        cout << s << endl;
    }
}
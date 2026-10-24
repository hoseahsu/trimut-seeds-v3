#include<iostream>
using namespace std;

int main()
{
    int h1, w1, h2, w2;

    cin >> h1 >> w1;
    
    int a[h1][w1];
    for( int i = 0; i < h1; i++ )
        for( int j = 0; j < w1; j++ )
            cin >> a[i][j];

    bool b[h1][w1];
    for( int i = 0; i < h1; i++ )
        for( int j = 0; j < w1; j++ )
            cin >> b[i][j];

    cin >> h2 >> w2;

    bool c[h2][w2];
    for( int i = 0; i < h2; i++ )
        for( int j = 0; j < w2; j++ )
            cin >> c[i][j];

    int res = -1000000000;
    bool judge = false;
    for( int i = 0; i <= h1 - h2; i++ )
        for( int j = 0; j <= w1 - w2; j++ )
        {
            int sum = 0;
            bool issame = true;
            for( int k = i; k < i + h2; k++ )
            {
                for( int l = j; l < j + w2; l++ )
                {
                    if( b[k][l] != c[k-i][l-j] )
                    {
                        issame = false;
                        break;
                    }
                    else
                        sum += a[k][l];
                }
                if( !issame )
                    break;
            }
            if( issame && res < sum )
            {
                judge = true;
                res = sum;
            }
        }

    if( !judge )
        cout << "NA" << endl;
    if( judge )
        cout << res << endl;
    
    return 0;
}

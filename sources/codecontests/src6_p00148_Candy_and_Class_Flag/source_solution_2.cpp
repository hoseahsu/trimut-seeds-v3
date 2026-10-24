#include <cstdio>

using namespace std;

int main()
{
    int n;
    while( scanf ( "%d\n", &n ) != EOF )
    {
        if( n % 39 == 0 && n != 0 )
        {
            printf( "3C39\n" );
        }
        else
        {
            printf( "3C%02d\n", n % 39 );

        }
    }
    return 0;
}

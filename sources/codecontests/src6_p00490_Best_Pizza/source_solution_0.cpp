#include<algorithm>
#include<functional>
#include<iostream>

int N;
int A, B, C;
int D[100];

int main()
{
	std::cin >> N >> A >> B >> C;
	for( int i = 0; i != N; ++i )
		std::cin >> D[i];

	std::sort( D, D + N, std::greater<int>() );

	int sum = 0, ans = 0;
	for( int i = 0; i != N; ++i )
	{
		sum += D[i];
		ans = std::max( ans, ( C + sum ) / ( A + ( i + 1 ) * B ) );
	}

	std::cout << ans << std::endl;

	return 0;
}
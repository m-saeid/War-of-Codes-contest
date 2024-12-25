#include <iostream>
using namespace std;

int sum_digits(int n)
{
	int s = 0;
	while(n!=0)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main()
{
	int m, n, c=0;
	cin >> m;
	cin >> n;
	for(int i = m ; i <=n ; i++)
		if(i % sum_digits(i) == 0)
			c++;
	cout << c;
}
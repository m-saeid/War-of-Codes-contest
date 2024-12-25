#include <iostream>
using namespace std;
int main()
{
	int n, k, c=0;
	cin  >> n;
	int list[n];
	for(int i = 0; i < n; i++)
		cin >> list[i];
	cin >> k;
	for(int i = 0; i<n-1; i++)
		for(int j = i + 1; j < n; j++)
			if(list[i] + list[j] == k)
				c++;
	cout << c;
}
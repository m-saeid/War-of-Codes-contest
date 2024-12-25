#include <iostream>

using namespace std;
int main()
{
	char s[100];
	int key, i = -1;
	cin >> key;
	cin >> s;
	while(s[++i] != '\0')
	{
		s[i] -= key;
		if(s[i] < 'a')
			s[i] += 'z' - 'a' + 1;
		if(s[i] >'z')
			s[i] += 'a' - 'z' - 1;
	}
	cout << s;
}
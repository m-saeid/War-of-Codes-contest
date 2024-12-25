#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void sum_key(vector<string> &arr, int tedad, string key)
{
	int l, count;
	string s,n;
	for(int k = 0; k < tedad; k++)
	{
		n="";
		s = arr[k];
		l = s.length();
		count = 0;
		for(int i = 0; i < l; i++)
		{	
			if(s.at(i) == ' ' || s.at(i) == ',' || s.at(i) == '.') 
			{
				if(n == "")continue;
				if(n == key)
					count++;
				n = "";
			}
			else
				n += s.at(i);
		}
		if(n != "" && n==key)
			count++;
		cout << count << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<string> arr(n);
	string s, key;
	cin.ignore();
	for(int i =0; i<n; i++)
	{
		getline(cin, arr[i]);
	}
	getline(cin, key);
	sum_key(arr, n, key);
}
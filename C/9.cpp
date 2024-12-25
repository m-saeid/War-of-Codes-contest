#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int read(int arr[])
{
	int l, max = 0;
	string s,n="";
	getline(cin, s);
	l = s.length();
	for(int i = 0; i<l; i++)
	{	
		if(s.at(i) == ' ')
		{
			if(n == "")continue;
			arr[max++] = stoi(n);
			n = "";
		}
		else
			n += s.at(i);
	}
	if(n != "")	arr[max++] = stoi(n);
	return max;
}

int sum(int arr[], int origin,int max, int tedad)
{
	int s = 0;
	int idx = origin;
	for(int i = 0; i < tedad; i++)
	{
		s += arr[idx++];
		if(idx >= max)
			idx = 0;
	}
	return s;
}

int main()
{
	int arr[100], max = INT_MIN, tedad;
//	int o_max, t_max ;
	tedad = read(arr);
	for(int origin = 0; origin < tedad; origin++)
	{
		for(int t = 1; t <= tedad; t++)
		{	
			int s = sum(arr, origin, tedad, t);
			if(s > max)
			{
				max = s;
//				o_max = origin;
//				t_max = t;
			}
		}			
	}
	
//	for(int i = 0, j = o_max; i < t_max; i++, j++)
//	{
//		if(j > tedad-1)j=0;
//		cout << j << '-' << arr[j] << "  ";
//	}
//	cout << endl << max;
	cout << max;
}
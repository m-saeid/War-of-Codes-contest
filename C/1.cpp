#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	string str;
	float avg;
	string max_name="";
	float max_avg = -1;
	
	cin>>t;
	
	for(int i = 0; i<t; i++)
	{
		cin >> str >> avg;
		if(avg > max_avg)
		{
			max_avg = avg;
			max_name = str;
		}
	}
	cout<<max_name;	
}
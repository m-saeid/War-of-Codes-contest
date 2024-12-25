#include <iostream>
#include <string>
using namespace std;

long min_del(long num, int k)
{
	if(k == 0)
		return num;
	string snum = to_string(num);
	string d_num = snum;
	int l = snum.size();
	long min = stol(d_num.erase(0, 1));
	for(int i = 1; i<l;i++)
	{
		d_num = snum;
		if(stol(d_num.erase(i, 1)) < min)
			min = stol(d_num);
	}
	long res = min_del(min, k-1);	
	return res;
}

int main()
{
	int n, k;
	long num;
	cin >> n >> k;
	cin >> num;
	cout << min_del(num, k);
}
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void combineUtil(vector<int>& arr, vector<int>& data, int start, int end, int index, int r, vector<vector<int>>& result)
{
    if (index == r)
	{
        result.push_back(data);
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
	{
        data[index] = arr[i];
        combineUtil(arr, data, i + 1, end, index + 1, r, result);
    }
}

vector<vector<int>> getCombinations(vector<int>& arr, int r)
{
    vector<vector<int>> result;
    vector<int> data(r);
	combineUtil(arr, data, 0, arr.size() - 1, 0, r, result);
    return result;
}

int sum(vector<int>& arr)
{
	int s = 0;
	for(int item : arr)
		s += item;
	return s;
}

int basket(vector<int>& arr,int limit, int r, int t)
{
	if(r > arr.size() || sum(arr) < limit)
		return t;
    vector<vector<int>> comb = getCombinations(arr, r);
    int min = INT_MAX;
    int min_idx = 0;
    for(int i = 0; i < comb.size(); i++)
		if(sum(comb[i]) >= limit && sum(comb[i]) < min)
		{
			min = sum(comb[i]);
			min_idx = i;
		}
	if(min != INT_MAX)
	{
        t++;
        for(int i : comb[min_idx])
        	arr.erase(find(arr.begin(), arr.end(), i));
        t = basket(arr, limit, r, t);
    }
    t= basket(arr, limit, r+1, t);
    return t;
}

int main()
{
	int tedad, item, limit;
	cin >> tedad;
    vector<int> data(tedad);
    for(int i = 0; i < tedad; i++)
    {
    	cin >> item;
    	data.push_back(item);
	}
	cin >> limit;
	cout << basket(data, limit, 1, 0);
    return 0;
}


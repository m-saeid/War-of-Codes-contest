#include <iostream>
using namespace std;

int max_cards(int arr[], int s, int n)
{
	int max_num = 0;
	int subset = 2 << n;
	for(int i = 1; i < subset; i++)
	{
		int sum = 0;
		int num = 0;
		for(int bit = 0; bit <n; bit++)	
			if(i & 1 << bit)
			{
				sum += arr[bit];
				num ++;
			}
		if(sum == s && num > max_num)
			max_num = num;
	}
	return max_num;
}

int main()
{
	int floor_cards[20];
	int hand_card, num;
	
	cin >> hand_card;
	cin >> num;
	for(int i = 0; i<num; i++)
		cin >> floor_cards[i];
	cout << max_cards(floor_cards, 11-hand_card, num) << endl;
}

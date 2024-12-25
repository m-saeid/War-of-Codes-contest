#include <iostream>
#include <climits>
using namespace std;

int table[100][100]={{0}};

enum side{DOWN, LEFT, RIGHT, UP};

class cordinate{
	public:
		int n;
		int row;
		int col;
		
		cordinate(int y = 0, int x = 0, int t =5)
		{
			row = y;
			col = x;
			n = t;
		}
		bool move_up()
		{
			if(row > 0 && table[row-1][col]==0)
			{
				row--;
				return true;
			}
			return false;
		}
		bool move_down()
		{
			if(row < n-1 && table[row+1][col]==0)
			{
				row++;
				return true;
			}
			return false;
		}
		bool move_right()
		{
			if(col < n-1 && table[row][col+1]==0)
			{
				col++;
				return true;
			}
			return false;
		}
		bool move_left()
		{
			if(col > 0 && table[row][col-1]==0)
			{
				col--;
				return true;
			}
			return false;
		}
};	
		  
int move(cordinate current, side before_side, int num_moves)
{
	int m1 = INT_MAX, m2 = INT_MAX, m3 = INT_MAX;
	if(current.row == current.n -1)
		return num_moves;
	num_moves++;
	if(current.move_down())
	{	
		m1 = move(current, UP, num_moves);	
		current.move_up();
	}
	if(before_side != LEFT)
		if(current.move_left())
		{	
			m2 = move(current, RIGHT, num_moves);
			current.move_right();
		}
		
	if(before_side != RIGHT)
		if(current.move_right())
		{	
			m3 = move(current, LEFT, num_moves);
			current.move_left();
		}
	return m1<m2 && m1<m3 ? m1 : (m2<m3 ? m2 : m3);
} 

int main()
{
	int n, m;
	cin >> n >> m;
	cordinate start(0, m, n);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> table[i][j];
	
	int min = move(start, UP, 0);
	cout<<(min==INT_MAX ? -1 : min);
}
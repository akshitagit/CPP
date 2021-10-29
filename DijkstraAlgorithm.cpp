//Dijkstra-s-Algorithm in C++
//Write by Abdullah Sheikh (github.com/Abdullah-sheikh)
//email: abdullahsh123@hotmail.com 
//If you feel anything missing Please upgrade 

#include <iostream>
using namespace std;

struct node
{
	int index;
	int cost;
	node()
	{
		index = 0;
		cost = 999999;
	}
};
int arr[5][5] = { {0,2,3,0,0}
			   ,{2,0,15,2,0}
			   ,{3,15,0,0,13}
			   ,{0,2,0,0,9}
			   ,{0,0,13,9,0}};
class adjancey_matric
{
private:
	node NODE[5];
public:
	adjancey_matric()
	{
		for (int i = 0; i < 5; i++)
		{
			NODE[i].index = i;
		}
	}
	void apply_algorthim()
	{
		NODE[0].cost = 0; // beacuse it is our starting point
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (NODE[j].cost > arr[i][j]&& arr[i][j]!=0)
				{
					NODE[j].cost = arr[i][j];

					NODE[j].cost = NODE[j].cost + NODE[i].cost;
				}
			}
		}
	}
	void dispaly_cost()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "The cost of  " << i << "  is  : " << NODE[i].cost << endl;
		}
	}
};
int main()
{
	adjancey_matric obj;
	cout << "\t\tFinding minimum cost of Each Node " << endl << endl;
	obj.apply_algorthim();
	obj.dispaly_cost();
	system("pause");
}

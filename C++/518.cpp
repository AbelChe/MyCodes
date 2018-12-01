#include <iostream>

using namespace std;

int main()
{
	int Array_1[100];
	int Array_2[5];
	int Num = 0;
	int Low = 0;
	int Mid = 0;
	int High = 0;
	int i = 0;
	int j = 0;
	
	cin >> Num;
	
	for (i=1; i<=Num; i++)
	{
		cin >> Array_1[i];
	}
	
	for (j=0; j<3; j++)
	{ 
		cin >> Array_2[j];
	}
	
	for (j=0; j<3; j++)
	{
		Low = 1;
		High = Num;
		
		while (Low <= High)
		{
			Mid = (Low + High) / 2;
			
			if (Array_2[j] < Array_1[Mid])
			{
				cout << Low << " " << Mid << " " << High << " " << Array_1[Mid] << endl;
				
				High = Mid - 1;
			}
			else if (Array_2[j] > Array_1[Mid])
			{
				cout << Low << " " << Mid << " " << High << " " << Array_1[Mid] << endl;
				
				Low = Mid + 1;
			}
			else
			{
				break;
			}
		}
		
		if (Array_2[j] != Array_1[Mid])
		{
			cout << "0" << endl;
		}
		
		if (Array_2[j] == Array_1[Mid])
		{
			cout << Low << " " << Mid << " " << High << " " << Array_1[Mid] << endl;
			cout << Mid << endl;
		}
	}
	
	return 0;
}

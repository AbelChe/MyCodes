#include <iostream>

using namespace std;

int Sequential_Search (int array[],int n);

int main()
{
	int Num = 0;
	int Array[100];
	int i = 0;
	int j = 0;
	
	cin >> Num;
	
	for(i=1; i<=Num; i++)
	{
		cin >> Array[i];
	}

	for (j=3; j>0; j--)
	{
		cin >> Array[0];
		
		cout << Sequential_Search (Array, Num) << endl;
	}
	
	return 0;
}

int Sequential_Search (int array[], int n)
{
	while (array[n] != array[0])
	{
		cout << array[n--] << " ";
	}
	
	cout << endl;
	
	return n;
}

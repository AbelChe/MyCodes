#include <iostream>
#include <string>

using namespace std;

const int Maxsize = 10000;

class Mumber_Data
{
	public:
		Mumber_Data ();
		~Mumber_Data ();
		int GetMumber_Data ();
		bool IsEmpty ();
		void SetMumber_Data (int Data);
	
	private:
		int Data;
		bool Empty;
};

class Mumber_Hash
{
	public:
		Mumber_Hash () {}
		~Mumber_Hash () {}
		void SetLength (int Length) { this->Length = Length; }
		void SetMod (int Mod) { this->Mod = Mod; }
		int Get (int Data);
		void Insert (int Data);
		bool IsFull ();
	
	private:
		int GetIndex (int Data);
		int Length;
		int Mod;
		Mumber_Data Data[Maxsize];
};

Mumber_Data::Mumber_Data ()
{
	Empty = true;
}

Mumber_Data::~Mumber_Data ()
{
	
}

int Mumber_Data::GetMumber_Data ()
{ 
	return Data;
}

bool Mumber_Data::IsEmpty ()
{
	return Empty;
}

void Mumber_Data::SetMumber_Data (int Data)
{
	this->Data = Data;
	
	Empty = false;
}



int Mumber_Hash::GetIndex (int Data)
{
	return Data % Length;
}

void Mumber_Hash::Insert (int Data)
{
	int i = 0;
	int begin = 0;
	
	i = GetIndex (Data);
	
	begin = i;
	
	while ((!this->Data[i].IsEmpty ()) && (this->Data[i].GetMumber_Data () != Data))
	{
		if ((i = GetIndex (i + 1)) == begin)
		{
			return;
		}
	}
	
	this->Data[i].SetMumber_Data (Data);
}

int Mumber_Hash::Get (int Data)
{
	int i = 0;
	int begin = 0;
	
	i = GetIndex (Data);
	
	begin = i;
	
	while ((!this->Data[i].IsEmpty ()) && (this->Data[i].GetMumber_Data () != Data))
	{
		if ((i = GetIndex (i + 1)) == begin)
		{
			throw string ("full");
		}
	}
	
	if (this->Data[i].IsEmpty ())
	{
		this->Data[i].SetMumber_Data (Data);
		
		throw string ("none");
	}
	else
	{
		return i;
	}
}

int main ()
{
	Mumber_Hash Hash;
	
	int Length = 0;
	int Mod = 0;
	int Num = 0;
	int Temp = 0;
	int i = 0;
	int j = 0;
	
	cin >> Length;
	
	Hash.SetLength (Length);
	
	cin >> Mod;
	
	Hash.SetMod (Mod);
	
	cin >> Num;
	
	for (i=0; i<Num; i++)
	{
		cin >> Temp;
		
		Hash.Insert (Temp);
	}
	
	for (j=0; j<3; j++)
	{
		try
		{
			cin >> Temp;
			
			cout << Hash.Get (Temp) << endl;
		}
		catch (string &e)
		{
			cout << e << endl;
		}
	}

	return 0;
} 

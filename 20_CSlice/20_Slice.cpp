#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>

using namespace std;

class CSlice {  
private:
		int *Array;
		int lenth_array;
public:
		int Start_Index;
    	int Stop_Index;
    	int Step;
		int Sign;
    	int lenth_slice;

	CSlice (int lenth1, int lenth2, int *a): lenth_array(lenth1), lenth_slice(lenth2), Array(a)   
	{
		Array = a;
		Start_Index = 0;
		Stop_Index = lenth_array - 1;
		Step = 1;
		Sign = 1;
	};
	
	~CSlice()
	{
		delete[] Array;
	};

	void parser(string s)
	{
		int i = 0;
		string String = "";

	    if (s[i] == '[')
		{
		    i++;
			if(s[i] == '-')
		    {
			    Sign = -1;
				i++;
			} 
			else Sign = 1;

			while (isdigit(s[i]))                                               
		    {
			    String += s[i];
				i++;
				if (s[i] == ':' || s[i] == ']')
				Start_Index = stoi(String) * Sign;
			}
		}

		String = "";

		if (s[i] == ':')                                                        
		{
			i++;
			if(s[i] == '-')
			{
				Sign = -1;
			  	i++;
		    }
			else Sign = 1;

			while (isdigit(s[i]))
			{
			    String += s[i];
				i++;
				if (s[i] == ':' || s[i] == ']')
				Stop_Index = stoi(String) * Sign;
			}
		}
		
		String = "";

		if (s[i] == ':')                                                        
		{
			i++;
			if(s[i] == '-')
			{
				Sign = -1;
				i++;
			} 
			else Sign = 1;

			while (isdigit(s[i]))
			{
				String += s[i];
			    i++;
			    if (s[i] == ']')
			     	Step = stoi(String) * Sign;
			}
		}
	}

	void print(string s)
	{
		if (s[0] != '[' || s[lenth_slice-1] != ']')
		{
			cout << "Incorrect input_1\n";
			system ("pause");
			exit(0);
		}
		int i;
		for (i = 1; i < lenth_slice - 1; i++)
		{
			if (s[i] != '-' && s[i] != ':' && ! isdigit(s[i]))
			{
				cout << "Incorrect input_2\n";
				system ("pause");
				exit(0);
			}
		}

			if(Start_Index >= 0 && Stop_Index >=0  && Step < 0)
			{
				if (Start_Index == 0 && Stop_Index == lenth_array - 1)
				{
					for(int i = Stop_Index; i >= Start_Index; i -= abs(Step))
						cout << Array[i] << " ";
				}
				else
				{
					for(int i = Start_Index; i >= Stop_Index + 1 ; i -= abs(Step))
						cout << Array[i] << " ";
						
				}
				cout << '\n';
				system ("pause");
				exit(0);
			}

			if(Start_Index >= 0 && Stop_Index >= 0 && Step > 0)			
			{
				for(int i = Start_Index; i <= Stop_Index - 1 ; i += Step)
					cout << Array[i] << " ";
				cout << '\n';
				system ("pause");
				exit(0);
			}

			if(Start_Index >= 0 && Stop_Index <= 0 && Step > 0)			
			{
				for(int i = Start_Index; i <= lenth_array - abs(Stop_Index) - 1; i += Step)
					cout << Array[i] << " ";
				cout << '\n';
				system ("pause");
				exit(0);
				
			}

			if(Start_Index >= 0 && Stop_Index <= 0 && Step < 0)			
			{
				for(int i = Start_Index; i >= lenth_array - abs(Stop_Index) + 1; i -= abs(Step))
					cout << Array[i] << " ";
				cout << '\n';
				system ("pause");
				exit(0);
			}
        
			if(Start_Index <= 0 && Stop_Index >= 0 && Step > 0)			
			{
				for(int i = lenth_array - abs(Start_Index); i <= Stop_Index - 1; i += Step)
					cout << Array[i] << " ";
				cout << '\n';
				system ("pause");
				exit(0);	
			}
        
			if(Start_Index <= 0 && Stop_Index >= 0 && Step < 0)				
			{
				for(int i = lenth_array - abs(Start_Index); i >= Stop_Index + 1; i -= abs(Step))
					cout << Array[i] << " ";
				cout << '\n';
				system ("pause");
				exit(0);	
			}	

			if(Start_Index <= 0 && Stop_Index <= 0 && Step < 0)						
			{
				for(int i = lenth_array - abs(Start_Index); i >= lenth_array - abs(Stop_Index) + 1; i -= abs(Step))
					cout << Array[i] << " ";
				cout << '\n';
				system ("pause");
				exit(0);	
			}
        
			if(Start_Index <= 0 && Stop_Index <= 0 && Step > 0)						
			{
				for(int i = lenth_array - abs(Start_Index); i <= lenth_array - abs(Stop_Index)- 1; i += Step)
					cout << Array[i] << " ";
				cout << '\n';
				system ("pause");
				exit(0);	
			}
	}
};


int main()
{
	int N, i, lenth, *a = new int;

	cout << "Enter the number of elements in the array: ";
	cin >> N;

	cout << "Enter array intrger elements separated by space: ";
	for (i = 0 ; i < N ; i++)
         cin >> a[i];
 
	cout << "Enter the lenth of slice including brackets and colons: ";
	cin >> lenth;
	cin.ignore(32767, '\n');

    string slice;
	cout << "Enter the slice: ";
    getline(cin, slice);
    
	CSlice ar(N, lenth, a);
    ar.parser(slice);
	ar.print(slice);

	system ("pause");
	return 0;
}
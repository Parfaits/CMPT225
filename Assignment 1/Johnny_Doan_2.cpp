#include <iostream>

using namespace std;

char flag;

unsigned int Inputs(unsigned int A[])
{
	int i=0;
	cout << "Enter C for character entries. Enter I for integer entries." << endl;
	cin >> flag;
	char temp;
		// ctrl+d to indicate EOF
	if(flag=='I')
	{
		cout << "Enter positive int." << endl;
		while(i<10 && cin >> A[i])
		{
			if(i==8)
			{
				cout << "One more entry remaining." << endl;
			}
			i++;
		}
	} else if(flag=='C')
	{
		cout << "Enter character." << endl;
		while(i<10 && (cin >> temp))
		{
			// ASCII
			unsigned int convert = temp;
			A[i] = convert;
			if(i==8)
			{
				cout << "One more entry remaining." << endl;
			}
			i++;
		}
	}
	
	cout << "Maximum entries reached. Sorting..." << endl;
	return i;
}

void InsertionSort(unsigned int A[], unsigned int size)
{
	for(unsigned int i=1; i<size; i++)
	{
		unsigned int cur = A[i];
		int j = i-1;
		while(j>=0 && A[j]>cur)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = cur;
	}
}

int main(int argc, char const *argv[])
{
	unsigned int* arr;
	//unsigned char* C;
	arr = new unsigned int [10];
	//C = new unsigned char [10];
	unsigned int size = Inputs(arr);
	InsertionSort(arr, size);
	if(flag=='I')
	{
		for (unsigned int i = 0; i < size; ++i)
		{
			cout << arr[i] << endl;
		}
	} else if(flag=='C')
	{
		for (unsigned int i = 0; i < size; ++i)
		{
			cout << (char) arr[i] << endl;
		}	
	}
	return 0;
}
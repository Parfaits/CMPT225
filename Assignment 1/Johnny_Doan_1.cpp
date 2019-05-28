#include <iostream>

using namespace std;

unsigned int Inputs(unsigned int A[])
{
	int i=0;
	cout << "Enter a positive int." << endl;
	// ctrl+d to indicate EOF
	while(i<10 && cin >> A[i])
	{
		if(i==8)
		{
			cout << "One more entry remaining." << endl;
		}
		i++;
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
	arr = new unsigned int [10];
	unsigned int size = Inputs(arr);
	InsertionSort(arr, size);
	for (unsigned int i = 0; i < size; ++i)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
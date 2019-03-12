//2014312971 ÀÌ¿µ°Ç
#define NUM   10000
#define MAX_SIZE   10000


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;

void InsertionSort(Data* list, int n);
void Merge(Data* list, int left, int mid, int right);
void MergeSort(Data* list, int left, int right);
int HexToDec(char c);
void StringToArray(char* str);

int arr[50];
int main(void)
{
	int selection, i;
	char s[1000];
	scanf("%d", &selection);							//clear buffer
	scanf(" %[^\n]s", s);					//get input as string, including space using [^\n]s
	StringToArray(s);

	if (selection == 1)
		InsertionSort(arr,50);

	else if (selection == 2)
		MergeSort(arr,0,50);

	for (i = 50; i >0; i--)
		if(arr[i]!=0)
			printf("%0.4X ", arr[i]);			//print the sorted array in reverse order
}





void StringToArray(char* str)
{
	int idx=0;
	int len = strlen(str);										//calculate the length of input
	for (int i = 0; i < len; i++)
		if (str[i] != 32) {										//if str[i] is not 32 ; 32 is space for ASCII code.
			arr[idx] = HexToDec(str[i]) * 16 * 16 * 16;			//calculate decimal * 16^n to make hexadecimal.
			arr[idx] += HexToDec(str[++i]) * 16 * 16;
			arr[idx] += HexToDec(str[++i]) * 16;
			arr[idx] += HexToDec(str[++i]);	
			idx++;												//add all the members and move the cursor of 'arr'
		}
}









int HexToDec(char c)				//return decimal value according to hexadecimal value using switch function.
{
		switch (c)
		{
		case 'A':
		{
			return 10;
			break;
		}
		case 'B':
		{
			return 11;
			break;
		}
		case 'C':
		{
			return 12;
			break;
		}
		case 'D':
		{
			return 13;
			break;
		}
		case 'E':
		{
			return 14;
			break;
		}
		case 'F':
		{
			return 15;
			break;
		}

		default:
			return c-48;												//since 0 is 48 for ASCII code, -48 for all value.(same for - '0')
			break;
		}
}


//Sorting codes are refered from the material of data structure.


void InsertionSort(Data* list, int n)
{
	int j, key;
	for (int i = 1; i < n; i++)
	{
		key = list[i];// Choose the i-th element.
		for (j = i - 1; j >= 0; j--) {
			// If the j-th element is greater than key,
			// move to the next position.

			if (key < list[j])
			{
				list[j + 1] = list[j];
			}
			else
				break;
		}
		// Otherwise, move the key to the (j+1)-th element.
		list[j + 1] = key;
	}
}


//Merge
void MergeSort(Data* list, int left, int right)
{
	if (left < right)
	{

		int mid = (left + right) / 2;    // Equal partitioning
		MergeSort(list, left, mid);      // Sorting sublists
		MergeSort(list, mid + 1, right);   // Sorting sublists
		Merge(list, left, mid, right);   // Merging two sublists
	}
}


void Merge(Data* list, int left, int mid, int right)
{
	int sorted[MAX_SIZE];
	int first = left, second = mid + 1, i = left;

	// Merge two lists by comparing elements in sequence.
	while (first <= mid && second <= right) {



		if (list[first] <= list[second])
			sorted[i++] = list[first++];
		else
			sorted[i++] = list[second++];
	}

	// For remaining items, add them in sequence.


	if (first > mid)
		for (int j = second; j <= right; j++)
			sorted[i++] = list[j];
	else
		for (int j = first; j <= mid; j++)
			sorted[i++] = list[j];

	// Copy the sorted list to the list.
	for (int j = left; j <= right; j++)
	{


		list[j] = sorted[j];
	}
}



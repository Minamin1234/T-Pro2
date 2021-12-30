#include <iostream>
#include <random>

using namespace std;

#define ARYLOOP for(int i = 0;i < n;i++){
#define END }
#define SPRT cout << "--------------------" << endl;

void SetRandInt(int nums[], int n, int max)
{
	random_device randdev;
	ARYLOOP;
	nums[i] = randdev() % max + 1;
	END;
}

void PrintAry(int nums[], int n)
{
	ARYLOOP;
	cout << nums[i] << endl;
	END;
}

void Swap(int nums[],int IdxA, int IdxB)
{
	int num = nums[IdxA];
	nums[IdxA] = nums[IdxB];
	nums[IdxB] = num;
}

void Sort(int nums[], int n, bool isRev=false)
{
	for (int i = 0;i < n; i++)
	{
		for (int cnum = i; cnum < n; cnum++)
		{
			if (isRev)
			{
				if (nums[i] < nums[cnum]) Swap(nums, i, cnum);
			}
			else
			{
				if (nums[i] > nums[cnum]) Swap(nums, i, cnum);
			}
		}
	}
}

int main()
{
	int nums[10];
	SetRandInt(nums, 10, 50);
	PrintAry(nums, 10);
	SPRT;
	Sort(nums, 10,true);
	PrintAry(nums, 10);
	return 0;
}
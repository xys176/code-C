#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;;
			}
		}
		a[end + 1] = tmp;
	 }
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; // 加一确保最后一次间隔为1的插入排序。
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap; 
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

//在后边遍历选出最大的与最小的
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[mini] > a[i])
			{
				mini = i;
			}
			if (a[maxi] < a[i])
			{
				maxi = i;
			}
		}
		int tempmin = a[begin];
		a[begin] = a[mini];
		a[mini] = tempmin;
		if (begin == maxi)
		{
			maxi = mini;
		}
		swap(&a[end], &a[maxi]);
		int tempmax = a[end];
		a[end] = a[maxi];
		a[maxi] = tempmax;
		begin++;
		end--;
	}
}

//冒泡排序
//
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] < a[j])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;;
			}
		}
	}
}


//重要：
//当左边做key，让右边right先走，同理，若右边right做key，则应该让左边left先走。
//这是为了保证最后key位置与中间相遇位置交换后，还能保持左边比右边小。
void QuickSort(int* a, int begin,int end)
{
	//当区间不存在或只有一个值
	if (begin >= end)
	{
		return;
	}
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])		//注意这里一定加上等于，如果不加等于号，
									//那么当左右两边数值相等时，就会死循环，因为交换之后两个数依旧是相等的。
		{
			right--;				//加上left<right的判断，否则可能会越界访问，因为当等于的情况下
		}							//还是有right--与left++，当key为最小值时，那么right向左移动直到
		while (left < right &&  a[left] <= a[keyi])		//与key相等，此时是数组最左边，那么经过right--，就会越界。
		{							//再循环中要加上，left<right的判断。
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[keyi], &a[left]);
	keyi = left;
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}
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
		gap = gap / 3 + 1; // ��һȷ�����һ�μ��Ϊ1�Ĳ�������
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

//�ں�߱���ѡ����������С��
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

//ð������
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


//��Ҫ��
//�������key�����ұ�right���ߣ�ͬ�����ұ�right��key����Ӧ�������left���ߡ�
//����Ϊ�˱�֤���keyλ�����м�����λ�ý����󣬻��ܱ�����߱��ұ�С��
void QuickSort(int* a, int begin,int end)
{
	//�����䲻���ڻ�ֻ��һ��ֵ
	if (begin >= end)
	{
		return;
	}
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])		//ע������һ�����ϵ��ڣ�������ӵ��ںţ�
									//��ô������������ֵ���ʱ���ͻ���ѭ������Ϊ����֮����������������ȵġ�
		{
			right--;				//����left<right���жϣ�������ܻ�Խ����ʣ���Ϊ�����ڵ������
		}							//������right--��left++����keyΪ��Сֵʱ����ôright�����ƶ�ֱ��
		while (left < right &&  a[left] <= a[keyi])		//��key��ȣ���ʱ����������ߣ���ô����right--���ͻ�Խ�硣
		{							//��ѭ����Ҫ���ϣ�left<right���жϡ�
			left++;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[keyi], &a[left]);
	keyi = left;
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}
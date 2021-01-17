#include <stdio.h>
int main()
{
	int arr[] = {2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	int key = 0;
	scanf("%d", &key);
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if(arr[mid]>key)
		{
			right = mid - 1;
		}
		else
		{
			printf("�ҵ�Ԫ�أ��±�Ϊ:%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("û���ҵ���Ԫ��\n");
	}
}
#include<stdio.h>
int main()
{
	int i,a[10],temp,k,flag;
	printf("ÇëÊäÈë10¸öÊı×Ö:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(k=0;k<9;k++)
	{
		flag=0;
		for(i=0;i<9-k;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				flag=1;
				
			}
		}
		if(flag==0)
		break;
		
	}
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}
	
	
	
	
		
	
	
	
		
	
	
	

 


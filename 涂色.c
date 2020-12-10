#include<stdio.h>
int main()
{
	char color[5][10]={"red","yellow","blue","green","brown"};
	int i,j,k;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			for(k=0;k<5;k++)
			{
				if(i!=1&&j!=4&&i!=k)
				{
					printf("%s %s %s\n",color[i],color[j],color[k]);
				}
			}
		}
	}
	
}



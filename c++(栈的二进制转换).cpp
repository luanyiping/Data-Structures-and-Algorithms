#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	stack<int>s;
	int num = 0;
	scanf("%d", &num);
	while (num)
	{
		s.push(num % 2);
		num /= 2;
	}
	while (!s.empty()) // Ϊ�շ���true
	{
		printf("%d ", s.top());
		s.pop();
	}
}

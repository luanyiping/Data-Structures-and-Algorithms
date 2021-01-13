#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int>s;
	// 判断栈是否为空,为空返回true
	bool empty();
	// 入栈
	for (int i = 0; i < 10; i++)
	{
		s.push(i);
	}
	// 出栈
	void pop();
	// 返回栈顶元素
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	//  返回栈中元素个数
	cout << s.size() << endl;

}
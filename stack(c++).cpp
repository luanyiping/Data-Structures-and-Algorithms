#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int>s;
	// �ж�ջ�Ƿ�Ϊ��,Ϊ�շ���true
	bool empty();
	// ��ջ
	for (int i = 0; i < 10; i++)
	{
		s.push(i);
	}
	// ��ջ
	void pop();
	// ����ջ��Ԫ��
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	//  ����ջ��Ԫ�ظ���
	cout << s.size() << endl;

}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool isvalid(char* s)
{
	char* p = (char*)malloc(sizeof(char) * strlen(s)), temp;
	int top = -1, i = 0;
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			p[++top] = s[i];
		}
		else if (top < 0)
		{
			return false;
		}
		temp = p[top];
		if (s[i] == ')')
		{
			if (temp == '(')
				top--;
			else
				return false;
		}
		if (s[i] == '}')
		{
			if (temp == '{')
				top--;
			else
				return false;
		}
		if (s[i] == ']')
		{
			if (temp == '[')
				top--;
			else
				return false;
		}
	}
	if (top >= 0)
		return false;
	else
		return true;
}
int main()
{
	char s[100];
	gets_s(s);
	if (isvalid(s))
	{
		printf("true");
	}
	else
	{
		printf("false");
	}

}
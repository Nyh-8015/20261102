#include <iostream>
using namespace std;


typedef int DataType;
struct Stack
{
	int top;
	int maxsize;
	DataType* elements;
};

void InitStack(Stack& s, int size)
{
	s.maxsize = size;
	s.elements = new DataType[s.maxsize];
	s.top = -1;
}
bool IsEmpty(Stack& s)
{
	return s.top == -1;
}

bool IsFull(Stack& s)
{
	return s.top == s.maxsize - 1;
}

bool Push(Stack& s, DataType x)
{
	if (IsFull(s))
	{
		cout << "栈满，入站失败！" << endl;
		return false;
	}
	s.top++;
	s.elements[s.top] = x;
	return true;
}

bool Pop(Stack& s, DataType& x)
{
	if (IsEmpty(s))
	{
		cout << "栈空，入栈失败" << endl;
		return false;
	}
	x = s.elements[s. top];
	s.top--;
	return true;
}

bool GetTop(Stack& s, DataType& x)
{
	if (IsEmpty(s))
	{
		cout << "栈空，获取栈顶元素失败" << endl;
		return false;
	}
	x = s.elements[s.top];
	return true;
}

void DestroyStack(Stack& s)
{
	delete[] s.elements;
	s.elements = nullptr;
	s.top = -1;
	s.maxsize = 0;
}

void DecToBase(int n, int base)
{
	if (base < 2 || base>9)
	{
		cout << "进制必须在2~9之间" << endl;
		return;
	}
	if (n == 0)
	{
		cout << 0;
		return;
	}
	Stack st;
	InitStack(st, 100);

	int t = n;
	while (t != 0)
	{
		int rem = n % base;
		Push(st, rem);
		t /= base;
	}

	int val;
	while (!IsEmpty(st))
	{
		Pop(st, val);
		cout << val;
	}
	DestroyStack(st);
}

int main()
{
	Stack s;
	InitStack(s, 5);
	cout << "是否为空栈：" << (IsEmpty(s) ? "是" : "否") << endl;


	Push(s, 10);
	Push(s, 20);
	Push(s, 30);

	int topVal;
	Pop(s, topVal);
	cout << "栈顶元素：" << topVal << endl;

	int popVal;
	Pop(s, popVal);
	cout << "出栈元素：" << popVal << endl;
	GetTop(s, topVal);
	cout << "出栈后栈顶：" << topVal << endl;

	cout << "是否满：" << (IsFull(s) ? "是" : "否") << endl;
	DestroyStack(s);

	cout << "\n========十进制转进制测试========" << endl;
	int num, b;
	cout << "请输入一个十进制整数：";
	cin >> num;
	cout << "请输入进制(2~9)：";
	cin >> b;
	cout << "转换结果：";
	DecToBase(num, b);
	cout << endl;


	return 0;
}
#include<iostream>
using namespace std;
#include<string>
class stack
{
	public:
		int top;
		stack()
		{
			top=-1;
		}
		void push(int n)
		{
			top++;
			arr[top]=n;
			cout<<n<<" is being pushed at "<<top<<endl;
		}
		int pop()
		{
			int k=arr[top];
			cout<<k<<" is being popped at "<<top<<endl;
			top--;
			return k;
		}
		int show()
		{
			return arr[top];
		}
	private:
		
		int arr[20];
		
};
bool isoperator(char c);
bool isnumeric(char c);
void operate(char c);

stack stack1;

int main()
{
	string s;
	getline(cin,s);
	char c;
	int operand,k=0,full=0;
	for (int i=0;i<s.size();i++)
	{
		operand=0;
		c=s[i];
		if (isoperator(c))
		{
			if (k>0) stack1.push(full);
			k=0;
			operate(c);
		}
		
		else if (c==' ') {if (k>0) stack1.push(full);k=0;}
		else if (isnumeric(c))
		{
			k++;
			operand=c-'0';
			if (k==1) full=operand;
			else if (k>1)
				full=full*10+operand;
			
		}

	}
	cout<<stack1.show();
	return 0;
}

bool isoperator(char c)
{
	if (c=='+'||c=='-'||c=='*'||c=='/')
		return true;
	return false;
}

bool isnumeric(char c)
{
	if (c>='0'&& c<='9') return true;
	return false;
}

void operate(char c)
{
	int op1,op2;
	op1=stack1.pop();
	op2=stack1.pop();
	if (c=='+') stack1.push(op2+op1);
	else if (c=='-') stack1.push(op2-op1);
	else if (c=='*') stack1.push(op2*op1);
	else if (c=='/') stack1.push(op2/op1);
}




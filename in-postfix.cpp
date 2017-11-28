#include<iostream>
using namespace std;
class stack
{
	public:
		stack()
		{
			top=-1;
		}
		int isempty()
		{
			return (top==-1)? 1:0;
		}
		void push(char c)
		{
			top++;
			arr[top]=c;
		}
		char pop()
		{
			if (top!=-1)
			{
			char c=arr[top];
			top--;
			return c;
			}
		}
		char show()
		{
			if(top!=-1) return arr[top];
		}
	private:
		char arr[10];
		int top;
};

bool isoperator(char c)
{
if (c=='^'||c=='*'||c=='/'||c=='+'||c=='-')
	return true;
else return false;
}
int pre(char c)
{
	if (c=='^') return 3;
	else if (c=='*'||c=='/') return 2;
	else if (c=='+'||c=='-') return 1;
}
int main()
{
	cout<<"give an infix expression containing single digit numbers and +-*/^ ( )"<<endl;
	string s,postfix="";
	int i,k=0;
	stack st;
	cin>>s;
	for (i=0;i<s.length();i++)
	{
		if (s[i]=='(') st.push(s[i]); 
		else if (isoperator(s[i]))
		{
		while (!st.isempty() && isoperator(st.show()) && pre(s[i])<=pre(st.show())) {postfix+=st.show();st.pop();}
		st.push(s[i]);
		}
		else if (s[i]==')') {while (!st.isempty() && st.show()!='(') {postfix+=st.show();st.pop();} st.pop();}
		else postfix+=s[i];		
	}
	while (!st.isempty())
	{
		postfix+=st.show();
		st.pop();
	}
	cout<<"postfix exp is "<<postfix<<endl;
	return 0;
}
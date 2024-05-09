#include<iostream>
#include<cstdlib>

using namespace std;

class stack{
	int top;
	int data[100];//배열선언

public:
	stack();//생성자
	~stack();//소멸자
	void push(int item);//입력
	void pop();//삭제
	int gettop();//현재 최고위치 출력
	char getdata();//현재 최고위치 데이터 출력
	
};
stack::stack(){
	top=0;
	data[0]='*';
}
stack::~stack(){

}

void stack::push(int item){
	if(top==100)
	{
		exit(1);
	}
	top++;
	data[top]=item;
}

void stack::pop()
{
	if(top==0)
	{
		exit(1);
	}
	else
		top--;
}
int stack::gettop()
{
	return top;
}
char stack::getdata()
{
	return data[top];
}

int main()
{
	stack s;
	
	char command;
	while(cin>>command)
	{
		if(command=='('&&s.gettop()<100)//'('입력
		{
		s.push(command);
		}
		if(command=='{'&&s.gettop()<100)//'{'입력
		{
			s.push(command);
		}
		if(command=='['&&s.gettop()<100)//'['입력
		{	
			s.push(command);
		}
		if(command==')')//')'입력시 최고위치 데이터 출력 및 확인
		{
			if(s.getdata()=='(')
			{
					s.pop();
			}
		}
		if(command=='}')//'}'입력시 최고위치 데이터 출력 및 확인
			{
				if(s.getdata()=='{')
					{
						s.pop();
					}
			}
		if(command==']')//']'입력시 최고위치 데이터 출력 및 확인
			{
			if(s.getdata()=='[')
						{
							s.pop();	
						}
			}
		else
		{
			continue;
		}
	}
	if(s.gettop()==0)
	{
		cout<<"1"<<endl;
	}
	else
	{
		cout<<"-1"<<endl;
	}
}

3-2
#include<iostream>
#include<cstdlib>
typedef int itemtype;

using namespace std;

class stack{
	int top;
	int data[100];
	int kline[100];

public:
	stack();//생성자
	~stack();//소멸자
	void push(char item);//입력
	void linepush(int line);//줄 별 위치 저장
	void pop();//삭제
	int gettop();//현재 최고 위치 출력
	char getdata();//현재 최고 위치 데이터 출력
	int getline();//현제 최고 위치 데이터의 줄 출력
};
stack::stack(){
	top=0;
}
stack::~stack(){

}

void stack::push(char item){
	if(top==99)
	{
		exit(1);
	}
	top++;
	data[top]=item;
}

void stack::pop()
{
 top--;
}
int stack::gettop()
{
	return top;
}
char stack::getdata()
{
	return data[top];
}
void stack::linepush(int line)
{
	kline[top]=line;
}
int stack::getline()
{
	return kline[top];
}
int main()
{
	int line=1,valid=1;
	int command;
	stack s;
	int result;

while((command=getchar())!=EOF)//^z입력받을때까지 입력받음
	{
	
		if(command=='\n')//줄 수 증가
		{line++;}
		if(command=='('||command=='{'||command=='[')//조건 충족시 입력 및 라인 수 증가
		{
			s.push(command);
			s.linepush(line);
		}
		if(command==')')
		{
			if(s.gettop()!=0&&s.getdata()=='(')//아무것도 없지 않고 최고위치 데이터가 '('일때
			{
				s.pop();
			}
			else
			{
				s.linepush(line);
				result=s.getline();
				cout<<"error 1 at line "<<line<<endl;
				valid=0;
				break;
			}
		}
		if(command=='}')
		{
			if(s.gettop()!=0&&s.getdata()=='{')//아무것도 없지 않고 최고위치 데이터가 '{'일때
			{
								s.pop();
			}
			else
			{
				s.linepush(line);
				cout<<"error 2 at line "<<line<<endl;
				valid=0;
				break;
			}
		}
		if(command==']')
		{
			if(s.gettop()!=0&&s.getdata()=='[')//아무것도 없지 않고 최고위치 데이터가 '['일때
			{
				s.pop();
			}
			else
			{
				s.linepush(line);
				cout<<"error 3 at line "<<line<<endl;
				valid=0;
				break;
			}
		}
	
	} 
	
	if(s.getdata()=='('&&valid==1)//'('남을때
	{
		
		cout<<"error 4 at line "<<s.getline()<<endl;
		valid=0;
	}
	if(s.getdata()=='{'&&valid==1)//'{'남을때
	{
		
		cout<<"error 5 at line "<<s.getline()<<endl;
		valid=0;
	}
	if(s.getdata()=='{'&&valid==1)//'['남을때
	{
		
		cout<<"error 6 at line "<<s.getline()<<endl;
		valid=0;
	}
 	if(s.gettop()==0)//모두 맞을때
	{
		cout<<"1"<<endl;
	}
}
		
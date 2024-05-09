#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


typedef char itemtype;//데이터타입 선언
struct node//구조체 선언
{
	itemtype info;
	node *next;
};
class stack//스택 선언
{
	public:
	stack();
	~stack();
	bool isempty() const;//빈 지 확인하는 함수 선언
	bool isfull() const;//차있는지 확인하는 함수 선언
	void push(itemtype item);//새로운 스텍을 만들어 추가하는 함수 선언
	char pop();//지우는 함수 선언
	char peek() const;//현재 탑의 위치 반환함수 선언
	char gettopptr();
private:
	node *topptr;
};
stack::stack()
{
	topptr=NULL;
}
stack::~stack()
{
	node *tempptr;

	while(topptr!= NULL)
	{
		tempptr != topptr;
		topptr=topptr->next;
		delete tempptr;
	}
}
bool stack::isempty() const
{
	if(topptr==NULL)
		return true;
	else

		return false;

}
void stack::push(itemtype item)
{
	node *newnode;
	newnode= new node;
	newnode->info=item;
	newnode->next=topptr;
	topptr=newnode;
}
char stack::pop()
{
	if(isempty()){
		cout<<"비어있음"<<endl;
		exit(1);
	}
	else
	{
	itemtype item;
	node *tempptr;
	item=topptr->info;
	tempptr=topptr;
	topptr=topptr->next;
	delete tempptr;
	return item;
	}
}
char stack::peek() const
{
	if(isempty())
	{
		cout<<"비어있음"<<endl;
		exit(1);
	}
	else
		return topptr->info;
}
char stack::gettopptr()
{
	return topptr->info;
}

int main()
{
	stack s;
	char command;
	while(cin>>command)//글자 입력받음
	{
		if(command=='(')//입력값 별로 별도 수행
		{
		s.push(command);
		}
		if(command=='{')
		{
			s.push(command);
		}
		if(command=='[')
		{
			s.push(command);
		}
		if(command==')')
		{
			if(s.gettopptr()=='(')//최고 위치에 맞는 괄호가 있는지 확인 후 맞으면 팝함수 호출
			{
					s.pop();
			}
		}
		if(command=='}')
			{
				if(s.gettopptr()=='{')
					{
						s.pop();
					}
			}
		if(command==']')
			{
			if(s.gettopptr()=='[')
						{
							s.pop();
						}
			}
		else
		{
			continue;
		}
	}
	if(s.isempty())//맞는 경우
	{
		cout<<"1"<<endl;
	}
	else//틀린경우
	{
		cout<<"-1"<<endl;
	}
}
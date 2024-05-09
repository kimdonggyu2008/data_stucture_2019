#include <cstdlib>
#include<iostream>
#include<ctype.h>
#include<string>
#include<cstring>
using namespace std;

struct sugang{//구조체 선언
		string number;
		string name;
		string major;
		sugang *leftlink=NULL;
		sugang *rightlink=NULL;
};

class suganginfo//구조체 포함하는 노드
{
sugang *root;//제일 처음으로 나오는 것, 첫번째꺼를 가리킴
int people;

public:
	sugang *tlocation=root;
	suganginfo();//생성자
	~suganginfo();//소멸자
	bool newsugang(string a, string b,string c);	//새로운거 추가, 학번,이럼,학과입력받음
	void remove(sugang*& location,string a);
	void deletesugang(string a);//학번입력받음
	int getlength();//학생수 출력
	int changeinfo(string a,string b,string c,sugang *location,int d);//학번,이름,학과, 정보변경
	bool getinfo(string a);//학번받고 정보출력
	void returnsugang();//학번순으로 학번,이름,학과 출력
	void result(sugang *location);//결과 출력
	int count(sugang *location);//학생수 출력
};

suganginfo::suganginfo()//생성자
{
	root=NULL;
}
suganginfo::~suganginfo()//나중에 봄
{
	sugang* ptr=root;
	while(ptr->leftlink==NULL&&ptr->rightlink==NULL)
	{
		delete ptr;
	}
}
bool suganginfo::newsugang(string a,string b,string c)//추가,첫번째는 처음으로 다음부터는 뒤에 추가
{
	sugang* location=root;//간이 노드 생성
	sugang* temp;//수강자 노드 생성
	temp= new sugang;
	temp->number=a;
	temp->name=b;
	temp->major=c;

	if(root==NULL)//루트가 비어있을때
	{
		root=temp;//첫번째위치에 입력
	}
	else
	{
		if(a==location->number)//같으면 종료
			{
				cout<<"error1"<<endl;
				return false;
			}
		while(1)//링크가 없을때까지
		{
			if(a<location->number&&location->leftlink!=NULL)//작으면 쪽으로 이동
			{
				location=location->leftlink;
			}
			else if(a==location->number)//같으면 종료
			{
				cout<<"error1"<<endl;
				return false;
			}
			else if(a>location->number&&location->rightlink!=NULL)//크면 오른쪽으로 이동
			{
				location=location->rightlink;
			}
			if(a<location->number&&location->leftlink==NULL)
			{
				location->leftlink=temp;//왼쪽에 붙임
				return true;
			}
			else if(a>location->number&&location->rightlink==NULL)
			{
				location->rightlink=temp;//오른쪽에 붙임
				return true;
			}
		}//위치 이동 완료

	}
	return true;
}
void suganginfo::deletesugang(string a)
{
	remove(root,a);
}

void suganginfo::remove(sugang*& location,string a)//삭제 재귀
{
	
	if(a<location->number&&location->leftlink!=NULL)//작을때 왼쪽 노드로 이동
	{
		remove(location->leftlink,a);
	}
	if(a>location->number&&location->rightlink!=NULL)//클때 오른쪽 노드로 이동
	{
		remove(location->rightlink,a);
	}
	else
	{
		sugang *temp;
		if(location->leftlink==NULL)//왼쪽이 비었을때
		{
			temp=location;
			location=location->rightlink;
			delete temp;
		}
		else if(location->rightlink==NULL)//오른쪽이 비었을때
		{
			temp=location;
			location=location->leftlink;
			delete temp;
		}
		else
		{
			temp=location->rightlink;//부모노드가 비었을때 오른쪽에서 가장 작은 노드랑 바꿈
			while(temp->leftlink!=NULL)
			{
				temp=temp->leftlink;
			}
			location->number=temp->number;
			remove(location->rightlink,location->number);
		}
	}
	if(location==NULL)//없을시
	{
		cout<<"error2"<<endl;
	}
}
int suganginfo::getlength()//길이 출력
{
	return count(root);
}
int suganginfo::count(sugang *location)//길이출력 재귀함수
{
	if(location==NULL)
		return 0;
	return 1+count(location->leftlink)+count(location->rightlink);
}
int suganginfo::changeinfo(string a,string b,string c,sugang *location,int d)//정보변경 재귀함수
{
	if(root==NULL)
	{
		return 0;
	}
	if(d==1)
	{
		location=root;
		d=0;
	}
	if(location->number==a)//위치에 있으면 변경함
	{
		location->name=b;
		location->major=c;
		return 1;
	}
	if(a<location->number)//작을때
	{
		if(location->leftlink==NULL)
		{
			return 0;
		}
		else
		{
			changeinfo(a,b,c,location->leftlink,0);//왼쪽이동
		}
	}
	if(a>location->number)//클때
	{
		if(location->rightlink==NULL)
		{
			return 0;
		}
		else
		{
			changeinfo(a,b,c,location->rightlink,0);//오른쪽이동
		}
	}
	return 1;
}

bool suganginfo::getinfo(string a)//학번으로 정보찾기
{
	sugang* current;
	string item;
	if(root==NULL)//비었을때
	{
		cout<<"error2"<<endl;
	}
	else
	{
		current=root;
		while(current!=NULL){//루트부터 이동하면서 찾음
			if(current->number==a)//찾았을때
			{
			cout<<current->number<<" "<<current->name<<" "<<current->major<<endl;
			return true;
			}
			else if(current->number>a)//작을때
						current=current->leftlink;
					else//클때
						current=current->rightlink;
		}
		return true;
	}
}

void suganginfo::returnsugang()//학번순 출력
{
	 result(root);
}
void suganginfo::result(sugang *location)//학번순 출력 재귀함수
{
		if(location!=NULL)
		{
			result(location->leftlink);
			cout<<location->number<<" "<<location->name<<" "<<location->major<<endl;
			result(location->rightlink);
		}
}

int main()
{
	suganginfo s;//수강자 클래스 선언
	string a;
	string b,c,d;
	while(cin>>a)//메뉴 입력받음
	{
			if(a=="N")//새로운 수강생 추가
			{
				cin>>b>>c>>d;
				s.newsugang(b,c,d);
			}
			if(a=="W")//수강생 삭제
			{
				cin>>b;
				s.deletesugang(b);
			}
			if(a=="S")//학생수 출력
			{
				int k=s.getlength();
				cout<<k<<endl;
			}
			if(a=="C")//정보 변경
			{
				cin>>b>>c>>d;
				sugang *k=s.tlocation;//헤드받음
				int n=s.changeinfo(b,c,d,k,1);//받은 헤드와 입력값가지고 재귀
				if(n==0)
					cout<<"error2"<<endl;
			}
			if(a=="R")//학생정보 찾아서 출력
			{
				cin>>b;
				s.getinfo(b);
			}
			if(a=="P")//학번순으로 출력
			{
				s.returnsugang();
			}

			if(a=="Q")//--실행됨
			{
				break;
			}
	}
	return 0;
}
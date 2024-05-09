#include <cstdlib>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<string>
using namespace std;

struct sugang{//구조체 선언
		string number;
		string name;
		string major;
		sugang *link;
};

class suganginfo//구조체 포함하는 노드
{
sugang *head;//제일 처음으로 나오는 것, 첫번째꺼를 가리킴
int length;

public:
	sugang *tlocation=head;
	suganginfo();//생성자
	~suganginfo();//소멸자
	void newsugang(string a,string b,string c);//새로운거 추가, 학번,이럼,학과입력받음
	bool deletesugang(string a);//학번입력받음
	void getlength();//학생수 출력
	int changeinfo(string a,string b,string c,sugang *location,int d);//학번,이름,학과, 정보변경
	bool getinfo(string a);//학번받고 정보출력
	void returnsugang();//학번순으로 학번,이름,학과 출력
};

suganginfo::suganginfo()//생성자
{
	head=NULL;
	length=0;
}
suganginfo::~suganginfo()
{
	sugang* ptr;
	while(head!=NULL)
	{
		ptr=head;
		head=head->link;
		delete ptr;
	}
}
void suganginfo::newsugang(string a,string b,string c)//추가,첫번째는 처음으로 다음부터는 뒤에 추가
{
	sugang* location=head;//간이 노드 생성
	sugang* newsugang;//수강자 노드 생성
	int valid=1;
	while(location!=NULL)//걸리는 것
	{
		if(location->number==a)//겹치는 게 있을 시 에러 출력 학번
		{
			cout<<"error1"<<endl;
			valid=0;//유효값 변경
		}
		location=location->link;
	}
	if(length==0&&valid==1)//처음일때
	{
		newsugang=new sugang;
		newsugang->number=a;
		newsugang->name=b;
		newsugang->major=c;
		newsugang->link=head;
		head=newsugang;
		length++;
	}
	else if(length!=0&&valid==1)//길이가 0이 아니고 유호값이 존재할때
	{

		newsugang=new sugang;
		newsugang->number=a;
		newsugang->name=b;
		newsugang->major=c;
		newsugang->link=head;//이전것을 앞으로 밀어냄
		head=newsugang;//자신이 헤드가 됨
		length++;
	}
}
bool suganginfo::deletesugang(string a)//삭제확인--문제발생
{
	sugang* location=head;
	if(length==0)
	{
		return false;
	}
	if(location->number==a)
	{
		head=location->link;
		length--;
		delete location;
		return true;
	}
	for(int i=0;i<length-1;i++)
	{
		if(location->link->number==a)
		{
			sugang* temp=location->link;
			location->link=temp->link;
			delete temp;
			length--;
			return true;
		}
		location=location->link;
	}
	return false;
}
void suganginfo::getlength()
{
	cout<<length<<endl;//인원수 반환
}
int suganginfo::changeinfo(string a,string b,string c,sugang *location,int d)//--문제발생
{
	if(length==0)
	{
		return 0;
	}
	if(d==1)
	{
		location=head;
	}
	if(location==NULL)
	{
		return 0;
	}
	if(location->number==a)//학번을 찾을때
		{
			location->name=b;//정보 변경
			location->major=c;
			return 1;
		}
	if(location!=NULL)
	{
		return changeinfo(a,b,c,location->link,0);//아니면 재귀로 넘어감
	}
}

bool suganginfo::getinfo(string a)//학번으로 정보찾기
{
	sugang* location=head;//헤드에서 시작
	for(int i=0;i<length;i++)//맞는 것을 찾기 위함
		{
			if(location->number==a)
			{
				cout<<location->number<<" "<<location->name<<" "<<location->major<<endl;
				return true;
			}
			location=location->link;
		}
	return false;//끝까지 안 나올시 에러출력

}

void suganginfo::returnsugang()//학번순 출력
{
	string k[length];//렝스길이 배열선언
	int i=0;
	sugang* location=head;//헤드부터 시작
	while(location!=NULL){//끝에 도달할때까지 학번 복사
		k[i]=location->number;//학번만 복사함
		i++;
		location=location->link;//다음걸로 이동
	}
	sort(k,k+length);//정렬
	location=head;//헤드로 다시 옮김
	for(int a=0;a<length;a++)//모든 자료를 출력을 하기 위함
	{
		location=head;//위치 초기화
		for(i=0;i<length;i++)//맞는 것을 찾기 위함
		{
			if(k[a]==location->number)//정렬된 숫자와 일치하는 정보 출력
			{
				cout<<location->number<<" "<<location->name<<" "<<location->major<<endl;
			}
			location=location->link;
		}
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
				int a;
				a=s.deletesugang(b);
				if(a==0)
					cout<<"error2"<<endl;
			}
			if(a=="S")//학생수 출력
			{
				s.getlength();
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
				int k;
				k=s.getinfo(b);
				if(k==0)
					cout<<"error2"<<endl;
			}
			if(a=="P")//학번순으로 출력
			{
				s.returnsugang();
			}
			if(a=="Q")
			{
				break;
			}
	}
	return 0;
}

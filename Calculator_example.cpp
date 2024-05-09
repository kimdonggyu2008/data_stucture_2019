#include<iostream>
#include<string>
using namespace std;

class calculator{
private://변수 입력
	int result;
	int memory;
public://클래스 함수 선언
	calculator();
	~calculator();
	void setvalue(int value);
	void add(int value);
	void sub(int value);
	void multi(int value);
	void divide(int value);
	void mod(int value);
	void changesign();
	void clear();
	void memorysave();
	void memoryread();
	void memoryclear();
	void memoryadd();
	void memorysub();
	void printr();	
};
calculator::calculator()//생성자
{
	result=0;
	memory=0;
}
calculator::~calculator()//소멸자
{

}
void calculator::setvalue(int value)//값 설정
{
	result=value;
}
void calculator::add(int value)//더하기
{
	result+=value;
}
void calculator::sub(int value)//빼기
{
	result-=value;
}
void calculator::multi(int value)//곱하기
{
	result*=value;
}
void calculator::divide(int value)//나누기
{
	result/=value;
}
void calculator::mod(int value)//나머지 계산
{
	result=result%value;
}
void calculator::changesign()//부호 변환
{
	result=result*(-1);
}
void calculator::clear()//초기화
{
	result=0;
}
void calculator::memorysave()//메모리에 저장
{
	memory=result;
}
void calculator::memoryread()//메모리 읽어오기
{
	result=memory;
}
void calculator::memoryclear()//메모리 초기화
{
	memory=0;
}
void calculator::memoryadd()//메모리에 더하기
{
	memory=memory+result;
}
void calculator::memorysub()//메모리에 빼기
{
	memory=memory-result;
}
void calculator::printr()//result 출력
{
	cout<<result<<endl;
}

int main()
{
	calculator cal;
	string command;
	int value;
	string exitcmd="exit";

	while(cin>>command)//커맨드 입력받음 
	{
		if(command==exitcmd)//각 커맨드에 따라 명령 수행
		{
			break;
		}
		else if(command=="setValue")
		{
			cin>>value;
			cal.setvalue(value);
			cal.printr();
		}
		else if(command=="add")
		{
			cin>>value;
			cal.add(value);
			cal.printr();
		}
		else if(command=="sub")
		{
			cin>>value;
			cal.sub(value);
			cal.printr();
		}
		else if(command=="mul")
		{
			cin>>value;
			cal.multi(value);
			cal.printr();
		}
		else if(command=="div")
		{
			cin>>value;
			cal.divide(value);
			cal.printr();
		}
		else if(command=="mod")
		{
			cin>>value;
			cal.mod(value);
			cal.printr();
		}
		else if(command=="cs")
		{
			cal.changesign();
			cal.printr();
		}
		else if(command=="clear")
		{
			cal.clear();
			cal.printr();
		}
		else if(command=="MS")
		{
			cal.memorysave();
			cal.printr();
		}
		else if(command=="MR")
		{
			cal.memoryread();
			cal.printr();
		}
		else if(command=="M+")
		{
			cal.memoryadd();
			cal.printr();
		}
		else if(command=="M-")
		{
			cal.memorysub();
			cal.printr();
		}
		else if(command=="MC")
		{
			cal.memoryclear();
			cal.printr();
		}	
	}
	return 0;
}

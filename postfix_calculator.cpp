 #include<iostream>
#include<cstdlib>
#include<ctype.h>
#include<iomanip>
using namespace std;
typedef int itemtype;

class stack{
	int top;
	float data[100];//배열선언

public:
	stack();//생성자
	~stack();//소멸자
	bool is_empty();//빈 것 확인
	bool is_full();//가득찬지 확인
	void push(float item);//입력
	float pop();//삭제
	int gettop();//현재 최고위치 
	float getresult();//현재 최고위치 데이터 출력
};

stack::stack()
{
	top=-1;
}
stack::~stack()
{

}
bool stack::is_empty()
{
	if(top==-1)
		return true;
	else
		return false;
}
bool stack::is_full(){
	if(top==99)
		return true;
	else
		return false;
}
void stack::push(float item)
{
	if(is_full()){
		
		exit(1);
	}
	top++;
	data[top]=item;
}
float stack::pop()
{
	if(is_empty()){
		exit(1);
	}
	return data[top--];
}
int stack::gettop()
{
	return top;
}
float stack::getresult()
{
	return data[top];
}

int main(){
	string token;
	stack s;
	float k;
	
	int ncount=0,valid=1;//숫자 갯수, 유효 확인용 선언

while(cin>>token)//입력받음
{
	
		if(token==";")
			break;
		k=atof(token.c_str());
		if(isdigit(token[0])||isdigit(token[1]))//정수인지 확인, 음수 구별도 포함.
		{
			s.push(atof(token.c_str()));//입력
			ncount++;//현재숫자갯수 증가
		
		}
		
		else if(token=="+")//+입력 받을시
		{
			if(s.gettop()<1)//숫자 모자랄시
			{
				cout<<"error1"<<endl;
				valid=0;
				break;
			}
			if(s.is_empty()){//비었을시
				cout<<"error2"<<endl;
				valid=0;
				exit(1);
			}
			
			itemtype second=s.pop();
			if(s.is_empty()){
				cout<<"error2"<<endl;
				valid=0;
				exit(1);
			}
			
			float first=s.pop();
			s.push(first+second);//값 추출 및 계산
			ncount-=2;//숫자 갯수 줄임
		}
		else if(token=="-"){
			if(s.gettop()<1)
			{
				cout<<"error1"<<endl;
				valid=0;
				break;
			}
					if(s.is_empty()){
						cout<<"error2"<<endl;
						valid=0;
						exit(1);
					}
			
					float second=s.pop();
					if(s.is_empty()){
						cout<<"error2"<<endl;
						valid=0;
						exit(1);
					}
					else
					{float first=s.pop();
					s.push(first-second);//값 추출 및 계산
					
					ncount-=2;//숫자 갯수 줄임
					}
				}
		else if(token=="*"){
	
			if(s.gettop()<1)
			{
				cout<<"error1"<<endl;
				valid=0;
				break;
			}
					if(s.is_empty()){
						cout<<"error2"<<endl;
						valid=0;
						exit(1);
					}
			
					float second=s.pop();
					if(s.is_empty()){
					cout<<"error2"<<endl;
						valid=0;
						exit(1);
					}
					else
					{float first=s.pop();
					s.push(first*second);//값 추출 및 계산
					ncount-=2;//숫자 갯수 줄임
				}
				}
		else if(token=="/"){

			if(s.gettop()<1)
			{
				cout<<"error1"<<endl;
				valid=0;
				break;
			}
					if(s.is_empty())
					{
						cout<<"error2"<<endl;
						valid=0;
						exit(1);
					}
			
					float second=s.pop();
					if(s.is_empty())
					{
						cout<<"error2"<<endl;
						valid=0;
						exit(1);
					}
					else
					{float first=s.pop();
					s.push(first/second);//값 추출 및 계산
					ncount-=2;}//숫자 갯수 줄임
				}
			else if(token=="%")//+입력 받을시
		{
			if(s.gettop()<1)//숫자 모자랄시
			{
				cout<<"error1"<<endl;
				valid=0;
				break;
			}
			if(s.is_empty()){//비었을시
				cout<<"error2"<<endl;
				valid=0;
				exit(1);
			}
			itemtype second=s.pop();
			if(s.is_empty()){
				cout<<"error2"<<endl;
				valid=0;
				exit(1);
			}
			
			float first=s.pop();
				int ifirst=(int)first;
				int isecond=(int)second;
				float result=ifirst%isecond;
			s.push(result);//값 추출 및 계산
			ncount-=2;//숫자 갯수 줄임
		}
		if(ncount==3)//숫자 갯수 넘어갈 시 오류 출력
		{
			cout<<"error2"<<endl;
			valid=0;
			break;
		}
}
	
		if(s.gettop()==0&&valid==1)//최고 위치 및 유효 확인 및 결과 출력
		{
		float result=s.pop();
			
		cout<<fixed<<setprecision(2)<<result<<endl;
		}

		return 0;
}
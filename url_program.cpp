#include <iostream>
using namespace std;

const int MAX_SIZE=50;

class Web_browser{//변수 선언
	string addr_arr[50];
	string addr_history[50];
	int current;
	int length;
	int historynum=1;

public://클래스 함수 선언
	Web_browser();
	void go(string addr);
	void forward();
	void backward();
	string get_current_addr();
	void history();
	void home();
	void sethome(string addr);
};

Web_browser::Web_browser(){// 생성자
	addr_arr[0]="http://ces.hufs.ac.kr";
	current=0;
	length=1;
	cout<<get_current_addr()<<endl;
	addr_history[0]=addr_arr[0];
}
void Web_browser::go(string addr){//새로운 주소로 이동
	if(length<MAX_SIZE-1)
	{
		addr_arr[current+1]=addr;//주소 입력
		current++;//최근 위치 이동
		length=current+1;//길이 조정
		cout<<get_current_addr()<<endl;
	}
	addr_history[historynum]=addr;//기록 남기기
	historynum++;//기록 번호 증가
}
void Web_browser::forward()//앞으로
{
	if(current==length-1)//이동불가
		{
			cout<<get_current_addr()<<endl;
		}
	if(current<length-1)//이동가능
		{
			current++;
			cout<<get_current_addr()<<endl;
		}
}
void Web_browser::backward()//뒤로
{
	if(current==0)//이동불가
	{
		cout<<get_current_addr()<<endl;
	}
	if(current>0)//이동가능
	{
		current--;
		cout<<get_current_addr()<<endl;
	}
}
string Web_browser::get_current_addr()//최근 위치 반환
{
	return addr_arr[current];
}
void Web_browser::home()//홈으로 설정
{
	if(length<MAX_SIZE-1)
	{
		addr_arr[current+1]=addr_arr[0];
		current++;
		length=current+1;
		cout<<get_current_addr()<<endl;
	}
	addr_history[historynum]=addr_arr[current];
	historynum++;
}
void Web_browser::sethome(string addr)//입력받은 주소를 홈으로 변경
{
	addr_arr[0]=addr;	
}
void Web_browser::history()//히스토리 출력
{
	int i=historynum-10;
	if(i<0)
	{
		i=0;
	}
	for(;i<historynum;i++)
	{
		cout<<addr_history[i]<<endl;
	}
}

int main()
{
	Web_browser wb;
	string command;
	string addr;
	string EXITCMD="exit";

	while(cin>>command){
		if(command==EXITCMD)
		{
			break;
		}
		else if(command == "go")
		{
			cin>>addr;
			wb.go(addr);
		}
		else if(command =="forward")
		{
			wb.forward();
		}
		else if(command=="backward")
		{
			wb.backward();
		}
		else if(command=="history")
		{
			wb.history();	
		}
		else if(command=="set_home")
		{
			cin>>addr;
			wb.sethome(addr);
		}
		else if(command=="home")
		{
			wb.home();
		}
	}
	return 0;
}
#include <cstdlib>
#include<iostream>
#include<ctype.h>
#include<iomanip>
using namespace std;

#define MAX_QUEUE_SIZE 500

typedef int ItemType;
class Queue {
public:
	double time=0;//시간
	int delay=0;//사람들이 오는데 걸린 시간 총합
 	double number=0;//횟수
	int shorter(int a);//짧은 것 비교
	Queue();//생성자
	bool isEmpty();//비었는 지 확인
	bool isFull();
	void enqueue(ItemType item );//리어 입력
	void dequeue(ItemType item);//프론트 입력
	int numberresult();//횟수 반환
	double timeresult();//시간 반환
	void minuswait(int a);//시간 배기
	int returntemp();
private:
	int front; // 제일 앞
	int rear; // 제일 뒤
	int temp;// 대기시간
	int valid=1;//처음 것 유효확인
	int data[MAX_QUEUE_SIZE];//데이터의 
};
Queue::Queue()
{
	front = 0;
	rear = 2;
	temp=0;
}

bool Queue::isEmpty()
{
	if(front==rear)
		return true;
	else
		return false;
}
bool Queue::isFull()
{
	if((rear+6)%MAX_QUEUE_SIZE==front)
		return true;
	else
		return false;
}
void Queue::enqueue(ItemType item)
{
	number++;//횟수 증가

	int ex;
		ex=data[rear];
		rear = (rear+1) % MAX_QUEUE_SIZE;
		data[rear]=ex+item;
		temp=data[rear]-data[front];
}

void Queue::dequeue(ItemType item)
{ // 첫 항목을 큐에서 빼서 반환
// assert(front != rear)
	if(isEmpty()){
		exit(1);
	}
	else{
			int ex;//임의의 변수
			ex=data[front];//프론트 변수 반환받음
			front = (front+1) % MAX_QUEUE_SIZE;//프론트를 1증가시킴
			data[front]=ex+item;
			temp=data[rear]-data[front];//대기시간
			if(temp<0)
			{
				temp=0;
				}
			time=time+temp;//대기시간의 전체 합을 구한다
			if(valid==1)//배릴드 없으면 처음입력에서 시간이 바뀜.
			{
				time=0;
				valid=0;
			}
		if(data[rear]<data[front])
		{
			data[rear]=data[front];//전 사람의 대기시간이 끝나고 비는 시간이 생길시
		}
		
	}
}

int Queue::numberresult()
{
	return number;
}
double Queue::timeresult()
{
	
	return time;
}
void Queue::minuswait(int a)
{
	temp = temp - a;//대기 시간 줄임
	data[front]=data[front]+a;//프론트의 위치를 위로 올림
	
	if(data[rear]<data[front])
	{
		data[rear]=data[front];
	}
}
int Queue::shorter(int a)//대기시간(템프)짧은 것 구별후 작은것 반환
{
	if(temp<=a)
	{return 1;}
	else
	{return 2;}
}

int Queue::returntemp()//대기시간 반환
{
	return temp;
}
int main()
{
	Queue que1;
	Queue que2;
	int i,k,a,b;
	cin>>i;
	cin>>a>>b;
	que1.enqueue(b);//1번 리어 입력
	cin>>a>>b;
	que2.enqueue(a+b);//2번 리어 입력 - 1번 넣고 난 이후량 계산해야 함
	que2.dequeue(a);//2번 프론트 입력
	que1.dequeue(a);//1번 프론트 입력
	for(k=2;k<i;k++)
	{
		int temp=que2.returntemp();//대기시간 반환 받음

		if(que1.shorter(temp)==1)//1번이 대기시간이 짧을 시
		{
			cin>>a>>b;
		 	que2.minuswait(a);//2번 대기시간 줄임
			que1.dequeue(a);//1번 프론트 입력
			que1.enqueue(b);//1번 리어 입력
		}
		else if(que1.shorter(temp)==2)//2번이 대기시간이 짧을 시
		{
			cin>>a>>b;
			que1.minuswait(a);//1번의 대기시간 줄임
			que2.dequeue(a);//2번의 프론트 입력
			que2.enqueue(b);//2번의 리어 입력
		}
	}
	int num1,num2;
	double time1,time2,result;
	num1=que1.numberresult();//각 큐의 횟수 반환 받음
	num2=que2.numberresult();
	time1=que1.timeresult();//각 큐의 시간 반환 받음
	time2=que2.timeresult();
	result=(time1+time2)/(num1+num2);//결과 계산
	result=(result*1000)+1;//결과의 반올림 계산
	result=(int)result;
	result=(double)result;
	result=result/1000;
	cout<<fixed<<setprecision(2)<<result<<endl;//결과 출력
	return 0;
}
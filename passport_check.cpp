#include <cstdlib>
#include<iostream>
#include<ctype.h>
#include<iomanip>
using namespace std;

#define MAX_QUEUE_SIZE 500

typedef int ItemType;//아이템 타입 선언
class Queue {//큐 선언
public:
	double time=0;//시간
 	double number=0;//횟수
	Queue();
	bool isEmpty();//비었는지 확인
	bool isFull();//가득 차 있는지 확인
	void enqueue(ItemType item);//rear증가 및 rear의 데이터 입력
	void dequeue(ItemType item);//front증가 및 front의 데이터 입력
	double result();
private:
	int front; // 첫 번째 요소 앞의 위치
	int rear; // 마지막 요소 위치
	int data[MAX_QUEUE_SIZE]; // 요소의 배열
	int temp;//대기시간
	int valid=1;//최초 시행 유효값
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
		return (rear+1)%MAX_QUEUE_SIZE == front;
}
void Queue::enqueue(ItemType item)//rear증가 및 입력
{
	number++;
	if(isFull())
		exit(1);
	else{
		int ex;
		ex=data[rear];
		rear = (rear+1) % MAX_QUEUE_SIZE;
		data[rear]=ex+item;
		temp=data[rear]-data[front];
	}
}
void Queue::dequeue(ItemType item)front증가 및 입력 - 삭제
{ // 첫 항목을 큐에서 빼서 반환
// assert(front != rear);
	if( isEmpty() ) {
		cout << " Error: 큐가 공백상태입니다\n";
		exit(1);
	}
	else {
		int ex;
		ex=data[front];
		front = (front+1) % MAX_QUEUE_SIZE;
		data[front]=ex+item;
		temp=data[rear]-data[front];
		if(temp<0)
		{
			temp=0;
			}
		time=time+temp;//대기시간의 전체 합을 구한다
	}
}

double Queue::result()//결과값 반환
{
	double result;
	result=time/number;
	return result;
}
int main()
{
	Queue que;
	int i,k,a,b;
	cin>>i;

	cin>>a>>b;
	que.enqueue(b);

	cin>>a>>b;
	que.dequeue(a);
	que.enqueue(b);
	for(k=2;k<i;k++)
	{
		cin>>a>>b;
		que.dequeue(a);
		que.enqueue(b);
	}
	double res;
	res=que.result();
	cout<<fixed<<setprecision(2)<<res<<endl;
	return 0;
}

// op laba 14 - 6,27,62,75 +  var 8
//oaip   15,12,8,13,8

/*			OP				*/
/* 6.�����
 *
 * ��� ��������� P1 �� ������� �����, ����������� �� ����� ������
    ���������. ������� �� ����� ������ ������ ��������� � ������� �� �����-
    ���. ������� ����� ����� ����� ������� �����. ����� ���������� ������-
    ��� �� ����� ����������� ������, ������� ��� ��������.
 *
 */

/*
 * Listing dinamic_struct_ar1.cpp
 * http://pastebin.com/CBK6Q5TP
 */

/*

#include <iostream>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct TNode {
	int Data;
	TNode* Next;
};

typedef  TNode *PNode;

void AddAfter(PNode P,PNode NewNode);
PNode CreateNode(PNode P);
void FirstTask();
void PrintNode(PNode ptr);
PNode Destroy(PNode head);

/////////////////////////////////////
PNode CreateNode(PNode P){
	PNode newNode = new TNode;
	newNode->Data = 1 + rand()%9;
	newNode->Next = NULL;
	AddAfter(P,newNode);
	return newNode;
}

void AddAfter(PNode P,PNode NewNode){
	NewNode->Next = P->Next;
	P->Next = NewNode;
}

void PrintNode(PNode ptr){
	if(ptr == NULL){
		cout<<"List is empty\n";
	} else {
		while(ptr != NULL){
			cout<<ptr->Data<<"-->";
			ptr = ptr->Next;
		}
		cout<<"NULL\n";
	}
}

PNode Destroy(PNode head){
	PNode temp = head;
	for(int i=0; i<9; i++){
		temp = head->Next;
		free(head);
		head=temp;
	}
	return head;
}

void FirstTask(){
	PNode P1=NULL; // head;
	PNode newNode = new TNode;
	newNode->Data = 1 + rand()%9;
	newNode->Next = NULL;
	P1 = newNode;
	for(int i=0; i < 9; i++){
		CreateNode(newNode);
	}
	cout<<"������� 1\n";
	PrintNode(P1);
	P1 = Destroy(P1);
	PrintNode(P1);
	cout<<"Head address: "<<P1;

}

*/

/* 2.�������
 * ���� ��������� P1 � P2 �� ������ � ����� �������, ���������� ��
    ����� ���� ���������. ��������� ��� TQueue (��. ������� Pointer26), ���-
    ���� ������� Dequeue(Q) ������ ����, ������� ��������� �� ������� ���-
    ��� (���������) �������, ���������� ��� �������� � ����������� ������,
    ���������� ����������� ��������� (Q � ������� � �������� ��������
    ���� TQueue). � ������� ������� Dequeue ������� �� �������� �������
    ���� ��������� ��������� � ������� �� ��������. ������� ����� ������
    ������ � ����� �������������� ������� (���� ������� �������� ������,
    �� ��� ������ ������ ���� ����� nil).
 *
 */

/*
struct TQueue{
	int Data;
	struct TQueue *ptr;
};
typedef struct TQueue *QPtr;

void PrintQueue(QPtr ptr);
QPtr CreateQueue(QPtr P,int i);
void SecondTask();
QPtr Dequeue(QPtr &tail, QPtr &head);

void PrintQueue(QPtr ptr){
	if(ptr == NULL){
		cout<<"List is empty\n";
	} else {
		while(ptr != NULL){
			cout<<ptr->Data<<"-->";
			ptr = ptr->ptr;
		}
		cout<<"NULL\n";
	}
}

QPtr CreateQueue(QPtr P, int i){
	QPtr NewQ = new TQueue;
	NewQ->Data = i;// rand()%9 + 1;
	NewQ->ptr = P;
	return NewQ;
}


void SecondTask(){
	QPtr P1 = NULL;
	QPtr P2 = NULL;
	P1 = CreateQueue(P1,0);
	QPtr temp = P1;
	for(int i=0; i<4; i++){
		temp = CreateQueue(temp,i+1);
	}
	P2 = temp;
	cout<<"\n\n������� 2\n����� head: "<<P1<<"\nA���� tail: "<<P2<<endl;
	PrintQueue(P2);

	for(int i = 0; i < 4; i++ ){
		P2 = Dequeue(P2,P1);
		PrintQueue(P2);
	}

}

QPtr Dequeue(QPtr &tail, QPtr &head){
	QPtr temp = tail;
	while(temp->ptr != head){
		temp = temp->ptr;
	}
	free(head);
	head = temp;
	head->ptr = NULL;
	return tail;
}

*/

/*
 * 3. ���������� ������
 * ��� �������� ���������� ������, ������, ��������� � �������
    �������� �������� ����� ������ P1, P2 � P3. ����� ���� ���� �����. ��-
    ������� ��� TList (��. ������� ������� 59), ������� ��������� InsertAfter(L,
    D), ������� ��������� ����� ������� �� ��������� D ����� �������� ���-
    ����� ������ L (L � ������� � �������� �������� ���� TList, D � ����-
    ��� �������� ������ ����). ����������� ������� ���������� �������. �
    ������� ���� ��������� �������� ���� ������ ����� � �������� ������
    � ������� ����� ������ ��� �������, ���������� � �������� ���������.
 *
 */

/*

struct List{
	int Data;
	List *Next;
	List *Prev;
};
typedef List *TList;

struct ptr{
	TList head,tail,cur;
}S;

typedef ptr *ss;

void ThirdTask();
TList InsertAfter(TList L, int D);
void AddFirst(TList &head, TList &tail, TList NewNode );
void CreateList(TList &head, TList &tail, TList &cur);
void PrintList(TList L);

TList InsertAfter(TList L, int D){
	TList NewNode = new List;
	NewNode->Data = D;
	NewNode->Next = L->Next;
	NewNode->Prev = L;
	L->Next = NewNode;
	NewNode->Next->Prev = NewNode;
	return NewNode;
}

void CreateList(TList &head, TList &tail, TList &cur){
	for(int i = 0; i < 5; i++){
		TList NewNode = new List;
		NewNode->Data = 15;// rand()%9+1;
		AddFirst(head,tail,NewNode);
	}
	cur = head->Next; // ������� ����� 2-�� �������
}

void AddFirst(TList &head, TList &tail, TList NewNode ){
	NewNode->Prev = NULL;
	NewNode->Next = head;
	if(head) head->Prev = NewNode;
	head = NewNode;
	if(!tail) tail = head;
}

void PrintList(TList L){
	if(L==NULL){
		cout<<"List is empty\n";
		return;
	}
	while(L != NULL){
		cout<<L->Data<<"-->";
		L = L->Next;
	}
	cout<<"NULL\n";
}

void ThirdTask(){
	S.head = S.tail = S.cur = NULL;
	int mass[5] = { 1, 2, 3, 4, 5 };
	CreateList(S.head,S.tail,S.cur);
	cout<<"\n������� 3\n";
	cout<<"A���� head: "<<S.head<<"\n����� tail: "<<S.tail<<"\n����� current: "<<S.cur<<'\n';
	PrintList(S.head);
	for(int i=0; i<5; i++){
		S.cur = InsertAfter(S.cur,mass[i]);
	}
	cout<<"\n����� ������:\nA���� head: "<<S.head<<"\n����� tail: "<<S.tail<<"\n����� current: "<<S.cur<<'\n';
	PrintList(S.head);
}
*/

/*4.
 * �������75. ���� ��������� P1 � P2 �� ��������� � ������� �������� �������-
    ���� ������. ����� ���� ����� N (> 0) � ����� �� N �����. ��������� ���
    TListB (��. ������� ������� 74), ������� ��������� LBInsertFirst(L, D), ��-
    ����� ��������� ����� ������� �� ��������� D � ������ ������ L (L �
    ������� � �������� �������� ���� TListB, D � ������� �������� ������
    ����). ����������� ������� ���������� �������. � ������� ���� �����-
    ���� �������� � ������ ��������� ������ ������ ����� ����� (��������-
    ��� ����� ����� ������������� � ������ � �������� �������) � �������
    ����� �������� �������� ����������� ������.
 *
 */

/*

void FourtyTask();
TList LBInsertFirst(TList L, int D);
void PrintListB(TList ptr,TList bar);

TList LBInsertFirst(TList L, int D){
	TList NewNode = new List;
	NewNode->Data = D;
	NewNode->Next = L->Next;
	L->Next = NewNode;
	NewNode->Prev = L;
	NewNode->Next->Prev = NewNode;
	return NewNode;
}

void PrintListB(TList cur,TList bar){
	while(cur != bar){
		cout<<cur->Data<<"<--";
		cur=cur->Prev;
	}
	cout<<"barrier\n";
}

void FourtyTask(){
	TList  P1,P2;
	// P1 -> Bar, P2 -> Current
	TList Bar = new List;
	Bar->Data = 0;
	Bar->Next = Bar->Prev = Bar;
	P1=P2=Bar;
	int N = 5;
	for(int i=0; i<N;i++){
		P2 = LBInsertFirst(P2,i+1);
	}
	cout<<"\n������� 4\nA���� barrier: "<<P1<<"\n����� current: "<<P2<<endl;
	PrintListB(P2,P1);

}

int main() {
	FirstTask();
	SecondTask();
	ThirdTask();
	FourtyTask();
	return 0;
}
*/

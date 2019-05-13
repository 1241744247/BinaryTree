#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef char BTDataType;

#define N 20

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// ֧�ֶ�̬������ջ

typedef BTNode* STDataType;
typedef BTNode* QUDataType;

typedef struct Stack
{
	STDataType* _a;

	// ջ��
	int _top;

	// ����
	int _capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void ExtendMemory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);



typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;


typedef struct Queue {
	QueueNode* _front; // ��ͷ    
	QueueNode* _rear;  // ��β
}Queue;



void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
int QueueEmpty(Queue* pq);




// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);

void BinaryTreeDestory(BTNode** root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

void BTtest();


// ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

// �ǵݹ����
// �������
void BinaryTreeLevelOrder(BTNode* root);


// �ж϶������Ƿ�����ȫ������

int BinaryTreeComplete(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

void TestBinaryTree();


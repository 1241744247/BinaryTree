#include"BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	BTNode* cur;
	char x;
	x = a[*pi];
	(*pi)++;
	if (x == '#')
	{
		cur = NULL;
		return cur;
	}

	cur = (BTNode*)malloc(sizeof(BTNode));
	cur->_data = x;
	cur->_left = BinaryTreeCreate(a, pi);
	cur->_right = BinaryTreeCreate(a, pi);
	return cur;
}
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	free(*root);
	*root = NULL;
}
int BinaryTreeSize(BTNode* root)
{
	if (root==NULL)
	{
		return 0;
	}

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;

}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->_left == NULL&&root->_right==NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode *cur;

	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	

	cur = BinaryTreeFind(root->_left,x);
	if (cur)
		return cur;
	cur = BinaryTreeFind(root->_right, x);
	if (cur)
		return cur;
	return NULL;

}
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c", root->_data);

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeInOrder(root->_left);
	
	printf("%c", root->_data);
	BinaryTreeInOrder(root->_right);

}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);

	
	printf("%c", root->_data);
}



void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur;
	cur = pq->_front;
	while (cur)
	{
		pq->_front = cur->_next;
		free(cur);
		cur = pq->_front;
	}
	pq->_front = NULL;
	pq->_rear = NULL;
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* cur;
	cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->_data = x;
	cur->_next = NULL;
	return cur;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* cur = BuyQueueNode(x);
	if (pq->_front == NULL)
	{
		pq->_front = cur;
		pq->_rear = cur;
	}
	else
	{
		pq->_rear->_next = cur;
		pq->_rear = cur;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* cur;
	cur = pq->_front;
	if (pq->_front == pq->_rear)
	{
		pq->_front = NULL;
		pq->_rear = NULL;
	}
	else
		pq->_front = pq->_front->_next;
	free(cur);
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq);
	if (pq->_front == NULL)
		return NULL;
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq);
	if (pq->_rear == NULL)
		return NULL;
	return pq->_rear->_data;
}


void BinaryTreeLevelOrder(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, root);
	BTNode* x;
	x = QueueFront(&pq);
	while (x)
	{
		if (x->_left)
		QueuePush(&pq,x->_left);
		if (x->_right)
		QueuePush(&pq, x->_right);

		printf("%c", x->_data);


		QueuePop(&pq);
		x = QueueFront(&pq);
	}


	QueueDestory(&pq);
}
int BinaryTreeComplete(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, root);
	BTNode* x;
	int d=0;
	x = QueueFront(&pq);
	while (x)
	{
		QueuePush(&pq, x->_left);
		QueuePush(&pq, x->_right);
		QueuePop(&pq);
		x = QueueFront(&pq);
	}
	if (pq._front == pq._rear)
		d = 1;
	
	QueueDestory(&pq);

	return d;
}


void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*N);
	ps->_capacity = N;
	ps->_top = -1;

}
void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = -1;

}
void ExtendMemory(Stack* ps)
{
	STDataType* cur;
	cur = (STDataType*)realloc(ps->_a, sizeof(STDataType)*ps->_capacity * 2);
	if (cur)
	{
		ps->_a = cur;
		ps->_capacity *= 2;
	}
	else
		printf("扩容失败");
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity - 1)
		ExtendMemory(ps);
	ps->_a[ps->_top + 1] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top];
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top + 1;
}



void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack ps;
	StackInit(&ps);
	BTNode* cur;
	BTNode* top;
	cur = root;
	while (StackSize(&ps) || cur)
	{
		while (cur)
		{
			StackPush(&ps, cur);
			printf("%c", cur->_data);
			cur = cur->_left;
		}
		
		top = StackTop(&ps);
		StackPop(&ps);
		cur = top->_right;
	}

}
void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack ps;
	StackInit(&ps);
	BTNode* cur;
	BTNode* top;
	cur = root;
	while (StackSize(&ps) || cur)
	{
		while (cur)
		{
			StackPush(&ps, cur);
			cur = cur->_left;
		}
		top = StackTop(&ps);
		StackPop(&ps);
		printf("%c", top->_data);

		cur = top->_right;


	}

}
void BinaryTreePostOrderNonR(BTNode* root)
{
	Stack ps;
	StackInit(&ps);
	BTNode* cur;
	BTNode* top;
	BTNode* prev=NULL;
	cur = root;
	while (StackSize(&ps) || cur)
	{
		while (cur)
		{
			StackPush(&ps, cur);
			cur = cur->_left;
		}
		top = StackTop(&ps);
		
		if (top->_right == NULL||prev==top->_right)
		{
			printf("%c", top->_data);
			StackPop(&ps);
			prev = top;
		}
		else
		{
			cur = top->_right;
		}
	}
}



void BTtest()
{
	char a[20] = "ABD##E#H##CF##G##";
	BTNode* cur;
	int i = 0;
	cur = BinaryTreeCreate(a, &i);

	printf("总个数为%d\n", BinaryTreeSize(cur));
	printf("叶子个数为%d\n", BinaryTreeLeafSize(cur));
	printf("3层个数为%d\n", BinaryTreeLevelKSize(cur,3));

	printf("%c\n", BinaryTreeFind(cur, 'B')->_data);

	BinaryTreePrevOrder(cur);
	printf("\n");
	BinaryTreeInOrder(cur);
	printf("\n");
	BinaryTreePostOrder(cur);
	printf("\n");
	BinaryTreeLevelOrder(cur);
	printf("\n");

	if (BinaryTreeComplete(cur))
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");

	BinaryTreePrevOrderNonR(cur);
	printf("\n");
	BinaryTreeInOrderNonR(cur);
	printf("\n");
	BinaryTreePostOrderNonR(cur);
	printf("\n");
	BinaryTreeDestory(&cur);

}


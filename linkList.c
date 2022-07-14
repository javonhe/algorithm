#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}LNode;

LNode *CreateListHead()
{
    LNode *listHead = (LNode *)malloc(sizeof(LNode));

    listHead->next = NULL;

    return listHead;
}

//创建新的节点
LNode *CreateNewNode(int data)
{
    LNode *newNode = (LNode *)malloc(sizeof(LNode));

    newNode->data = data;

    newNode->next = NULL;

    return newNode;
}

//打印链表
void printNode(LNode *listHead)
{

    LNode *listNode = listHead->next;

    while(listNode != NULL)
    {
        printf("%d\t", listNode->data);

        listNode = listNode->next;
    }
}

//链表插入：头部插入
void insertNodeByHead(LNode *listHead, int data)
{
    LNode *newNode = CreateNewNode(data);

    newNode->next = listHead->next;

    listHead->next = newNode;
}


//链表插入：尾部插入
void insertNodeBytail(LNode *listHead, int data)
{
    LNode *newNode = CreateNewNode(data);

    LNode *tail = listHead;

    while(tail->next != NULL)
        tail = tail->next;

    tail->next = newNode;
}


//链表插入：指定位置
void insertNodeByPoint(LNode *listHead, int data, int n)
{
    LNode *pointFront = listHead;
    LNode *point = listHead->next;

    while(point->data != n)
    {
        point = point->next;
        pointFront = pointFront->next;

        if (point == NULL)
            return;
    }

    LNode *newNode = CreateNewNode(data);

    pointFront->next = newNode;
    newNode->next = point;
}


//删除节点：头部删除
void deleteNodeByHead(LNode *listHead)
{
    LNode *deleteNode = listHead->next;

    listHead->next = deleteNode->next;

    free(deleteNode);

    deleteNode = NULL;
}


//删除节点：尾部删除
void deleteNodeByTail(LNode *listHead)
{
    LNode *frontNode = NULL;

    LNode *tailNode = listHead;

    while(tailNode->next != NULL)
    {
        frontNode = tailNode;

        tailNode = tailNode->next;

    }

    frontNode->next = NULL;

    free(tailNode);

    tailNode = NULL;
}


//删除节点：指定位置删除
void deleteNodeByPoint(LNode *listHead, int data)
{
    LNode *pointFront = listHead;

    LNode *point = listHead->next;

    while(point->data != data)
    {
        pointFront = pointFront->next;

        point = point->next;

        if (point == NULL)
            return;
    }

    pointFront->next = point->next;

    free(point);

    point = NULL;
}


int main(void)
{
    int n;

    LNode *listHead = CreateListHead();

    printf("plese input the num of data want to insert: ");
    scanf("%d", &n);

    printf("\nplease input the data want to insert: \n");

    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);

        //insertNodeByHead(listHead, data);
        insertNodeBytail(listHead, data);
    }

    printf("\n");

    printNode(listHead);

    printf("\n");

    //从头部删除一个数据
    deleteNodeByHead(listHead);
    printNode(listHead);

    printf("\n");

    //从尾部删除一个数据
    deleteNodeByTail(listHead);
    printNode(listHead);

    printf("\n");

    return 0;
}

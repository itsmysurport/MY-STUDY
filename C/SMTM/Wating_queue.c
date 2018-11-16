#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node //노드 정의
{
	char *data;
	struct Node *next;
}Node;


typedef struct Queue //Queue 구조체 정의
{
	Node *front; //맨 앞(꺼낼 위치)
	Node *rear; //맨 뒤(보관할 위치)
	int count;//보관 개수
}Queue;

void InitQueue(Queue *queue);//큐 초기화
int IsEmpty(Queue *queue); //큐가 비었는지 확인
void Enqueue(Queue *queue, char* data); //큐에 보관
void Dequeue(Queue *queue);
void printList(Queue *queue);
int SelectMenu();

int main(void)
{
	int i, j;
	int num;
	char *str = (char *)malloc((sizeof(char)) * 8);

	Queue queue;
	InitQueue(&queue);//큐 초기화

	while ((i = SelectMenu()) != 3) {
		switch (i) {
		case 1:
			printf("Input Your number of people : ");	scanf("%d", &num);
			for (j = 0; j < num; j++)
			{
				scanf("%s", str); Enqueue(&queue, str);
			}
			printf("Input Delete number of People : ");	scanf("%d", &num);
			for (j = 0; j < num; j++)	Dequeue(&queue);
				break;
		case 2: printList(&queue);  break;
		}
	}

	printf("\n");
	return 0;
}

void InitQueue(Queue *queue)
{
	queue->front = queue->rear = NULL; //front와 rear를 NULL로 설정
	queue->count = 0;//보관 개수를 0으로 설정
}

int IsEmpty(Queue *queue)
{
	return queue->count == 0;    //보관 개수가 0이면 빈 상태
}

void Enqueue(Queue *queue, char *data)
{
	Node *now = (Node *)malloc(sizeof(Node)); //노드 생성
	now->data = (char*)malloc(sizeof(char) * 8);
	strcpy(now->data, data);
	now->next = NULL;

	if (IsEmpty(queue))//큐가 비어있을 때
	{
		queue->front = now;//맨 앞을 now로 설정
	}
	else//비어있지 않을 때
	{
		queue->rear->next = now;//맨 뒤의 다음을 now로 설정
	}
	queue->rear = now;//맨 뒤를 now로 설정
	queue->count++;//보관 개수를 1 증가
}

void printList(Queue *queue)
{
	char *re = (char *)malloc((sizeof(char)) * 8);
	Node *now;

	while (1)//큐가 비지 않았을 때
	{
		now = queue->front;//맨 앞의 노드를 now에 기억
		if (!now)	break;
		strcpy(re, now->data);
		queue->front = now->next;//맨 앞은 now의 다음 노드로 설정
		printf("%s\n", re);
	}
	free(re);
	printf("\n");
	return;
}

int SelectMenu() {
	int i;
	printf(" 1. Input Name 2. Checking List 3.Exit\n====================================\n");
	scanf("%d", &i);
	return i;
}

void Dequeue(Queue *queue)
{
	Node *now;
	if (IsEmpty(queue))
	{
		printf("ERROR!\n");
		return;
	}
	now = queue->front;//맨 앞의 노드를 now에 기억
	queue->front = now->next;//맨 앞은 now의 다음 노드로 설정
	free(now);//now 소멸
	queue->count--;//보관 개수를 1 감소
}

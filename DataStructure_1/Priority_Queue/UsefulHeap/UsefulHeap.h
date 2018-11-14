//배열로 구현한 힙
#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE            1
#define FALSE           0

#define HEAP_LEN        100

typedef char HData;                       //HeapData
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp *comp;     //typedef int PriorityComp(HData d1, HData d2);
	int numOfData;
	HData heapArr[HEAP_LEN]; //typedef char HData;
} Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif

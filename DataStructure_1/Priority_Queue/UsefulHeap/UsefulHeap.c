#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap * ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

// 현재 노드의 부모노드 인덱스 찾기
int GetParentIDX(int idx)
{
	return idx / 2;
}

// 현재 노드의 왼쪽 자식노드 인덱스 찾기
int GetLChildIDX(int idx)
{
	return idx * 2;
}

// 현재 노드의 오른쪽 자식노드 인덱스 찾기
int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
	//자식 노드가 존재하지 않는다면,
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;

	//자식 노드가 왼쪽 자식 노드 하나만 존재한다면,
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	//자식 노드가 둘 다 존재한다면,
	else
	{
		/* 삭제 코드
		if (ph->heapArr[GetLChildIDX(idx)].pr
				> ph->heapArr[GetRChildIDX(idx)].pr)
		  return GetRChildIDX(idx);
		*/

		//오른쪽 자식 노드의 우선순위가 높다면, (왼쪽 > 오른쪽)
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)],
			ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		//왼쪽 자식 노드의 우선순위가 높다면, (왼쪽 < 오른쪽)
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, char data/*, int pr*/)
{
	int idx = ph->numOfData + 1;    //새노드가 저장될 인덱스 값을 idx에 저장

	// 새 노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복
	while (idx != 1)
	{
		// 새 노드와 부모 노드의 우선순위 비교
		//삭제: if (pr < (ph->heapArr[GetParentIDX(idx)].pr))   // 새 노드의 우선순위 높다면

		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			// 추가할(마지막)인덱스에 부모 노드 복사
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);  // 부모노드와 그 노드의 부모노드와 비교하기 위해 idx를 변경
		}
		else
			break;
	}

	ph->heapArr[idx] = data;  //nelem;
	ph->numOfData += 1;
}

char HDelete(Heap * ph)
{
	// 마지막에 삭제된 데이터를 return 하기 위해 백업
	char retData = (ph->heapArr[1]).data;
	/*
	 lastElem가 필요한 이유는 Heap을 비교를 하면서 정렬을 하는것이 아니라
	 parentInx에 ph->heapArr[ph->numOfData]가 있다고 가정하여 비교를 하면서 정렬을 한 후에
	 사라진 ph->heapArr[ph->numOfData]를 lastElem를 parentIdx에 넣기위해 백업해둔다.
	*/
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	//parentIdx는 이 함수에서 처음에는 1번을, 나중에는 lastElem가 저장될 위치를 가르킨다
	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		//삭제 if(lastElem.pr <= ph->heapArr[childIdx].pr) //마지막 노드와 우선순위 비교

		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;  //마지막 노드의 우선순위가 높으면 반복문 탈출

		// 마지막 노드보다 우선순위가 높으니, 비교대상 노드의 위치를 한 레벨 올린다.
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; //1번방 위치에 자식을 넣음
		parentIdx = childIdx; //마지막 노드가 저장될 위치 정보를 한 레벨 내림
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}

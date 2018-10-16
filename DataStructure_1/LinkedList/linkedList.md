Linked List
========


![screenshot](./images/linked_list.png)
> 연결리스트(*Linked List*)는 data와 next의 값을 가지고 있는 **노드** 가 이어져 있는 형태이다.

C 언어에서 구조체를 이용하여 이렇게 선언할 수 있다.

```c
typedef struct nNODE{
  int           nData;
  struct nNode  *next;
} NODE;
```

이렇게 작성할 수 있다.
여기서 struct nNode에 포인터 next를 이용해 다음 nNode를 가르키게 한다.

이것을 통해 코드를 작성해 보았다.

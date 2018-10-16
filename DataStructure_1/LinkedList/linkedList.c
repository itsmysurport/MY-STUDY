#include <stdio.h>
#include <stdlib.h>                               // For malloc function
#define MAX 8

int Dat[MAX]    =   {15, 22, 7, 3, 2, 99, 100, 30};

typedef struct nNODE{
  int               nData;
  struct nNODE      *next;
} NODE;

NODE *Head      =   NULL;                         // Dat Original
NODE *Head1     =   NULL;                         // Dat +5
NODE *Head2     =   NULL;                         // Dat -5

NODE *InsertNode(NODE *ptr, int Item){
  NODE *New     =   (NODE*)malloc(sizeof(NODE));
  New->nData    =   Item;                        // ' -> ' is Arrow Operator
  New->next     =   ptr;

  return New;
}

void PrintList(NODE *ptr){
  while(ptr->next){
    printf("%3d ", ptr->nData);
    ptr         =   ptr->next;
  }
  printf("%3d \n", ptr->nData);
}

int main(int argc, char const *argv[]) {
  int               i;
  NODE              *New;

  for (i = 0; i < MAX; i++) {
    Head        = InsertNode(Head, Dat[i]);
    Head1       = InsertNode(Head1, Dat[i]+5);
    Head2       = InsertNode(Head2, Dat[i]-5);
    PrintList(Head);
    PrintList(Head1);
    PrintList(Head2);
    printf("---------------------------\n");
  }

  New->nData    =   37;
  return            0;
}

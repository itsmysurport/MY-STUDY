#include <stdio.h>

int Lsearch(int ar[], int len, int target);

int main(int argc, char const *argv[])
{
  int nLength, nFind, i, nIndex;
  printf("Input LENGTH OF ARRAY you want.\n>>");
  scanf("%d", &nLength);

  int *pArr = (int*) malloc(sizeof(int) * nLength);
  for(i = 0; i < nLength; i++)
  {
    printf("[%d] is Selcted.\nINPUT >>", i);
    scanf("%d", &pArr[i]);
    for (int j = 0; j < i; j++)
    {
      if(pArr[i] == pArr[j])
      {
        printf("[!] ERROR, Retry\n");
        pArr[i] = NULL;
        i--;
      }
    }
  }
  printf("What do you want Index of Number? :");
  scanf("%d", &nFind);
  nIndex = Lsearch(pArr, nLength, nFind);

  if(nIndex == -1)	printf("Search failed\n");
  else printf("Index of %d is [%d].",nFind, nIndex);

  return 0;
}

int Lsearch(int ar[], int len, int target)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(ar[i] == target)
            return i;			//찾은 인덱스를 반환
    }
    return -1;					//찾지 못했음을 의미하는 -1을 반환
}

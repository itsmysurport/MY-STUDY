#include <stdio.h>

int BSearch(int ar[], int first, int last, int target);

int main(int argc, char const *argv[]) {
  int nLength, nFind, i, nIndex;
  printf("Input LENGTH OF ARRAY you want.\n>>");
  scanf("%d", &nLength);

  int *pArr = (int*) malloc(sizeof(int) * nLength);
  for(i = 0; i < nLength; i++)
  {
    printf("Please enter in alignment\n");
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

  nIndex = BSearch(pArr, 0, nLength-1, nFind);
  if(nIndex == -1)	printf("Search failed\n");
  else printf("Index of %d is [%d].",nFind, nIndex);

  return 0;
}

int BSearch(int ar[], int first, int last, int target)
{
    int mid, status;

    if(first>last)  return -1;
    else
    {
        mid = (first+last)/2;
        if(target == ar[mid])	return mid;
        else
        {
            if(target < ar[mid])	status = BSearch(ar, first, mid-1, target);
            else                  status = BSearch(ar, mid+1, last, target);
        }
    }
    return status;
}

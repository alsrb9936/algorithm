#include <stdio.h>
#include <stdbool.h>

bool visit[8] = {false};
int list[8];
int arr[8];
int n, m;

void backtrack(int cnt,int num);
void sortbubble(int * arr)
{
  int temp;
  int len = n;

  for(int i=0; i<len -1; i++)
  {
    for(int j=0; j<(len-1)-i; j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  
  scanf("%d %d",&n ,&m);
  for(int i =0; i<n; i++)
    scanf("%d",&arr[i]);
  sortbubble(arr);

  backtrack(0,0);

}

void backtrack(int cnt,int num) {
  if(cnt == m) {
    for(int i=0; i<m; i++)
    {
      printf("%d ",list[i]);
    }printf("\n");
  }

  for(int j=num; j<n; j++)
  {
    if(visit[j]==false)
    {
      visit[j] = true;
      list[cnt] = arr[j];
      backtrack(cnt+1,j);
      visit[j] = false;
    }
  }
  return;
}
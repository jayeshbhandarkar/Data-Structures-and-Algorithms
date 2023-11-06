#include <stdio.h>

int main()
{
   int i, first, last, mid, n, search, arr[100];

  printf("\nEnter Number of Elements: ");
  scanf("%d", &n);

  printf("Enter %d Integers in Sorted Order: ", n);

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("Enter value to find: ");
  scanf("%d", &search);

  first = 0;
  last = n -1;
  mid = (first+last)/2;

  while (first <= last) {
    if (arr[mid] < search)
      first = mid + 1;
    else if (arr[mid] == search)
    {
      printf("%d found at location %d.\n", search, mid+1);
      break;
    }
    else
      last = mid -1;

    mid = (first + last)/2;
  }
  if (first > last)
    printf("Not found! %d is not present in the list.\n", search);

  return 0;
}

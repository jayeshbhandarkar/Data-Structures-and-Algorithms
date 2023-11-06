#include<iostream>
#define max 50
using namespace std;

int partition(int arr[], int low, int up)
{ 
    int i=low+1, j=up, pvt=arr[low];
    while(i<=j)
    {
        while((arr[i]<pvt) && (i<up))
            i++;
        while(arr[j]>pvt)
            j--;
        if(i<j)
        {
            int temp= arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        else
            i++;
    }
    arr[low]=arr[j];
    arr[j]=pvt;
    return j;
}

void quick(int arr[], int low, int up)
{
    int pvt;
    if (low>=up)
        return;
    pvt=partition(arr,low,up);
    quick (arr,low,pvt-1);
    quick(arr,pvt+1,up);
}

int main()
{
    int arr[max], n, i;
    cout<<"\n Enter the No of Elements: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"\n Enter Element "<<i+1<<" : ";
        cin>>arr[i];
    }
    quick(arr, 0, n-1);
    cout<<"\n Sorted List is: ";
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
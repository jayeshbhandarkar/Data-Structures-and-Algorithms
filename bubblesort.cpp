#include<iostream>
using namespace std;
void bubblesort(int arr[]={10,1,7,6,14,9},int n=6)
{
    int i,j;
    for(i=1;i<n;i++){

        for(j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

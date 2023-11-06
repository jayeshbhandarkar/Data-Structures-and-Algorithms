#include<iostream>
using namespace std;
void select_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[minindex]>arr[j]){
                minindex=j;
            }
        }
        swap(arr[minindex],arr[i]);
    }
}
int main(){
    int arr[6]={1,7,9,2,3,0};
    select_sort(arr,6);
    for(int i=0;i<6;i++){
        cout<<" "<<arr[i];
    }
    return 0;
}
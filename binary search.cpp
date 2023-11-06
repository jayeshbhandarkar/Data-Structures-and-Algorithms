#include<iostream>
using namespace std; 
int main()
{ 
  int n, low, high, mid, key; 
  cout<<"\n Enter the size of an Array: ";
  cin>>n; 
  int a[n]; 
  low=0; 
  high=n-1; 
  cout<<"Enter the element of the array: ";  
  for(int i=0;i<n;i++) 
  {  
    cin>>a[i];
  } 
  cout<<"Enter a key to search: ";  
  cin>>key;
  while(low<=n-1) 
  { 
    mid=(low+ high)/2;  
    if(key==a[mid]) 
    {  
      cout<<key<<" found at index no. "<<mid;  
      break; 
    } 
    if(key<mid)
      high=mid - 1;  
    if(key>mid) 
      low=mid+1;  
    if(low>high)  
      cout<<key<<" not found in the list"; 
  }
  return 0; 
}  
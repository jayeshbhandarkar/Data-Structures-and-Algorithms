#include<iostream>
using namespace std; 
int main()
{
    int n;
    cout<<"Enter the No of Element: ";
    cin>>n;     
    int ar[n], i, min, max; 
    cout<<"\n Enter the Elements: ";
    for(i=0;i<=n-1;i++) 
    {
        cin>>ar[i]; 
    }

    min=max=ar[0]; 
    for(int i=1;i<=n-1;i++) 
    {  
        if (ar[i]<min)    
            min=ar[i];  
        if (ar[i]>max)    
            max=ar[i];  
    }   

    cout<<"\n Minimum Number is: "<<min;      
    cout<<"\n Maximum Number is: "<<max;  
    return 0; 
} 

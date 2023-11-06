#include<iostream>
using namespace std;
#define MAX 50
int main ()
{
    int i, j, n, position, temp;
    int ar[MAX];
    cout<<"Enter the Number of Elements in array: ";
    cin>>n;

    cout<<"Enter the elements in array: ";
    for(i = 0; i<n; i++)
    {
        cin>>ar[i];
    }
    for(i = 0; i<n; i++)
    {
        position = i;
        for(j = i +1; j<n; j++)
        {
            if(ar[position] > ar[j])
            position = j;
        }
        if(i != position)
        {
            temp =ar[i];
            ar[i] = ar[position];
            ar[position] = temp;
        }
    }
    cout<<"Sorted list is: \n";
    for(i = 0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
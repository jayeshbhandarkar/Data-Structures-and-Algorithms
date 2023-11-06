#include<iostream>
#define size 100
using namespace std;
void merge(int a1[], int a2[], int a3[], int n1, int n2);
int main()
{
    int a1[size]; int a2[size];int a3[2*size];int n1;int n2;
    cout<<"\n Enter the size of Array 1: ";
    cin>>n1;
    cout<<"\n Enter all the Elements of the Array 1 in Sorted Order: ";
    for(int i=0;i<=n1-1;i++)
    {
        cin>>a1[i];
    }
    cout<<"Enter the size of Array 2: ";
    cin>>n2;
    cout<<"\n Enter all the Elements of the Array 2 in Sorted Order: ";
    for(int j=0;j<=n2-1;j++)
    {
        cin>>a2[j];
    }
    merge(a1, a2, a3, n1, n2);
    cout<<"\n Merged List: ";
    for(int i=0; i<n1+n2; i++)
    {
        cout<<a3[i]<<" ";
    }
    return 0;
}

void merge(int a1[], int a2[], int a3[], int n1, int n2)
{
    int i=0;    // Index for first array
    int j=0;    // Index for second array
    int k=0;    // Index for merged array
    while((i<=n1-1)&&(j<=n2-1))
    {
        if(a1[i]<a2[j])
            a3[k++]=a1[i++];
        else
            a3[k++]=a2[j++];
    }

    // Put remaining elements of a1 into a3
    while(i<=n1-1)
        a3[k++]=a1[i++];

    // Put remaining elements of a2 into a3
    while(j<=n2-1)
        a3[k++]=a2[j++];
}
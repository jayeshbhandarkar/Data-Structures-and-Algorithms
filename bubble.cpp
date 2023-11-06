#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) ;

int main() 
{
    int n,i;
    cout << "Enter the number of elements: ";
    cin >>n;

    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (i = 0; i < n; i++) 
    {
        cout <<arr[i] << " ";
    }
    cout <<endl;
    return 0;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1 ; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
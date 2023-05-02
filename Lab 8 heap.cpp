#include <iostream>
using namespace std;

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}

void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout<<"Input array"<<endl;
    displayArray(arr, n);
  
    heapSort(arr, n);
  
    cout << "Sorted array"<<endl;
    displayArray(arr, n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;


    

int PARENT(int i) {
    return (i - 1) / 2;
}

int LEFT(int i) {
    return (2*i + 1);
}

int RIGHT(int i) {
    return (2*i + 2);
}

void heapify(int a[], int N, int i)
{
    int largest = i; 
    int left = LEFT(i);
    int right = RIGHT(i);
 
    //left child is larger than root
    if (left < N && a[left] > a[largest])
        largest = left;
 
    //right child is larger than largest so far
    if (right < N && a[right] > a[largest])
        largest = right;
 
    //largest is not root
    if (largest != i) {
        swap(a[i], a[largest]);
 
        //recursion to heapify subtree
        heapify(a, N, largest);
    }
}

void maxHeap(int a[], int N)
{
    
    int nonlIndex = (N / 2) - 1;
 
    //iterate from last non-leaf node
    for (int i = nonlIndex; i >= 0; i--) {
        heapify(a, N, i);
    }
}

void heapSort(int a[], int N)
{
    for (int i = N - 1; i >= 0; i--) {
        //swap root to last element
        swap(a[0], a[i]);
 
        //heapify
        heapify(a, i, 0);
    }
}

void printHeap(int a[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << "\n";
}
void printDescHeap(int a[], int N)
{
    for (int i = N - 1; i >= 0; --i)
        cout << a[i] << " ";
    cout << "\n";

}
 


int main()
{
    int a[100] , n = -1;
    for(int i = 0 ; ; i++)
    {
        cin>>a[i];
        n++;
        if(a[i] == -1)
            break;
        
    }

    
    maxHeap(a,n);
    printHeap(a,n);
    heapSort(a,n);
    printDescHeap(a,n);





    return 0;
}
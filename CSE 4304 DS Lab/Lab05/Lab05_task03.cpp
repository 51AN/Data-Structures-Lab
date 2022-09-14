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
    if (left < N && a[left] < a[largest])
        largest = left;
 
    //right child is larger than largest so far
    if (right < N && a[right] < a[largest])
        largest = right;
 
    //largest is not root
    if (largest != i) {
        swap(a[i], a[largest]);
 
        //recursion to heapify subtree
        heapify(a, N, largest);
    }
}

void minHeap(int a[], int N)
{
    
    int nonlIndex = (N / 2) - 1;
 
    //iterate from last non-leaf node
    for (int i = nonlIndex; i >= 0; i--) {
        heapify(a, N, i);
    }

}

int heap_minimim(int a[])
{
    return a[0];
}

int heap_extractmin(int a[], int N)
{

    for(int i = 1 ;i<N ;i++)
    {
        a[i-1] = a[i];
    }

    a[N-1] = 0;

    minHeap(a, N-1);


    return a[0];
} 

void minHeapInsert(int val, int a[], int N)
{
    a[N] = val;
    minHeap(a,N + 1);

    
}

void printHeap(int a[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << "\n";
}


int main()
{
    int n , k;
    cin>>n>>k;

    int *a;
    for(int i = 0 ; i<n ; i++)
    {
        cin>>a[i];
    }
    minHeap(a,n);
    printHeap(a,n);

    int cnt = 0;
    // while(heap_minimim(a)<=k)
    // {
    //     int temp = 0;
    //     temp = heap_extractmin(a,n) + (2 * heap_extractmin(a,(n-1)));
    //     minHeapInsert(temp,a,(n-2));
    //     --n;
    //     ++cnt;
    // }

    while(n!=0)
    {
        int check = heap_minimim(a);

        if(check>7)
            break;

        int val = 0;

        int firstL = 0, secondL = 0;
        
        firstL = heap_extractmin(a,n);
        --n;

        if(n == 0)
            break;

        secondL = heap_extractmin(a,n);
        --n;


        val = firstL + (2*secondL);


        minHeapInsert(val, a, n);
        ++n;

        ++cnt;


    }

    cout<<cnt;

    

}
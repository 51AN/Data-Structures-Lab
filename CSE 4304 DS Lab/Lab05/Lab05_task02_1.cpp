#include<bits/stdc++.h>
using namespace std;


    

int PARENT(int i) {
    return (i) / 2;
}

int LEFT(int i) {
    return (2*i );
}

int RIGHT(int i) {
    return (2*i + 1);
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
    
    int nonlIndex = (N / 2);
 
    //iterate from last non-leaf node
    for (int i = nonlIndex; i > 0; i--) {
        heapify(a, N, i);
    }

}


void printHeap(int a[], int N)
{
    for (int i = 1; i <= N; ++i)
        cout << a[i] << " ";
    cout << "\n";
}


int heap_minimim(int a[])
{
    return a[1];
}

int heap_extractmin(int a[], int N)
{

    for(int i = 2 ;i<=N ;i++)
    {
        a[i-1] = a[i];
    }

    a[N] = 0;


    return a[1];
} 


void minHeapInsert(int val, int a[], int N)
{
    a[N + 1] = val;
    minHeap(a,N + 2);

    
}



int main()
{
    int a[100] , n = -1;
    for(int i = 1 ; ; i++)
    {
        cin>>a[i];
        n++;
        if(a[i] == -1)
            break;
        
    }



    minHeap(a,n);
    printHeap(a,n);
   
    int input = 51;

    while(true)
    {
        cin>>input;

        if(input == 1)
        {
            cout<<heap_minimim(a)<<endl;
            printHeap(a,n);
        }
        else if(input == 2)
        {
            cout<<heap_extractmin(a,n)<<endl;
            --n;
            printHeap(a,n);
        }
        else if(input == 3)
        {
            int x;
            cin>>x;
            minHeapInsert(x,a,n);
            ++n;
            printHeap(a,n);


        }
        else
        {
            break;
        }
    }






    return 0;
}
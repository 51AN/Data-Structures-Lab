#include <iostream>
using namespace std;

void updateBIT(int BIT[], int n, int index, int val)
{
    
    index = index + 1;// index of BIT[] is 1 more than that of the provided array

    while (index <= n)
    {
        BIT[index] += val; //update target index
        index += index & (-index); //move to the next affected index
    }
}
 
int *generateBIT(int arr[], int n)
{
    int *BIT = new int[n+1];
    for (int i=1; i<=n; i++)
        BIT[i] = 0;

    for (int i=0; i<n; i++)
        updateBIT(BIT, n, i, arr[i]);
 
 
    return BIT;
}

int getSum(int BIT[], int index)
{
    int sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BIT[index];
        index -= index & (-index); //move to the next valid index in range
    }
    return sum;
}

int rangeQuery(int BIT[],int l, int r){
    return (getSum(BIT,r) - getSum(BIT,l-1));
}
 

int main()
{
    int arr[] = {1,3,1,2,4,0,5};
    
    int *BIT = generateBIT(arr,7);
    cout<<"\n"<<"Summation from 0th...4th index :"<<getSum(BIT, 4);
    cout<<"\n"<<"Summation from 2nd...4th index :"<<rangeQuery(BIT, 2, 4);

    updateBIT(BIT, 7, 3, 6);
    cout<<"\n"<<"After update on 3rd index";
    cout<<"\n"<<"Summation from 0th...4th index :"<<getSum(BIT, 4);
    cout<<"\n"<<"Summation from 2nd...4th index :"<<rangeQuery(BIT, 2, 4);

    return 0;
}
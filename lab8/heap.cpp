#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int left = (2*root) + 1; 
   int right = (2*root) + 2; 
   int largestElement = root; 
 
   //checking whether the left child is larger than the root
   if (left < n && arr[left] > arr[largestElement])
      largestElement = left;
 
   //checking whether the right child is larger than the root
   if (right < n && arr[right] > arr[largestElement])
      largestElement = right;
 
   //checking whether the largest element is not equal to the root
   if (largestElement != root) {
      swap(arr[root], arr[largestElement]);
   
   //calling the heapify function recursively
   heapify(arr, n, largestElement);
   }
   
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   //building the max heap from the input array by startting from the last non-leaf node
   for (int i = (n / 2) - 1; i >= 0; i--)
      heapify(arr, n, i);

   
   int i = (n - 1);
   //sorting the input array 
   while (i > 0) {
        
      swap(arr[0], arr[i]);
      i--;

      heapify(arr, i+1, 0);
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n;
   cout << "Enter the size of the array: ";
   cin >> n;
   int heap_arr[n];
   //enter the elements in the array as each element is seperated by a single white space
   cout << "Enter the elements of the array: ";
   for (int i = 0; i < n; i++) {
      cin >> heap_arr[i];
   }
   cout << "Input array: "<<endl;
   displayArray(heap_arr, n);

   heapSort(heap_arr, n);
   cout<<"----------------"<<endl;
   cout << "Sorted array: "<<endl;
   displayArray(heap_arr, n);
   return 0;
}
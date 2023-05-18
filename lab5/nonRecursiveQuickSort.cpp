#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

int lengthArray = 100;
using namespace std::chrono;



#include <iostream>
#include <stack>
using namespace std;

void quickSort(int arr[], int left, int right) {
    stack<int> stk;
    stk.push(left);
    stk.push(right);

    while (!stk.empty()) {
        right = stk.top();
        stk.pop();
        left = stk.top();
        stk.pop();

        int i = left, j = right;
        int pivot = arr[(left + right) / 2];

        // Partition the array
        while (i <= j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        // Push subarrays onto stack for sorting
        if (left < j) {
            stk.push(left);
            stk.push(j);
        }
        if (i < right) {
            stk.push(i);
            stk.push(right);
        }
    }
}



int main() {
    int newArray[lengthArray];
    int originalArray[lengthArray];
    
    double sum=0;
    
    srand(time(NULL));
    
    for (int i = 0; i < lengthArray; i++)
        {
            
            originalArray[i] = rand();

        }
        
    //int newArray[sizeof(originalArray)/sizeof(originalArray[0])];
    
    // Copy the contents of the original array to the new array
    for (int i = 0; i < sizeof(originalArray)/sizeof(originalArray[0]); i++) {
        newArray[i] = originalArray[i];
    }

    for (int r = 0;r<100;r++){
        
    
        
    
 
    auto start = high_resolution_clock::now();
    quickSort(newArray, 0 , lengthArray);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    sum += duration.count();
}
    
    
    cout<<"Average Run time of the non-recursive Quick sort : "<<sum/100;


    
  return 0;
}


#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
class Stack_Array{
    private:
    static int size;
    int top = -1;
    int* stack_arr;

    public:
    Stack_Array(int size)
    {
        this->size = size;
        stack_arr = new int(size);
        
    }
    ~Stack_Array()
    {
        delete[] stack_arr;
    }
    void push_array(int push_element);
    int pop_array();
    bool isEmpty_array();
    bool isFull_array();
    void DisplayStack_array();
    void clear();
};
bool Stack_Array::isEmpty_array()
{
    return (top == -1);
}
bool Stack_Array::isFull_array()
{
    return (top == size-1);
}
void Stack_Array::push_array(int push_element)
{
    if (top >= size){
        cout<<"Occurance of Stack Overflow";

    }
    else{
        top++;
        stack_arr[top] = push_element;
    }

}
int Stack_Array::pop_array()
{
    if (top <= -1){
        cout<<"Occurance of Stack Underflow";
    }
    else{
        int ElementPopped = stack_arr[top];
        top--;
        return ElementPopped;

    }
    return -1;
}
void Stack_Array::DisplayStack_array()
{
    if (top>=0){
        cout<<"Current Stack implemented by array is: ";
        for(int i = top ; i >=0 ; i--){
            cout<<stack_arr[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"Stack is empty";
    }
}

void Stack_Array::clear()
{
   top = -1; 
}
int Stack_Array::size; // to define the static variable 
int main() 
{
    
    int originalArray[14];
    int element,element1;

    Stack_Array* stack_array = new Stack_Array(10);
    srand(time(NULL));
    for (int i = 0 ; i<14 ; i++){
        originalArray[i]=rand();

    }
    for (int k=0 ; k<10 ; k++){
            stack_array-> push_array(originalArray[k]);

        }
    stack_array->DisplayStack_array();
    for (int x = 0 ; x<5 ; x++){
            stack_array->pop_array();
        }
    stack_array->DisplayStack_array();
    for (int z = 10 ; z<14 ; z++){
            stack_array-> push_array(originalArray[z]);
        }
    stack_array->DisplayStack_array();
     delete(stack_array);
    

    return 0;
}

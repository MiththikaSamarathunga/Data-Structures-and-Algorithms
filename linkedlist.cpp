#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
// to create the nodes of singly linked list
class Node{
    
    public:
    int element;
    Node* next;
    Node(int element){
        this-> element = element;
        this->next = NULL;
    }
};

class Stack_list {
    
    Node* top = NULL;
    
    public:

    
    
    void push_list(int push_element);
    int pop_list();
    bool isEmpty_list();
    bool isFull_list();
    void DisplayStack_list();
    void clear_list();

    ~Stack_list() {
        Node* temp = top;
        while (temp != NULL) {
            Node* current = temp;
            temp = temp->next;
            delete current;
        }
        top = NULL;
    }


};
void Stack_list::push_list(int push_element)
{
    Node* newNode = new Node(push_element);
    if (top ==NULL){
        top = newNode;

    }
    else{
        newNode->next = top;
        top = newNode;
    }


}
int Stack_list::pop_list(){
    if (top == NULL ){
        return -1;
    }
    else{
        Node* poppedElement = top;
        top = top->next;
        poppedElement->next = NULL;
        return (poppedElement->element);
    }

}
bool Stack_list::isEmpty_list(){
    return (top == nullptr);
}
bool Stack_list::isFull_list(){
    // no use of implementing this method because linked list are dynamically growing
    return -1;
}
void Stack_list::DisplayStack_list() {
   struct Node* pointer;
   if(top==NULL)
   cout<<"The stack is empty";
   else {
      pointer = top;
      cout<<"Current Stack is: ";
      while (pointer != NULL) {
         cout<< pointer->element<<" ";
         pointer = pointer->next;
      }
   }
   cout<<endl;
}
void Stack_list::clear_list()
{
   while (!isEmpty_list()) {
        pop_list();
    }
}
int main() 
{
    int originalArray[14];
    int element,element1;
    Stack_list* stack_list = new Stack_list();
    srand(time(NULL));
    for (int i = 0 ; i<14 ; i++){
        originalArray[i]=rand();

    }
    for (int k=0 ; k<10 ; k++){
            stack_list-> push_list(originalArray[k]);

        }
        stack_list->DisplayStack_list();
        for (int x = 0 ; x<5 ; x++){
            stack_list->pop_list();
        }
        stack_list->DisplayStack_list();
        for (int z = 10 ; z<14 ; z++){
            stack_list-> push_list(originalArray[z]);
        }
        stack_list->DisplayStack_list();

        delete(stack_list);
    

    return 0;
}
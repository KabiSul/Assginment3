#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* top = NULL;

void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}
void pop() {
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< top->data <<endl;
      top = top->next;
   }
}
void numel() {
   struct Node* temp = top;
   int count = 0;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      cout<<"Number of elements is: ";
      while (temp != NULL) {
         temp = temp ->next;
         count++;
         
      }
      cout << count;
   }
   cout<<endl;
   
}
void searchList(int searchValue) {
  Node* temp = top;
  int found = 0;
  int i = 0;
 
  if(temp != NULL) {
    while(temp != NULL) {
      i++;
      if(temp->data == searchValue) {
        found++;
        break;
      }
      temp = temp->next;
    }
    if (found == 1) {
      cout<<searchValue<<" is found at index = "<<i<<".\n";
    } else {
      cout<<searchValue<<" is not found in the list.\n";
    }
  } else {
    cout<<"The list is empty.\n";
  }
} 
void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}
void displayfirst() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Top element is: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         break;
      }
   }
   cout<<endl;
}
int main() {
   int ch, val,n;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display elements"<<endl;
   cout<<"4) Display number of elements"<<endl;
   cout<<"5) Search value"<<endl;
   cout<<"6) Display top element"<<endl;
   cout<<"7) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
             numel();
             break;
         }
         case 5: {
             cout<<"Enter value to be searched:"<<endl;
             cin>>n;
             searchList(n);
             break;
         }
         case 6: {
            displayfirst();
            break;
         }
         case 7: {
            cout<<"Exit"<<endl;
            break;
         }
         
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=7);
   return 0;
}

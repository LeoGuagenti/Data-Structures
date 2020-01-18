/*
  Project 1 - CS3610
  Leo Guagenti
  1/16/2020

  Implementation of the 'LinkedList' class,
  This implementation includes the 'push_front', 
  'pop_front', 'reverse', and 'print' functions outlined
  in the project description.
*/

#include <iostream>

template <typename T>
class LinkedList {
  public:
    //constructor
    LinkedList() : head(NULL) {}

    //deconstructor
    ~LinkedList(){
      ListNode* current;
      //free memory of all nodes connected to head
      while(head != NULL){
        current = head;
        head = head->next;
        delete current;
      }
    }

    //adds an element to the beginning of the list
    void push_front(const T data){
      if(head == NULL){
        head = new ListNode(data);  //if no head exists create the head
      }else{
        //add node to front and reassign head pointer
        ListNode* node = new ListNode(data); 
        node->next = head;
        head = node;
      }
    }
    
    //removes the first element of the list
    void pop_front(){
      if(head == NULL){
        std::cout << "Empty." << std::endl; //indicate that the list has no elements
      }else if(head->next == NULL){
        head = NULL;  //remove head if head is the only element of the list
      }else{
        //remove head element and reassign head pointer
        ListNode* temp = head;
        head = head->next;
        delete temp;
      }
    }
  
    //reverses the list
    void reverse(){
      if(head == NULL){
        std::cout << "Empty." << std::endl; //indicate that the list has no elements
        return;
      }

      //creation of pointers
      ListNode* current = head;
      ListNode* last = NULL;
      ListNode* next = NULL;

      //iterate through the list and reverese the direction
      while(current != NULL){
        next = current->next;
        current->next = last;

        last = current;
        current = next;
      }
      //set head to new beginning element;
      head = last;
    }

    //prints the list
    void print() const {
      if(head == NULL){
          std::cout << "Empty." << std::endl; //indicate that the list has no elements
          return;
      }

      ListNode* currentNode = head;
      //iterate through the list and print the value of each element 
      while(currentNode != NULL){
          std::cout << currentNode->data << " ";
          currentNode = currentNode->next;
      }
      std::cout << std::endl;
    }

  private:
    struct ListNode {
      ListNode(const T data) : data(data), next(NULL) {}

      T data;
      ListNode* next;
    };

  ListNode* head;
};
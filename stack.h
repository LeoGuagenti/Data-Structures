#include <iostream>

template <typename Type>
class Stack {
    public:
        Stack();
        ~Stack();

        void push(const Type data);
        void pop();
        void display();
        void empty();
        Type peek();
        int size();

    private:
        struct Layer {
            Layer(const Type data) : data(data), next(NULL) {};

            Type data;
            Layer* next;
        };
        Layer* top;
};

template <class Type>
Stack<Type>::Stack(){
    top = NULL;
}

template <class Type>
Stack<Type>::~Stack(){

}

template <class Type>
void Stack<Type>::push(const Type data){
    if(top == NULL){
        top = new Layer(data);
        return;
    }

    Layer* layer = new Layer(data);
    Layer* temp = top;
    layer->next = temp;
    top = layer;
}

template <class Type>
void Stack<Type>::pop(){
    Layer* temp = top;
    top = top->next;
    delete temp;
}

template <class Type>
void Stack<Type>::display(){
    if(top == NULL){
        std::cout << "Empty Stack" << std::endl;
        return;
    }

    Layer* ptr = top;
    while(ptr != NULL){
        std::cout << ptr->data << std::endl;
         ptr = ptr->next;
    }
}

template <class Type>
void Stack<Type>::empty(){
    if(top == NULL){
        std::cout << "Empty Stack" << std::endl;
        return;
    }

    Layer* temp = top;
    while(top != NULL){
        top = top->next;
        delete temp;
        temp = top;
    }
}

template <class Type>
Type Stack<Type>::peek(){
    if(top == NULL){
        std::cout << "Empty Stack" << std::endl;
        return NULL;
    }
    return top->data;
}

template <class Type>
int Stack<Type>::size(){
    if(top == NULL){
        return 0;
    }

    int count = 0;
    
    Layer* ptr = top;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }

    return count;
}
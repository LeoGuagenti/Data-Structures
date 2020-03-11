/**
 * Leo Guagenti
 * 3/4/20
 *
 * min_heap.h
 * 
 * This is the class declaration and implementation for the MinHeap class
*/

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
struct HeapNode {
  HeapNode(const T data, const int key) : data(data), key(key) {}
  bool operator<(const HeapNode<T>& rhs) {return this->key < rhs.key;}
  bool operator<=(const HeapNode<T>& rhs) {return this->key <= rhs.key;}

  T data;
  int key;
};

template <typename T>
class MinHeap {
  public:
    MinHeap() {};
    ~MinHeap() {};

    void insert(const T data, const int key);
    T extract_min();
    T peek() const;
    int size() const;
    void print();

  private:
    vector<HeapNode<T> > heap;
};


/**
 * Inserts a Heapnode into 'heap'
 * 
 * @param data the 'content' value of node to be inserted
 * @param key a non-distinct value associated with a value
*/
template <typename T>
void MinHeap<T>::insert(const T data, const int key){
  //add node to end of heap
  heap.push_back(HeapNode<T>(data, key));

  int currentIndex = heap.size() - 1;
  while(!(heap[(currentIndex - 1) / 2] <= heap[currentIndex])){
      //if parent is larger than current, swap, and update index
      swap(heap[currentIndex], heap[(currentIndex - 1) / 2]);
      currentIndex = ((currentIndex - 1) / 2);
  }
}

/**
 * Removes the smallest elements from the heap 
 * while maintaining a valid structure
 * 
 * @return the smallest element in the heap, if it exists
*/
template <typename T>
T MinHeap<T>::extract_min(){
  T data = heap[0].data;
  int currentIndex = 0;

  //remove and replace root with the 'heap's' last node
  swap(heap[0], heap[heap.size() - 1]);
  heap.pop_back();

  
  while(currentIndex * 2 + 2 <= heap.size() &&                  //right child 1 past max size and
       ((heap[(currentIndex * 2) + 1] < heap[currentIndex]) ||  //left child < current parent or
        (currentIndex * 2 + 2 < heap.size() &&                  //right child exits and
        heap[(currentIndex * 2) + 2] < heap[currentIndex]))     //right child < current parent
       ){
    if(currentIndex * 2 + 2 < heap.size() && (heap[(currentIndex + 2) + 2] <= heap[(currentIndex * 2) + 1])){
      //if right child is less than the current parent, and the right child is <= the left child
      //swap right and parent and update current index
      swap(heap[currentIndex], heap[(currentIndex * 2) + 2]);
      currentIndex = (currentIndex * 2) + 2;

    }else{
      //swap left and parent and update current index
      swap(heap[currentIndex], heap[(currentIndex * 2) + 1]);
      currentIndex = (currentIndex * 2) + 1;
    }
  }
  return data;
}

/**
 * Returns the root of the heap
 * 
 * @return the root of the vector 'heap', if it exists
*/
template <typename T>
T MinHeap<T>::peek() const { 
  T data;
  if(heap.size() == 0){
      return data;
  }else{
      return heap[0].data;
  }
};

/**
 * Returns size of the heap
 * 
 * @return the size of the vector 'heap'
*/
template <typename T>
int MinHeap<T>::size() const { 
  return heap.size(); 
};

/**
 * Prints the vector 'heap' in preorder
*/
template <typename T>
void MinHeap<T>::print() {
  //iterates through each element of the 'heap'
  for(unsigned int i = 0; i < heap.size(); i++){
    cout << heap[i].data << " "; 
  }
  cout << "\n" << endl;
}

#endif
#include <cstddef>

namespace CS270 {
template<class T>
class forward_list {
 private:
  class Node {
   public:
    T data;
    Node* next;
    Node(const T& v, Node* n) : data(v), next(n) {}
  };

  //Pointer to the beginning of the linked list
  Node* head;

  //Prevent copy and assignment by declaring private functions (implementations not needed)
  forward_list& operator=(forward_list& other);
  forward_list(const forward_list &other);

 public:
  // Constructor
  forward_list();
  
  // Destructor
  ~forward_list();

  //Insert an item at the beginning of the list
  void push_front(const T& v);

  //Returns the value at the head of the list
  T& front();

  //Remove the first item from the list
  void pop_front();

  //Check if a list is empty
  bool empty();

  //Remove items matching val from the list
  void remove(const T& val);

};

}

#include "ll.ipp"

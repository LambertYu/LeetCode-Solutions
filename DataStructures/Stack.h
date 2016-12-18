#include <iostream>

template <class T>
class node{
public:
  node(const T& v) : value(v), next(NULL) {}
  T value;
  node<T>* next;
};

template <class T> class Stack;

template <class T>
class Stack{
private:
    node<T>* top;
    int count,length;

public:
    Stack(int size){
        count = 0;
        length = size;
        top = NULL;
    }
    ~Stack(){
      while(top){
        node<T>* tmp = top;
        top = top->next;
        delete tmp;
      }
    }

    void push(const T& v){
      if(count == length) {
        std::cout << "Stack Overflow" << '\n';
        return;
      }
      count++;
      node<T>* new_node = new node<T>(v);
      new_node->next = top;
      top = new_node;
    }
    T pop(){
      if(count == 0){
        std::cerr << "Stack Underflow" << '\n';
      }
      T cur = top->value;
      node<T>* tmp = top->next;
      delete top;
      top = tmp;
      return cur;
    }

};

// int main(){
//   Stack<int> stack(10);
//   stack.push(1);
//   stack.push(2);
//   stack.push(3);
//   stack.push(4);
//   int a = stack.pop();
//   std::cout << a << '\n';
// }

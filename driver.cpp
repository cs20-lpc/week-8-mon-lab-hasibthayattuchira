#include "ArrayStack.hpp"
#include <iostream>
using namespace std;

template <typename T>
void rotate(ArrayStack<T>& stack){
    cout << "Before rotate: " << stack;
    stack.rotate(ArrayStack<T>::RIGHT);
    cout << "After rotate right: " << stack;
    stack.rotate(ArrayStack<T>::LEFT);  
    cout << "After rotate left: " << stack;
}

int main(){
    // integer stack test
    cout << "integer stack test" << endl;

    ArrayStack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    cout << "pushed 1,2,3: " << intStack;
    cout << "top: " << intStack.peek() << endl;
    
    intStack.pop();
    cout << "after one pop: " << intStack;
    
    intStack.push(4);
    intStack.push(5);
    cout << "pushed 4,5: " << intStack;

    rotate(intStack);

    intStack.clear();
    cout << "after clear: " << intStack;

    // strings test
    cout << "string stack test" << endl;

    ArrayStack<string> stringStack(4);
    stringStack.push("green apple");
    stringStack.push("red banana");
    stringStack.push("blue apple");

    cout << "pushed three apples: " << stringStack;
    cout << "top: " << stringStack.peek() << endl;

    stringStack.pop();
    cout << "after one pop: " << stringStack;

    rotate(stringStack);

    // terminate
    return 0;
}
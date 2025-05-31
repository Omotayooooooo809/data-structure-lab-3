#include <iostream>

#define MAX_SIZE 100

template<typename T>
class ArrayStack {
    T data[MAX_SIZE];
    int topIndex = -1;

public: 
    void push(T value) {
        if (topIndex >= MAX_SIZE-1) throw "Stack overflow";
        data[++topIndex] = value;
    }

    void pop() {
        if (isEmpty()) throw "Stack underflow";
        topIndex--;
    }

    T top() const { 
        if (isEmpty()) throw "Stack is empty";
        return data[topIndex]; 
    }
    
    bool isEmpty() const { return topIndex == -1; }
};

int main() {
    ArrayStack<int> stack;
    
    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);
        
        std::cout << "Top element: " << stack.top() << std::endl;
        
        stack.pop();
        std::cout << "Top element after pop: " << stack.top() << std::endl;
        
        stack.pop();
        stack.pop();
        
        if (stack.isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
        }
        
        // This will throw an exception
        stack.pop();
    }
    catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }
    
    return 0;
}

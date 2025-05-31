#include <iostream>

template<typename T>
class ListNode {
public: 
    T data;
    ListNode* next;
    ListNode(T val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedListStack {
    ListNode<T>* head = nullptr;

public: 
    void push(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (isEmpty()) throw "Stack underflow";
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T top() const { 
        if (isEmpty()) throw "Stack is empty";
        return head->data; 
    }
    
    bool isEmpty() const { return head == nullptr; }
};

int main() {
    LinkedListStack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    return 0;
}

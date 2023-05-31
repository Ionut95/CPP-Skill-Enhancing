#include <iostream>

struct Node {
    int value;
    Node *next;
};

class LinkedList {
    Node *head;
    Node *tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    void create_node(int value) {
        Node *temp = new Node();
        temp->value = value;
        temp->next = nullptr;
        
        if(head) {
            tail->next = temp;
            tail = temp;
        } else {
            head = temp;
            tail = temp;
        }
    }
    
    void print_list() const {
        Node *current_node = head;
        while(current_node != nullptr) {
            std::cout << current_node->value << " ";
            current_node = current_node->next;
        }
        std::cout << std::endl;
    }
    
    void push_node(int value) {
        Node *new_head = new Node();
        
        new_head->value = value;
        new_head->next = head;
        
        head = new_head;
    }
    
    void push_back(int value) {
        create_node(value);
    }
    
    void insert_at_pos(int pos, int value) {
        Node *prev = new Node;
        Node *cur = new Node;
        Node *temp = new Node;
        cur = head;
        
        for(int i = 1; i < pos; ++i) {
            if(cur->next == nullptr) {
                std::cout << "Position out of bound try less" << std::endl;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        
        temp->value = value;
        prev->next = temp;
        temp->next = cur;
    }
    
    void pop() {
        Node *new_head = new Node;
        new_head = head->next;
        delete head;
        head = new_head;
    }
    
    void pop_back() {
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        
        Node *current = head;
        while(current->next->next != nullptr) {
            current = current->next;
        }
        
        delete current->next;
        current->next = nullptr;
    }
    
    void remove_by_index(int n) {
        if (n == 1) {
            pop();
            return;
        }
        
        Node *current = head;
        for(int i = 0; i < n - 1; ++i) {
            if(current->next == nullptr) {
                std::cout << "Out of bound, try less" << std::endl;
                return;
            }
            current = current->next;
        }
        
        if (current->next == nullptr) {
            pop_back();
            return;
        }
        
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        
    }
};

int main()
{
    LinkedList list;
    list.create_node(1);
    list.create_node(4);
    /*list.create_node(2);
    list.create_node(3);
    list.create_node(5);
    list.create_node(8);
    
    list.print_list();
    list.push_node(0);
    list.print_list();
    //list.insert_at_pos(7, 10);*/
    list.print_list();
    
    list.remove_by_index(1);
    list.print_list();
    std::cout << "end";

    return 0;
}

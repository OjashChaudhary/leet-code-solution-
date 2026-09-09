class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };
    
    Node* head;
    int size;
    
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        return current->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        
        if (index < 0) {
            index = 0;
        }
        
        Node* newNode = new Node(val);
        
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++) {
                prev = prev->next;
            }
            newNode->next = prev->next;
            prev->next = newNode;
        }
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        
        if (index == 0) {
            head = head->next;
        } else {
            Node* prev = head;
            for (int i = 0; i < index - 1; i++) {
                prev = prev->next;
            }
            prev->next = prev->next->next;
        }
        
        size--;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
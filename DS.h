#ifndef DS_H
#define DS_H


int main();

class Node {
private:
    static int getNextCount;
    friend int main(); 
    friend void freeList(Node* head);

protected:
    char data;
    Node* next;

public:
    Node(char c, Node* n = nullptr) : data(c), next(n) {}
    virtual ~Node() = default;

    char getChar() const { return data; }
    
    Node* getNext() {
        getNextCount++; 
        return next;
    }
};

class MutableNode : public Node {
public:
    MutableNode(char c, Node* n = nullptr) : Node(c, n) {}
    
    void setChar(char c) { data = c; }
    void setNext(Node* n) { next = n; }
};

struct Answer {
    Node* middle;
    Node* tail;
};

#endif // DS_H
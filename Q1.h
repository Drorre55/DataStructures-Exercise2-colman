#ifndef Q1_H
#define Q1_H

#include "DS.h"

Answer findMiddleAndTail(Node* head) {
    Answer ans = {head, head};

    Node* current = head;
    int counter = 1;
    int middleIdx = 1;
    while (current != nullptr) {
        ans.tail = current;
        counter++;

        if ((counter / 2) + 1 > middleIdx) {
            ans.middle = ans.middle->getNext();
            middleIdx++;
        }
        
        current = current->getNext();
    }

    return ans;
}

bool isWW(Node* head) {

    return false;
}

bool isPalindrome(MutableNode* head) {

    return false;
}

#endif // Q1_H
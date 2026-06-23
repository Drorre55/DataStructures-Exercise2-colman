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
    Answer middleAndTail = findMiddleAndTail(head);
    if (head == middleAndTail.tail) return false;

    Node* firstHalf = head;
    Node* secondHalf = middleAndTail.middle;

    while (secondHalf != nullptr) {
        if (firstHalf->getChar() != secondHalf->getChar()) return false;
        firstHalf = firstHalf->getNext();
        secondHalf = secondHalf->getNext();
    }

    return true;
}

bool isPalindrome(MutableNode* head) {
    if (head == nullptr) return false;

    int counter = 0;
    float asciiResult = 0.0;
    Answer middleAndTail = findMiddleAndTail(head);
    Node* current = head;

    while (current != middleAndTail.middle) {
        if (counter % 2 == 1) {
            asciiResult *= (float)current->getChar();
        }
        else {
            asciiResult += (float)current->getChar();
        }
        current = current->getNext();
        counter++;
    }
    while (current != nullptr) {
        if (counter % 2 == 1) {
            asciiResult -= (float)current->getChar();
        }
        else {
            asciiResult /= (float)current->getChar();
        }
        current = current->getNext();
        counter++;
    }
    return asciiResult == 0.0;
}

#endif // Q1_H
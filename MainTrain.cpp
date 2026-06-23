/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <string>
#include "DS.h"
#include "Q1.h"

// אתחול המשתנה הסטטי של המונה
int Node::getNextCount = 0;

// פונקציית עזר לשחרור זיכרון ללא השפעה על המונה של הסטודנט
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next; // גישה ישירה ל-pointer המקורי כי main הוא friend
        delete temp;
    }
}

int main() {
    // סך הכל 9 בדיקות * 11 נקודות = 99 נקודות שליליות אפשריות

    // ==========================================
    // חלק א': בדיקות עבור findMiddleAndTail
    // ==========================================
    
    // בדיקה 1: רשימה קצרה באורך 4
    {
        std::string s = "abcd";
        Node* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new Node(s[i], head);
        
        Node::getNextCount = 0;
        Answer ans = findMiddleAndTail(head);
        
        if (!ans.middle || ans.middle->getChar() != 'c' || !ans.tail || ans.tail->getChar() != 'd') {
            std::cout << "findMiddleAndTail failed basic structure check (-11)" << std::endl;
        } else if (Node::getNextCount > (int)s.length() * 3 + 1 ) {
            std::cout << "findMiddleAndTail exceeded allowed operations (-11)"<< std::endl;
        }
        freeList(head);
    }

    // בדיקה 2: רשימה באורך 6 מהדוגמה
    {
        std::string s = "abbabb";
        Node* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new Node(s[i], head);
        
        Node::getNextCount = 0;
        Answer ans = findMiddleAndTail(head);
        
        if (!ans.middle || ans.middle->getChar() != 'a' || !ans.tail || ans.tail->getChar() != 'b') {
            std::cout << "findMiddleAndTail failed on 'abbabb' (-11)" << std::endl;
        }
        freeList(head);
    }

    // בדיקה 3: מחרוזת ארוכה יותר לבדיקת גבולות ליניאריים
    {
        std::string s = "abbabbaabbabba";
        Node* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new Node(s[i], head);
        
        Node::getNextCount = 0;
        Answer ans = findMiddleAndTail(head);
        
        if (!ans.middle || !ans.tail || ans.tail->getChar() != 'a') {
            std::cout << "findMiddleAndTail failed on long list tail detection (-11)" << std::endl;
        }
        freeList(head);
    }

    // ==========================================
    // חלק ב': בדיקות עבור isWW
    // ==========================================
    
    // בדיקה 4: מחרוזת שהיא WW אמיתי
    {
        std::string s = "abbabbaabbabba"; 
        Node* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new Node(s[i], head);
        
        Node::getNextCount = 0;
        bool res = isWW(head);
        
        if (!res) {
            std::cout << "isWW failed to detect a valid WW string (-11)" << std::endl;
        } else if (Node::getNextCount > (int)s.length() * 4 + 1) {
            std::cout << "isWW exceeded efficiency limit / counted nodes (-11)" << std::endl;
        }
        freeList(head);
    }

    // בדיקה 5: מחרוזת שאינה WW (מתוך הדוגמאות המקוריות בשאלה)
    {
        std::string s = "ababaababbababaaaababb";
        Node* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new Node(s[i], head);
        
        Node::getNextCount = 0;
        bool res = isWW(head);
        
        if (res) {
            std::cout << "isWW incorrectly identified a false string as WW (-11)" << std::endl;
        }
        freeList(head);
    }

    // בדיקה 6: בדיקת קצה קצרה ל-WW
    {
        std::string s = "abab";
        Node* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new Node(s[i], head);
        
        bool res = isWW(head);
        if (!res) {
            std::cout << "isWW failed on short string 'abab' (-11)" << std::endl;
        }
        freeList(head);
    }

    // ==========================================
    // חלק ג': בדיקות עבור isPalindrome
    // ==========================================
    
    // בדיקה 7: פלינדרום זוגי תקין
    {
        std::string s = "abba";
        MutableNode* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new MutableNode(s[i], head);
        
        Node::getNextCount = 0;
        bool res = isPalindrome(head);
        
        if (!res) {
            std::cout << "isPalindrome failed on true palindrome 'abba' (-11)" << std::endl;
        } else if (Node::getNextCount > (int)s.length() * 4) {
            std::cout << "isPalindrome exceeded allowed operations limit (-11)" << std::endl;
        }
        freeList(head);
    }

    // בדיקה 8: מחרוזת שאינה פלינדרום
    {
        std::string s = "abbabb";
        MutableNode* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new MutableNode(s[i], head);
        
        bool res = isPalindrome(head);
        if (res) {
            std::cout << "isPalindrome incorrectly identified 'abbabb' as palindrome (-11)" << std::endl;
        }
        freeList(head);
    }

    // בדיקה 9: פלינדרום ארוך יותר ומורכב
    {
        std::string s = "abaccaba"; // פלינדרום באורך 8
        MutableNode* head = nullptr;
        for (int i = (int)s.length() - 1; i >= 0; --i) head = new MutableNode(s[i], head);
        
        bool res = isPalindrome(head);
        if (!res) {
            std::cout << "isPalindrome failed on long valid palindrome (-11)" << std::endl;
        }
        freeList(head);
    }

    std::cout << "done" << std::endl;
    return 0;
}
//
//  main.cpp
//  linkedlist
//
//  Created by Sara Lindström on 2017-02-24.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class List
{
public:
    List()
    {
        head =  NULL;
    }
    
    void printList()
    {
        Node* node = head;
        std::cout << "{";
        while (node)
        {
            std::cout << node->data;
            if (node -> next != NULL)
                std::cout <<", ";
            
            node = node -> next;
        }
        std::cout << "}";
        std::cout << std::endl;
    }
    
    void insertBeginning(Node* newNode)
    {
        newNode->next = head;
        head = newNode;
    }
    
    void insertAfter(Node *node, Node* newNode)
    {
        newNode->next = node->next;
        node->next = newNode;
    }
    
    void removeBeginning()
    {
        Node* nodeToRemove = head;
        head = head->next;
        delete nodeToRemove;
    }
    
    ~List()
    {
        Node* nodeToDelete = head;
        Node* nextNode = head;
        
        while (nodeToDelete != NULL)
        {
            nextNode = nodeToDelete->next;
            if (nodeToDelete)
            {
                delete nodeToDelete;
                nodeToDelete = nextNode;
            }
        }
    }
    
private:
    Node* head;
};

int main(int argc, const char * argv[]) {
    
    List list;
    
    Node* node1 = new Node;
    node1->data = 20;
    
    Node* node2 = new Node;
    node2->data = 405;
    
    Node* node3 = new Node;
    node3->data = 220;
    
    Node* node4 = new Node;
    node4->data = 675;
   
    list.insertBeginning(node1);
    list.insertBeginning(node2);
    list.printList();
    
    list.removeBeginning();
    list.printList();
    
    list.insertAfter(node1, node3);
    list.insertAfter(node1, node4);
    list.printList();
    
    return 0;
}

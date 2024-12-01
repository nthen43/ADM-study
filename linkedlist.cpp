#include <iostream>

using namespace std;

class Node {
  public:
    int value;
    Node* next = nullptr;

    Node(int value){
      this->value = value;
    }

    Node(){
      this->value = 0;
      this->next = nullptr;
    }

    bool empty(Node* head){
      if(head->next == nullptr){
        return true;
      }
      return false;
    }

    void traverse(Node* node){
      Node* current = node;

      while(current->next != nullptr){
        cout << current->value << endl;
        current = current->next;
      }

      cout << current->value << endl;
      cout << "this is the end of the linked list." << endl;
    }

    Node* searchForNode(Node* head, int target){
      Node* current = head->next;
      while(current->next != nullptr){
        if(current->value == target){
          return current;
        }
        current = current->next;
      }
      return nullptr; // if node is not found, return a nullptr.
    }

    Node* insertNodeAtStart(Node* head, int value){
      Node* newNode = new Node(value);
      newNode->next = head;
      head = newNode;
      return head;
    }

    void insertNodeAtEnd(Node* head, int value){
      Node* newNode = new Node(value);
      Node* current = head;
      while(current->next != nullptr){
        current = current->next;
      }

      current->next = newNode;
      newNode->next = nullptr;
    }

    void insertNodeAnywhere(Node* head, int value, int pos){
      
    }
};


int main(){
  Node head;

  Node node1(1);
  Node node2(2);
  Node node3(3);
  Node node4(4);

  head.next = &node1;
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = nullptr;

  head.traverse(head.next);
  cout << head.searchForNode(&head, 1)->value << endl; // print the value of the node we are searching for (in this case 1)

  cout<< endl;
  Node* newHead = head.insertNodeAtStart(&head, -1); // insert at the head, thus becoming the new head
  head.insertNodeAtEnd(&head, 5); // insert node 5
  head.traverse(newHead); // traverse through list printing everything to see if it worked.

  return 0;
}
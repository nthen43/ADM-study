#include <iostream>

using namespace std;

class Node {
  public:
    int value;
    Node* next;

    Node(int value){
      this->value = value;
      this->next = nullptr;
    }

    Node(){
      this->value = 0;
      this->next = nullptr;
    }
};

class LinkedList {
  private:
  Node* head;

  public:

  LinkedList(){
    this->head = nullptr;
  }

  ~LinkedList(){
    while(this->head!= nullptr) {
      Node* temp = this->head;
      this->head= this->head->next;
      delete temp;
    }
  }

  bool empty(){
    return this->head == nullptr;
  }

  void traverse(){
    if(empty()) {
      cout << "list is empty." << endl;
      return;
    }

    Node* current = this->head;

    while(current != nullptr){
      cout << current->value << " ";
      current = current->next;
    }

    cout << endl;
    cout << endl;
  }

  Node* searchForNode(int target){
    Node* current = this->head;
    while(current->next != nullptr){
      if(current->value == target){
        return current;
      }
      current = current->next;
    }
    return nullptr; // if node is not found, return a nullptr.
  }

  void insertNodeAtStart(int value){
    Node* newNode = new Node(value);
    newNode->next = this->head;
    this->head = newNode;
  }

  void insertNodeAtEnd(int value){
    Node* newNode = new Node(value);
    if(empty()){
      this->head = newNode;
      return;
    }

    Node* current = this->head;
    while(current->next != nullptr){
      current = current->next;
    }

    current->next = newNode;
  }

  void insertNodeAnywhere(int value, int pos){
    if(pos < 0){
      cout << "invalid position" <<  endl;
      return;
    }

    if(pos == 0){
      insertNodeAtStart(value);
      return;
    }

    Node* newNode = new Node(value);
    int counter = 0;
    Node* predecessor = this->head;
    while(counter < pos - 1 && predecessor != nullptr){ // traverse until the node before our position
      predecessor = predecessor->next;
      counter++;
    }

    if(predecessor == nullptr){
      cout << "invalid position" << endl;
      delete newNode;
      return;
    }

    newNode->next = predecessor->next; // new node will point to what our previous node USED to point to
    predecessor->next = newNode; // our predecessor will point to the new node we just made.
  }

  void deleteAtStart(){
    if(empty()){
      cout << "List is Empty." << endl;
      return;
    }

    Node* temp = this->head;
    this->head = this->head->next;
    delete temp;
  }

  void deleteAtEnd(){
    if(empty()){ // if this->head is nullptr, list does not exist
      cout << "List is Empty." << endl;
      return;
    }

    if(this->head->next == nullptr){ // if the next node is null, then this->head is the only node in list
      delete this->head;
      this->head = nullptr;
      return;
    }

    Node* secondLast = this->head;
    while(secondLast->next->next != nullptr){
      secondLast = secondLast->next; // traverse to end of list - 1
    }

    delete (secondLast->next);
    secondLast->next = nullptr;
  }

  void deleteAnywhere(int position){
    if(empty() || position < 0){
      cout << "list empty or position invalid" << endl;
      return;
    }

    if(position == 0) {
      deleteAtStart();
      return;
    }

    int counter = 0;
    Node* predecessor = this->head;
    
    while(counter < position - 1 && predecessor->next != nullptr){
      predecessor = predecessor->next;
      counter++;
    }

    if(predecessor->next == nullptr){
      cout << "invalid position" << endl;
      return;
    }

    Node* toDelete = predecessor->next; // node to be deleted is the one after our predecessor
    predecessor->next = predecessor->next->next; // move our pointer to the node after the one to be deleted
    delete toDelete;
  }
};

int main(){
  LinkedList myList;

  myList.insertNodeAtEnd(1);
  myList.insertNodeAtEnd(2);
  myList.insertNodeAtEnd(3);
  myList.insertNodeAtEnd(4);

  cout << "Initial List: " << endl;
  myList.traverse();

  cout << "Insert 0 at the start of LL" << endl;
  myList.insertNodeAtStart(0);
  myList.traverse();

  cout << "Inserting 34 in between 3 and 4 (position 4)" << endl;
  myList.insertNodeAnywhere(34, 4);
  myList.traverse();

  cout << "Deleting at Start (0)" << endl;
  myList.deleteAtStart();
  myList.traverse();

  cout << "Deleting at the End (4)" << endl;
  myList.deleteAtEnd();
  myList.traverse();

  cout << "Delete at position 1 (2)" << endl;
  myList.deleteAnywhere(1);
  myList.traverse(); 

  return 0;
}
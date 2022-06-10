#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
};

class LinkedList {
  private:
    Node* head;

  public:
    LinkedList();
    int listSize();

    void pushBack(int);
    void pushAtGivenPos(int, int);
    void remove(Node*);
    void removeElements(int);
    void removeAtGivenPos(int);
    void findElement(int);
    void displayListForward();
    void displayListBackward();

};

LinkedList::LinkedList() : head(NULL) {}

void LinkedList::pushBack(int val) {
  Node* newNode = new Node();
  newNode->data = val;
  if (head == NULL) {
    head = newNode;
  } else {
    Node* oldNode = head;
    while (oldNode->next != NULL) {
      oldNode = oldNode->next;
    }
    oldNode->next = newNode;
    newNode->prev = oldNode;
  }
}

void LinkedList::pushAtGivenPos(int val, int pos) {
  Node* newNode = new Node();
  newNode->data = val;
  Node* tempHead = head;
  if (pos < 1) {
    return;
  } else if (pos == 1) {
    // consider using just pushBack function instead
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  } else {
    for (int i = 1; i < pos; i++) {
      if (head == NULL) {
        pushBack(val);
        break;
      }
      if (tempHead != NULL) {
        tempHead = tempHead->next;
      } else {
        pushBack(val);
        // consider using return in case of seg fault
        // especially when there is situation of adding
        // val at not-existing position of the list
        break;
      }
    }

    if (tempHead != NULL) {
      newNode->next = tempHead->next;
      newNode->prev = tempHead;
      tempHead->next = newNode;
      if (newNode->next != NULL) {
        newNode->next->prev = newNode;
      }
    }
  }
}

void LinkedList::remove(Node* val) {
  if (head == NULL) {
    cout << "The list is empty.";
  }

  if (head->data == val->data) {
    head = val->next;
  }

  if (val->next != NULL) {
    val->next->prev = val->prev;
  }

  if (val->prev != NULL) {
    val->prev->next = val->next;
  }

  free(val);
}

void LinkedList::removeElements(int val) {
  Node* iter = head;
  unsigned int count = 0;
  if (head == NULL) {
    cout << "The list is empty.";
  } else {
    while (iter != NULL) {
      if (iter->data == val) {
        remove(iter);
        count++;
      } else {
        cout << "0" << '\n';
        break;
      }
      iter = iter->next;
    }
    cout << "Removed " << count << " elements" << '\n';
  }
}

void LinkedList::removeAtGivenPos(int pos) {
  Node* tempHead = head;

  if (pos < 1) {
    return;
  }

  for (int i = 1; i < pos; i++) {
    if (tempHead != NULL) {
      tempHead = tempHead->next;
    }
  }
  remove(tempHead);
}

void LinkedList::findElement(int val) {
  Node* iter = head;
  unsigned int pos = 1;
  if (head == NULL) {
    cout << "The list is empty.";
  } else {
    while (iter != NULL) {
      if (iter->data == val) {
        cout << "Found the element: " << val << " at " << pos << " positon." << '\n';
      }
      pos++;
      iter = iter->next;
    }
  }
}

void LinkedList::displayListForward() {
  Node* iter = head;
  if (head == NULL) {
    cout << "The list is empty.";
  } else {
    while (iter != NULL) {
      cout << iter->data << " ";
      iter = iter->next;
    }
    cout << '\n';
  }
}

void LinkedList::displayListBackward() {
  Node* iter = head;
  Node* last = NULL;

  if (head == NULL) {
    cout << "The list is empty.";
  }

  while (iter != NULL) {
    last = iter;
    iter = iter->next;
  }

  while (last != NULL) {
    cout << last->data << " ";
    last = last->prev;
  }

  cout << '\n';
}

int main() {
  LinkedList myList;
  myList.pushBack(1);
  myList.pushBack(2);
  myList.pushBack(2);
  myList.pushBack(2);
  myList.pushBack(2);
  myList.pushAtGivenPos(3, 5);
  myList.displayListForward();
  myList.displayListBackward();
  myList.findElement(2);
  myList.removeAtGivenPos(3);
  myList.displayListForward();
  myList.displayListBackward();
  myList.removeElements(2);
  myList.displayListForward();
  myList.displayListBackward();
}
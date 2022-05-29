#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

// Zadanie 3A
void reverse(string &inputString) {
    stack<int> myStack;

    for (auto var: inputString) {
        myStack.push(var);
    }

    for (int i = 0; i < inputString.length(); i++) {
        inputString[i] = myStack.top();
        myStack.pop();
    }
}

// Zadanie 3B
class Queue {
    // Queue attributes
    private:
        bool empty_;
        unsigned int startIndex_, endIndex_;
        struct queueNode {
            int element;
            queueNode *next;
        };
        queueNode *start_, *end_, *queueItem_;
    public:
        Queue();
        ~Queue();
        unsigned int size() { return endIndex_ - startIndex_; }
        void add(int);
        void removeFirst();
        void display();
        void removeAll();
};

Queue::Queue() : startIndex_(0), endIndex_(0), empty_(true) {}

Queue::~Queue() {
    if (!this->empty_) { // If there is only one element in queue
        delete this->start_;
    }
    while (size()) {
        this->queueItem_ = this->start_;
        this->start_ = this->start_->next;
        delete this->queueItem_;
        this->startIndex_++;
    }
}

void Queue::add(int val) {
    if (!this->empty_) {
        this->queueItem_ = new queueNode;
        this->queueItem_->element = val;
        this->end_->next = this->queueItem_;
        this->end_ = this->queueItem_;
    } else {
        this->end_ = new queueNode;
        this->end_->element = val;
        this->start_ = new queueNode;
        this->start_->next = this->end_;
        this->empty_ = false;
    }
    this->endIndex_++;
}

void Queue::removeFirst() {
    if (!size()) {
        std::cout << "Queue is empty - nothing to remove (removeFirst)" << '\n';
    }
    this->queueItem_ = this->start_;
    this->start_ = this->start_->next;
    delete this->queueItem_;
    this->startIndex_++;
}

void Queue::display() {
    if (!size()) {
      cout << "Queue is empty - nothing to display" << '\n';
      return;
    } 
    queueNode* startTemp = this->start_;
    queueNode* queueItemTemp;
    unsigned int index = this->startIndex_;
    while (this->endIndex_ - index) {
        queueItemTemp = startTemp;
        startTemp = startTemp->next;
        cout << startTemp->element << '\n';
        index++;
    }
}

void Queue::removeAll() {
    if (!size()) {
        cout << "Queue is empty - nothing to remove (removeAll)" << '\n';
    }
    unsigned int index = 0;
    while (this->endIndex_ - this->startIndex_) {
        this->queueItem_ = this->start_;
        this->start_ = this->start_->next;
        delete this->queueItem_;
        this->startIndex_++;
    }
    this->empty_ = true;
}

int main() {

    unsigned int task = 0;   // Select task
    unsigned int option = 0; // Select option from task 3B
    
    // Task 3A variables
    fstream inputFile;
    string output = "";
    string text = "";
    unsigned int textLength = 0;

    // Task 3B variables
    int queueElement = 0;
    Queue myQueue;

    cout << "Enter task number (1 - 3A, 2 - 3B)" << '\n';
    cin >> task;
    switch (task) {
        case 1: 
            inputFile.open("C:\\Users\\mvjkel1\\Desktop\\studia\\Mazur\\Mazur_lab\\znaki1.txt");
            if (inputFile.is_open()) {
                while (getline(inputFile, output)) {
                    text += output + '\n';
                }
            }
            textLength = text.length();
            inputFile.close();
            reverse(text);
            if (textLength != text.length()) 
                return -1;
            cout << text << '\n';
            break;
        case 2:
            cout << "Enter option number" << '\n';
            cout << "1 - Remove all elements from the queue." << '\n';
            cout << "2 - Add element to the queue." << '\n';
            cout << "3 - Remove first element from the queue." << '\n';
            cout << "4 - Display elements from the queue." << '\n';
            cout << "5 - Finish." << '\n';
            do {
                cin >> option;
                switch(option) {
                    case 1:
                        myQueue.removeAll();
                        cout << "Removed all items from the queue" << '\n';
                        break;
                    case 2:
                        cout << "Enter the value of an element you want to add." << '\n';
                        cin >> queueElement;
                        myQueue.add(queueElement);
                        cout << "Added queue element equal to: " << queueElement << '\n';
                        break;
                    case 3:
                        myQueue.removeFirst();
                        cout << "Removed first element from the queue" << '\n';
                        break;
                    case 4:
                        myQueue.display();
                        break;
                    case 5:
                        cout << "Finished..." << '\n';
                        break;
                    default:
                        break;
                }
            } while (option != 5);
        default:
            break;
    }
}
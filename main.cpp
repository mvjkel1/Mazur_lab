#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void reverse(string &inputString) {

    cout << inputString.length() << endl;
    stack<int> myStack;

    for (auto var: inputString) {
        myStack.push(var);
    }

    for (int i = 0; i < inputString.length(); i++) {
        inputString[i] = myStack.top();
        myStack.pop();
    }
}

int main() {
    fstream inputFile;
    string output = "";
    string text = "";
    unsigned int textLength = 0;
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
}
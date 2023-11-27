//
// Created by gribk on 27.11.2023.
//

#include <algorithm>
#include "Practice7.h"

void Practice7::start() {
    int enter;
    string text;
    Practice7 object(0L);

    cout << "Enter line or \"file\" to import from file: ";
    cin >> text;
    if (text == "file") {
        fstream fstream1;
        fstream1.open("enter.txt");
        fstream1 >> text;
        fstream1.close();
    }

    cout << object.bruteForceMethod(text) << endl;
    cout << object.counter << endl;
}

unsigned int Practice7::bruteForceMethod(const string& text) {
    if (check(text)) return text.length();
    string str;
    cout << counter << endl;
//    cout << text << endl;
    unsigned int maxLen = 0;
    for (int i = 0; i < text.length(); i++) {
        str = text;
        str.erase(i, 1);
        maxLen = max(maxLen, bruteForceMethod(str));
    }
    return maxLen;
}

bool Practice7::check(const string &text) {
//    if (text.length() == 1) return true;
    for (int i = 0; i < text.length() / 2; i++) {
        counter++;
        if (text[i] != text[text.length() - 1 - i])
            return false;
    }
    return true;
}

Practice7::Practice7(unsigned long long int counter) : counter(counter) {}

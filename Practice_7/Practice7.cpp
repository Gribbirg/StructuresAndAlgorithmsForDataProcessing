//
// Created by gribk on 27.11.2023.
//

#include <algorithm>
#include "Practice7.h"

void Practice7::start() {
    int enter;
    string text;

    cout << "Enter line or \"file\" to import from file: ";
    cin >> text;
    if (text == "file") {
        fstream fstream1;
        fstream1.open("enter.txt");
        fstream1 >> text;
    }

    cout << bruteForceMethod(text);
}

unsigned int Practice7::bruteForceMethod(const string& text) {
    if (check(text)) return text.length();
    string str;
    unsigned int ans[text.length()];
    for (int i = 0; i < text.length(); i++) {
        str = text;
        str.erase(i, 1);
        ans[i] = bruteForceMethod(str);
    }
    return *max_element(ans, ans + text.length());
}

bool Practice7::check(const string &text) {
    if (text.length() == 1) return true;
    for (int i = 0; i < text.length() / 2; i++) {
        if (text[i] != text[text.length() - 1 - i])
            return false;
    }
    return true;
}

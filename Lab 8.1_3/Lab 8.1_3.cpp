#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція підрахунку (згідно з варіантом 7)
int Count(char* s) {
    if (!s) return 0;
    int k = 0;
    char* t = s;
    while (t = strstr(t, "while")) {
        k++;
        t += 5; // довжина "while"
    }
    return k;
}

// Функція заміни (згідно з варіантом 7: "while" -> "***")
char* Change(char* s) {
    if (!s) return nullptr;
    // Виділяємо пам'ять з запасом (на випадок, якщо зірочок більше, ніж літер)
    char* t = new char[strlen(s) * 2 + 1];
    char* p;
    int pos1 = 0;
    *t = 0;

    while (p = strstr(s + pos1, "while")) {
        int pos2 = p - s;
        strncat(t, s + pos1, pos2 - pos1);
        strcat(t, "***");
        pos1 = pos2 + 5;
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "Groups of 'while': " << Count(str) << endl;
    char* res = Change(str);
    cout << "Modified: " << str << endl;
    delete[] res;
    return 0;
}
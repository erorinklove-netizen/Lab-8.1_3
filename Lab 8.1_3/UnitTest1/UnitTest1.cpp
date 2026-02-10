#include "pch.h" // pch.h ЗАВЖДИ має бути першим
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Реалізація функцій безпосередньо в тесті, щоб уникнути помилок лінкування
int CountChar(char* s) {
    if (!s) return 0;
    int k = 0;
    char* t = s;
    while (t = strstr(t, "while")) {
        k++;
        t += 5;
    }
    return k;
}

char* ChangeChar(char* s) {
    if (!s) return nullptr;
    char* tmp = new char[strlen(s) * 2 + 1];
    char* p;
    int pos1 = 0;
    tmp[0] = '\0';
    while (p = strstr(s + pos1, "while")) {
        int pos2 = (int)(p - s); // явне приведення для усунення C4244
        strncat(tmp, s + pos1, pos2 - pos1);
        strcat(tmp, "***");
        pos1 = pos2 + 5;
    }
    strcat(tmp, s + pos1);
    strcpy(s, tmp);
    return tmp;
}

namespace UnitTestChar {
    TEST_CLASS(CharStyleTests) {
public:
    TEST_METHOD(TestCount) {
        char s[] = "abc while while";
        Assert::AreEqual(2, CountChar(s));
    }
    TEST_METHOD(TestChange) {
        char s[100] = "abc while";
        char* res = ChangeChar(s);
        Assert::AreEqual("abc ***", s);
        delete[] res;
    }
    };
}
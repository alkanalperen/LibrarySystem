//
// Created by Alperen Alkan on 5.12.2020.
//
#include <iostream>
#include "Book.h"
using namespace std;
#ifndef CSHW3B_STUDENT_H
#define CSHW3B_STUDENT_H


class Student {
public:
    Student();
    Student(int id, string name);
    int getId();
    string getName();
    void setId(int id);
    void setName(string s);
    void checkBook(Book b);
    void returnBook(Book &b);
    bool isNoCheckedBook();
    void showStu();
    void returnAllBook();
    int getTheInd(Book &b);
    int getIDBook(int ind);
    int getLengthB();
private:
    struct BookNode{
        Book item;
        BookNode *next;
    };
    BookNode *head;
    int id;
    string name;
    int bSize;
};


#endif //CSHW3B_STUDENT_H

//
// Created by Alperen Alkan on 5.12.2020.
//
#include <iostream>
using namespace std;
#ifndef CSHW3B_BOOK_H
#define CSHW3B_BOOK_H


class Book {
public:
    Book();
    ~Book();
    Book(int id, string name, int year);
    Book ( const Book &b);
    int getId();
    string getTitle();
    int getYear();
    void setId(int id);
    void setTitle(string s);
    void setYear(int year);
    bool isCheckedOut();
    void checkedBook();
    void returnBook();
    void setOwnerOfBook(string name);
    string getTheOwner();
    void showBook();
    int getTheOwnerId();
    void setTheOwnerId(int id);
    bool returnedAtleast1();
    bool checkedOut;

private:
    int id;
    string title;
    int year;
    string ownerOfBook;
    int ownerId;
    bool isReturned;
};


#endif //CSHW3B_BOOK_H

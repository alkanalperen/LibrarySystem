//
// Created by Alperen Alkan on 5.12.2020.
//
#include <iostream>
#include "Book.h"
#include "Student.h"
using namespace std;
#ifndef CSHW3B_LIBRARYSYSTEM_H
#define CSHW3B_LIBRARYSYSTEM_H

class LibrarySystem {
public:
    LibrarySystem();
    ~LibrarySystem();
    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);
    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);
    void showAllBooks() const;
    void showAllStudent() const;
    void showBook(const int bookId) const;
    void showStudent(const int studentId) const;
    bool isBookExist(const int bookId,int& ind);
    bool isStudentExist(const int bookId,int& ind);
    int getBookNu()const;
    int getStuNu()const;
    bool isNoBook()const;
    bool isNoStu()const;
    void removeB();
    void removeS();

private:
    struct StudentNode{
        Student item;
        StudentNode *next;
    };
    StudentNode *headS;
    StudentNode *findStuFromNu(int stuNu) const;
    int sizeS;
    struct BookNode{
        Book item;
        BookNode *next;
    };
    BookNode *headB;
    BookNode *findBookFromNu(int bookNu) const;
    int sizeB;
};

#endif //CSHW3B_LIBRARYSYSTEM_H

//
// Created by Alperen Alkan on 5.12.2020.
//

#include "Book.h"
Book::Book() {
    id = 0;
    title = "";
    year = 2000;
    checkedOut = false;
    ownerOfBook = "";
    isReturned = false;
}
Book::Book(int id, string name, int year) {
    setId(id);
    setTitle(name);
    setYear(year);
    checkedOut = false;
    ownerOfBook = "";
    isReturned = false;
}
Book::~Book() {
}
Book::Book(const Book &b) {
    id = b.id;
    title = b.title;
    year = b.year;
    checkedOut = b.checkedOut;
    ownerOfBook = b.ownerOfBook;
    ownerId = b.ownerId;
}
int Book::getId() {
    return id;
}
string Book::getTitle() {
    return title;
}
int Book::getYear() {
    return year;
}
void Book::setId(int id) {
    this->id = id;
}
void Book::setTitle(string s) {
    this->title = s;
}
void Book::setYear(int year) {
    this->year = year;
}
bool Book::isCheckedOut() {
    return checkedOut;
}
void Book::checkedBook() {
    checkedOut=true;
}
void Book::returnBook() {
    checkedOut = false;
    isReturned = true;
    cout << "Book " << id << "returned" <<endl;
}
void Book::setOwnerOfBook(string name) {
    ownerOfBook = name;
}
string Book::getTheOwner() {
    return ownerOfBook;
}
void Book::showBook() {
    cout << id << "  " << title << "  "<< year <<endl;
}
int Book::getTheOwnerId() {
    return ownerId;
}
void Book::setTheOwnerId( int id) {
    ownerId = id;
}
bool Book::returnedAtleast1() {
    return isReturned;
}


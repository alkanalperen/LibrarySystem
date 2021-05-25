//
// Created by Alperen Alkan on 5.12.2020.
//

#include "Student.h"
Student::Student() {
    id = 0;
    name = "";
    bSize = 0;
    head=NULL;
}
Student::Student(int id, string name) {
    this->id = id;
    this->name = name;
    bSize = 0;
    head=NULL;
}
void Student::setId(int id) {
    this->id = id;
}
int Student::getId() {
    return id;
}
string Student::getName() {
    return name;
}
void Student::setName(string s) {
    this->name = s;
}
bool Student::isNoCheckedBook() {
    return bSize == 0;
}
void Student::checkBook(Book b) {
    if(isNoCheckedBook()){
        head = new BookNode();
        head->item = b;
        bSize++;
    }else{
        BookNode *cur = head;
        for (int i = 1; i < bSize; i++) {
            cur = cur->next;
        }
        cur->next= new BookNode();
        cur->next->item = b;
        bSize++;
    }
}
void Student::returnBook(Book &b) {
    int indOfBook = getTheInd(b);
    BookNode *prev;
    BookNode *cur;
    for (prev = NULL, cur = head; (cur != NULL);
         prev = cur, cur = cur->next) {
        if (cur->item.getId() == b.getId() && indOfBook ==1 ) {
            head = head->next;
        } else if (cur->item.getId() == b.getId()) {
            prev->next = cur->next;
        }
    }
    bSize--;
    b.returnBook();

}

void Student::showStu() {
    cout << "Student id: " << id << " student name: "<< name <<endl;
    cout << "Student"<< id << "has checked out the following books" <<endl;
    if(isNoCheckedBook())
        cout << "Student " <<id  << " has no books";
    else {
        BookNode *cur = head;
        cout << "Book id    Book name     Year" <<endl;
        for (int i = 1; i < bSize+1; i++) {
            if( cur->item.checkedOut)
             cur->item.showBook();
            cur = cur->next;
        }
    }
}
void Student::returnAllBook() {
    BookNode *cur = head;
    int n = bSize;
    for (int i = 1; i < n+1; i++) {
        this->returnBook(cur->item);
        cur = cur->next;
    }
}
int Student::getTheInd(Book &b) {
    int ind = 1;
    BookNode *cur;
    for (cur = head; (cur != NULL);
    cur = cur->next) {
        if(b.getId() == cur->item.getId())
            return ind;
        ind++;
    }
}
int Student::getIDBook(int ind) {
    BookNode *cur = head;
    int n = bSize;
    for (int i = 1; i < n+1; i++) {
        if(i == ind)
            return cur->item.getId();
        cur = cur->next;
    }

}
int Student::getLengthB() {
    return bSize;
}
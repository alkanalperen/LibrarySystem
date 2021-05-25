//
// Created by Alperen Alkan on 5.12.2020.
//

#include "LibrarySystem.h"
#include <iomanip>
LibrarySystem::LibrarySystem() {
    headB=NULL;
    headS=NULL;
    sizeB=0;
    sizeS=0;
}
LibrarySystem::~LibrarySystem() {
    //if(!isNoStu())
    // removeS(1);
  //if(!isNoBook())
     //   removeB(1);
}

int LibrarySystem::getBookNu()const {
    return sizeB;
}
int LibrarySystem::getStuNu()const {
    return sizeS;
}
bool LibrarySystem::isBookExist(const int bookId, int &ind) {
    if(sizeB==0)
        return false;
    else {
        BookNode *cur = headB;
        for (int i = 0; i < getBookNu(); i++) {
            if (bookId == cur->item.getId()) {
                return true;
            }
            ind++;
            cur = cur->next;
        }
    }
    return false;
}
void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear) {
    int ind = 0;
    //create book
    Book b = Book(bookId,bookName,bookYear);
    if(isBookExist(b.getId(), ind) && !findBookFromNu(bookId)->item.checkedOut)
        cout << "Book " << bookId << " already exist" <<endl;
    else if(isNoBook()){
        headB = new BookNode();
        headB->item=b;
        sizeB++;
        cout << "Book "<< bookId <<" has been added"<<endl;
    }else{
        BookNode *cur = headB;
        for (int i = 1; i < sizeB; i++) {
            cur = cur->next;
        }
        cur->next= new BookNode();
        cur->next->item=b;
        sizeB++;
        cout << "Book "<< bookId <<" has been added"<<endl;
    }
}
void LibrarySystem::deleteBook(const int bookId) {
    int indOfBook = 1;
    if(!isBookExist(bookId,indOfBook))
        cout << "Book "<< bookId <<" does not exist" << endl;
    else{
        if(findBookFromNu(bookId)->item.checkedOut){
            findStuFromNu(findBookFromNu(bookId)->item.getTheOwnerId())->item.returnBook(findBookFromNu(bookId)->item);
        }
        BookNode *prev;
        BookNode *cur;
            for (prev = NULL, cur = headB; (cur != NULL);
                 prev = cur, cur = cur->next) {
                if (cur->item.getId() == bookId && indOfBook == 1) {
                    headB = headB->next;
                } else if (cur->item.getId() == bookId) {
                    prev->next = cur->next;
                }
            }
            sizeB--;
            cout << "Book " << bookId << " has been deleted" << endl;
    }
}
void LibrarySystem::showAllBooks() const {
    if(isNoBook()){
        cout << "There is no book"<<endl;
    }
    else {
        BookNode *cur = headB;
        cout << endl;
        cout << setw(7)<<"Book id "<< setw(19) <<"  Book name"<< setw(15) << "   Year " << setw(15) <<  "Status" << endl;
        for (int i = 1; i < sizeB+1; i++) {
            cout << left;
            cout <<setw(10)<< cur->item.getId()  << setw(20) << cur->item.getTitle() <<setw(10) << cur->item.getYear();

            if( (cur->item).isCheckedOut()  ){
                cout << "Checked out by student " << cur->item.getTheOwnerId() << endl;
            }
            else
                cout <<  "Not checked out "<<endl;
            cur = cur->next;
        }
    }
}


bool LibrarySystem::isNoBook() const{
    return sizeB == 0;
}
bool LibrarySystem::isStudentExist(const int stuID, int &ind) {
    if(sizeS==0)
        return false;
    else {
        StudentNode *cur = headS;
        for (int i = 0; i < getStuNu(); i++) {
            if (stuID == cur->item.getId()) {
                return true;
            }
            ind++;
            cur = cur->next;
        }
    }
    return false;
}
void LibrarySystem::addStudent(const int studentId, const string studentName) {
    int ind = 0;
    //create book
    Student b = Student (studentId,studentName);
    if(isStudentExist(b.getId(), ind))
        cout << "Student " << studentId << " already exist" <<endl;
    else if(isNoStu()){
        headS = new StudentNode();
        headS->item=b;
        sizeS++;
        cout << "Student " << studentId << " has been added" <<endl;
    }else{
        StudentNode *cur = headS;
        for (int i = 1; i < sizeS; i++) {
            cur = cur->next;
        }
        cur->next= new StudentNode();
        cur->next->item=b;
        sizeS++;
        cout << "Student " << studentId << " has been added" <<endl;
    }
}
void LibrarySystem::deleteStudent(const int studentId) {
    int indOfStu = 1;
    if(!isStudentExist(studentId,indOfStu))
        cout << "Student " << studentId <<  " does not exist" <<endl;
    else{
        int ind = 1;
        for(int i = 1; i <findStuFromNu(studentId)->item.getLengthB()+1;i++) {
            findBookFromNu(findStuFromNu(studentId)->item.getIDBook(i))->item.returnBook();
        }

        StudentNode *prev;
        StudentNode *cur;
        cout << "Student " << studentId << " has been deleted" <<endl;
        for(prev = NULL, cur= headS; (cur != NULL);
            prev = cur, cur = cur->next){
            if( cur->item.getId() == studentId && indOfStu == 1  ) {
                headS = headS->next;
            }
            else if ( cur->item.getId() == studentId ) {
                prev->next = cur->next;
            }
        }
        sizeS--;
    }
}
bool LibrarySystem::isNoStu() const {
    return sizeS == 0;
}
void LibrarySystem::showAllStudent() const {
    if(isNoStu()){
        cout << "There is no stu"<<endl;
    }
    else {
        StudentNode *cur = headS;
        for (int i = 1; i < sizeS+1; i++) {
            cout << cur->item.getId()  << cur->item.getName()<<endl;
            cur = cur->next;
        }
    }
}
void LibrarySystem::checkoutBook(const int bookId, const int studentId) {
    int indOfStu = 1;
    int indOfBook = 1;
bool isStuExist = isStudentExist(studentId,indOfStu);
bool isBExist = isBookExist(bookId,indOfBook);
if(isBExist ) {
    if (isStuExist){
        BookNode *cur = headB;
        for (int i = 1; i < sizeB+1; i++) {
            if(i == indOfBook) {
                if(cur->item.isCheckedOut()) {
                    cout << "Book "<< bookId << "has been already checked out by another student" << endl;
                    break;
                }
                cur->item.setOwnerOfBook(findStuFromNu(studentId)->item.getName());
                cur->item.setTheOwnerId(studentId);
                cur->item.checkedBook();
                cout <<"Book " << bookId << "has been checked out by student "<< studentId << endl;
                findStuFromNu(studentId)->item.checkBook(findBookFromNu(bookId)->item);
            }
            cur = cur->next;
        }
    }
    else
        cout << "Student " << studentId <<" does  not exist for checkout" << endl;
}
else
    cout << "Book " << bookId <<" does  not exist for checkout" << endl;


}
void LibrarySystem::returnBook(const int bookId) {
    int indOfBook = 1;
    bool isBExist = isBookExist(bookId,indOfBook);
    if(!isBExist)
        cout<< "Book is not exist"<<endl;
    else{
        BookNode *cur = headB;
        for (int i = 1; i < sizeB+1; i++) {
            if(i == indOfBook) {
                if(!cur->item.isCheckedOut()) {
                    cout << "book is not checked out"<<endl;
                }
                else{
                    findStuFromNu(findBookFromNu(bookId)->item.getTheOwnerId())->item.returnBook(findBookFromNu(bookId)->item);
                }
            }
            cur = cur->next;
        }

    }
}
LibrarySystem::StudentNode *LibrarySystem::findStuFromNu(const int studId)const{
    StudentNode *cur = headS;
    for(int skip = 1; skip < getStuNu()+1; skip++){
        if(cur->item.getId() == studId) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
LibrarySystem::BookNode *LibrarySystem::findBookFromNu(const int bookId) const{
    BookNode *cur = headB;
    for(int skip = 1; skip < getBookNu()+1; skip++){
        if(cur->item.getId() == bookId) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}


void LibrarySystem::showBook(const int bookId) const {
    BookNode *b = findBookFromNu(bookId);
    cout << b->item.getId() << b->item.getTitle()<< b->item.getYear();
    if(b->item.isCheckedOut())
        cout<< "checked out by the student" << b->item.getTheOwner() <<endl;
    else
        cout << "Not checked out"<<endl;
}
void LibrarySystem::showStudent(const int studentId) const {
    StudentNode *s = findStuFromNu(studentId);
    if(s!= NULL)
        s->item.showStu();
    else
        cout << "Student " << studentId <<" does not exist" <<endl;
}
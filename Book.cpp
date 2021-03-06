#include <iostream>
#include "Book.h"

using namespace std;
//konstruktor bezparametrowy
Book::Book() {
	this->author = "";
	this->title = "";
}
//konstruktor l-referencja
Book::Book(const string& author, const string& title) 
{
	this->author = author;
	this->title = title;
}
//konstruktor r-referencja
Book::Book(string&& author, string&& title){
	this->author = move(author);
	this->title = move(title);
}
//getery
string Book::GetAuthor(){
	return author;
}
string Book::GetTitle(){
	return title;
}
//setery ze stałymi l-referencjami
void Book::setAuthor(const string& author){
	this->author = author;
}
void Book::setTitle(const string& title){
	this->title = title;
}
//setery z r-referencjami 
void Book::setAuthor(string&& author) {
	this->author = move(author);
}
void Book::setTitle(string&& title){
	this->title = move(title);
}
// konstruktor kopiujący
Book::Book(const Book& other)
	:title(other.title), author(other.author){
}
//konstruktor przenoszący
Book::Book(Book&& other){
	title = move(other.title);
	author = move(other.author);
}
//operator przypisania kopiujący
Book& Book::operator=(const Book& right){
	title = right.title;
	author = right.author;
	return *this;
}
// operator przypisania przenoszący
Book& Book::operator=(Book&& right){
	std::swap(title, right.title);
	std::swap(author, right.author);
	return *this;
}
//destruktor
Book::~Book() {

}
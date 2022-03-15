#pragma once
#include<iostream>
#include <string>

using namespace std;

class Book {
	string author, title;
public:
	Book(); //konsturktor bezparametrowy
	Book(const string& author, const string& title); //sta³e l-referencje
	Book(string&& author, string&& title); // r--referencja

	//getery 
	string GetAuthor();
	string GetTitle();
	
	//setery ze sta³ymi l-referencjami
	void setAuthor(const string& author); 
	void setTitle(const string& title);
	//setery r-referencje
	void setAuthor(string&& author);
	void setTitle(string&& title);

	Book(const Book& other); // konstruktor kopiuj¹cy 
	Book(Book&& other); //konstruktor przenosz¹cy
	Book& operator=(const Book& right); // operator przypisania kopiuj¹cy 
	Book& operator=(Book&& right); //operator przypisania przenosz¹cy 
	~Book();
};
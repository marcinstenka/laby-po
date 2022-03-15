#pragma once
#include<iostream>
#include <string>

using namespace std;

class Book {
	string author, title;
public:
	Book(); //konsturktor bezparametrowy
	Book(const string& author, const string& title); //sta�e l-referencje
	Book(string&& author, string&& title); // r--referencja

	//getery 
	string GetAuthor();
	string GetTitle();
	
	//setery ze sta�ymi l-referencjami
	void setAuthor(const string& author); 
	void setTitle(const string& title);
	//setery r-referencje
	void setAuthor(string&& author);
	void setTitle(string&& title);

	Book(const Book& other); // konstruktor kopiuj�cy 
	Book(Book&& other); //konstruktor przenosz�cy
	Book& operator=(const Book& right); // operator przypisania kopiuj�cy 
	Book& operator=(Book&& right); //operator przypisania przenosz�cy 
	~Book();
};
#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include "Book.h"

class Library {
	Book* arr;
	size_t booksQuantity;
public:
	Library(); //konstruktor bezparametrowy
	Library(size_t booksQuantity); // konstruktor z ilo�ci� ksi��ek
	Library(initializer_list<Book> list); //konstruktor z list� ksi��ek
	Library(const Library& original); //konstruktor kopiuj�cy
	Library(Library&& original); //konstruktor przenosz�cy
	Library& operator=(const Library& right);
	Library& operator=(Library&& right);
	Book& operator[](size_t index);
	const Book& operator[](size_t index) const;
	size_t GetSize() const;
	~Library();
};
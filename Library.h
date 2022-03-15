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
	Library(size_t booksQuantity); // konstruktor z iloœci¹ ksi¹¿ek
	Library(initializer_list<Book> list); //konstruktor z list¹ ksi¹¿ek
	Library(const Library& original); //konstruktor kopiuj¹cy
	Library(Library&& original); //konstruktor przenosz¹cy
	Library& operator=(const Library& right);
	Library& operator=(Library&& right);
	Book& operator[](size_t index);
	const Book& operator[](size_t index) const;
	size_t GetSize() const;
	~Library();
};
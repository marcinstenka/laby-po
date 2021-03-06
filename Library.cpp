#include "Library.h"

//konstruktor bezparametrowy
Library::Library()
{
	arr = nullptr;
	booksQuantity = 0;
}

Library::Library(size_t booksQuantity)
	: booksQuantity{ booksQuantity }, arr{ new Book[booksQuantity] }{
}

//konstruktor z listą inicjalizacyjną
Library::Library(initializer_list<Book> list)
	: booksQuantity{ list.size() }, arr{ new Book[list.size()] }{
	size_t i = 0;
	for (Book v : list)
	{
		arr[i] = v;
		i++;
	}
}
//konstruktor kopiujący
Library::Library(const Library& original) 
	:booksQuantity{ original.booksQuantity }, arr{ new Book[original.booksQuantity] }{
	for (size_t i = 0; i < booksQuantity; i++){
		arr[i] = original.arr[i];
	}
}
//konstruktor przenoszący
Library::Library(Library&& original){
	booksQuantity = original.booksQuantity;
	arr = original.arr;

	//usuwanie
	original.booksQuantity = 0;
	original.arr = nullptr;
}
//operator przypisania kopiujący
Library& Library::operator=(const Library& right){
	Library tmp = right;
	swap(arr, tmp.arr);
	swap(booksQuantity, tmp.booksQuantity);
	return *this;
}
//operator przypisania przenoszący 
Library& Library::operator=(Library&& right){
	swap(booksQuantity, right.booksQuantity);
	swap(arr, right.arr);
	return *this;
}
// operator []
Book& Library::operator[](size_t index){
	return arr[index];
}
// operator [] werjsa stała
const Book& Library::operator[](size_t index) const{
	return arr[index];
}

size_t Library::GetSize() const{
	return booksQuantity;
}
// destrukltor 
Library::~Library(){
	if (arr != nullptr){
		delete[] arr;
	}
}
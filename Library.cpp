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

//konstruktor z list� inicjalizacyjn�
Library::Library(initializer_list<Book> list)
	: booksQuantity{ list.size() }, arr{ new Book[list.size()] }{
	size_t i = 0;
	for (Book v : list)
	{
		arr[i] = v;
		i++;
	}
}
//konstruktor kopiuj�cy
Library::Library(const Library& original) 
	:booksQuantity{ original.booksQuantity }, arr{ new Book[original.booksQuantity] }{
	for (size_t i = 0; i < booksQuantity; i++){
		arr[i] = original.arr[i];
	}
}
//konstruktor przenosz�cy
Library::Library(Library&& original){
	booksQuantity = original.booksQuantity;
	arr = original.arr;

	//usuwanie
	original.booksQuantity = 0;
	original.arr = nullptr;
}
//operator przypisania kopiuj�cy
Library& Library::operator=(const Library& right){
	Library tmp = right;
	swap(arr, tmp.arr);
	swap(booksQuantity, tmp.booksQuantity);
	return *this;
}
//operator przypisania przenosz�cy 
Library& Library::operator=(Library&& right){
	swap(booksQuantity, right.booksQuantity);
	swap(arr, right.arr);
	return *this;
}
// operator []
Book& Library::operator[](size_t index){
	return arr[index];
}
// operator [] werjsa sta�a
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
#include <iostream>
#include <string>
#include "Library.h"
#include "Book.h"

using namespace std;

// operator << dla klasy Book
std::ostream& operator<<(ostream& out, Book& book)
{
	out << "Book:(";
	out << book.GetAuthor();
	out << ", ";
	out << book.GetTitle();
	out << ")" <<endl;

	return out;
}

// operator << dla klasy Library
ostream& operator<<(ostream& out, Library& library){
	out << "Library:{" <<endl;
	for (size_t i = 0; i < library.GetSize(); i++){
		out << library[i];
	}
	out << "}" <<endl;
	return out;
}

int main() {
	string a = "Andrzej Sapowski", t = "The Witcher";
	Book e;
	cout << "e: " << e << endl;
	
	Book b1 = { a, t };
	cout << "b1: " << b1 << endl;
	
	Book b2 = { "John Flanagana","Ranger's Apprentice" };
	cout << "b2: " << b2 << endl;
	
	Book b3 = b1;
	cout << "b3: " << b3 << " b1: " << b1 << endl;
	
	e = move(b2);
	cout << "e: " << e << " b2:" << b2 << endl;
	
	e.setAuthor("J.R.R. Tolkien");
	cout << "e: " << e << endl;
	e.setTitle("The Lord of The Rings");
	cout << "e: " << e << endl;
	

	Library xx; // konstruktor bezparametrowy
	cout << "xx: " << xx << endl;
	
	Library l1 = { {"Andrzej Sapowski", "The Witcher"}, //konstruktor z list¹ ksi¹¿ek
	{"John Flanagana", "Ranger's Apprentice"},
	{"J.R.R. Tolkien", "The Lord of The Rings"} };
	cout << "l1: " << l1 << endl;
	
	Library l2(2); // konstruktor z ilosci¹ ksi¹¿ek
	cout << "l2: " << l2 << endl;
	l2[0] = { "C.S. Lewis", "The Chronicles of Narnia" };
	l2[1] = { "J.R.R. Tolkien", "The Hobbit" };
	cout << "l2: " << l2 << endl;
	
	xx = move(l2);
	cout << "xx: " << xx << " l2: " << l2 << endl;

	l1[0] = move(xx[1]);
	cout << "l1: " << l1 << " xx: " << xx << endl;

	return 0;
}
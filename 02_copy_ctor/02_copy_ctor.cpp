#include <iostream>
//#include "String.h"
#include "Book.h"
using namespace std;


void printBook(Book book) {
	cout << "\n========= Book ==========" << endl;
	cout << "\t Author :: " << book.getAuthor() << endl;
	cout << "\t Title  :: " << book.getTitle() << endl;
}
void printBooks(Book* books, const size_t& size) {
	for (size_t i = 0; i < size; i++)
	{
		printBook(books[i]);
	}
}
int main()
{
	//String str_1;
	//String str_2(20);
	//String str_3("Test");
	//cout << "Str 1 :: "; str_1.print(); cout << "\t size :: " << str_1.getSize() << endl;
	//cout << "Str 2 :: "; str_2.print(); cout << "\t size :: " << str_2.getSize() << endl;
	//cout << "Str 3 :: "; str_3.print(); cout << "\t size :: " << str_3.getSize() << endl;
	//String clone = str_3; // copy ctor
	//cout << "Str origin :: "; str_3.print(); cout << "\t size :: " << str_3.getSize() << endl;
	//cout << "Str clone  :: "; clone.print(); cout << "\t size :: " << clone.getSize() << endl;
	//str_3.input();
	//cout << "Str origin :: "; str_3.print(); cout << "\t size :: " << str_3.getSize() << endl;
	//cout << "Str clone  :: "; clone.print(); cout << "\t size :: " << clone.getSize() << endl;
	//clone = str_3;
	//cout << "Str origin :: "; str_3.print(); cout << "\t size :: " << str_3.getSize() << endl;
	//cout << "Str clone  :: "; clone.print(); cout << "\t size :: " << clone.getSize() << endl;
	//clone.input();
	//cout << "Edit clone : \n";
	//cout << "Str origin :: "; str_3.print(); cout << "\t size :: " << str_3.getSize() << endl;
	//cout << "Str clone  :: "; clone.print(); cout << "\t size :: " << clone.getSize() << endl;
	//String concat = clone.concat(str_3);
	//cout << "Result :: ";
	//concat.print();

	//String line("programming");
	//String line_2("language");
	//line.print(); cout << endl;
	//line_2.print(); cout << endl;

	//String res = line.slice(line_2);
	//cout << "Res :: "; res.print();
	//cout << endl;

	//String line_1(20);
	//line_1.input();
	//line_1.print(); cout << endl;
	//cout << "index 2 :: " << line_1.get(2) << endl;
	//line_1.set(2, 'A');
	//line_1.print(); cout << endl;
	//line_1.set(5, 'B');
	//line_1.print(); cout << endl;

	/*String line;
	line.copyStr("Hello");
	line.print(); cout << endl;*/

	String str("Hello");
	String str_2("World");
	String res = str.concat(str_2);
	res.print();

	/*Book book;
	book.print();
	Book book2("King", "It");
	book2.print();
	Book book3 = book2;
	cout << "Origin :: \n";
	book2.print();
	cout << "Clone :: \n";
	book3.print();
	book2.setAuthor("New Author");
	book2.setTitle("New Title");
	cout << "Test Book :: \t Author :: " << book2.getAuthor() << "\t Title :: " << book2.getTitle() << endl;

	cout << "\n\n========================================\n";
	printBook(book2);
	cout << "\n\n========================================\n";
	Book books[]{ book,book2,book3 };
	printBooks(books, sizeof(books) / sizeof(Book));*/
}



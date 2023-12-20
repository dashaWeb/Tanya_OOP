#pragma once
#include "String.h"
class Book
{

public:
	Book() 
	:Book("None author","None title")
	{}
	Book(const char* author, const char* title)
	{
		this->author.copyStr(author);
		this->title.copyStr(title);
	}
	Book(const char* author) :Book(author, "None") {}
	Book(const Book& other):Book(other.author.getLine(), other.title.getLine())
	{
		cout << "Copy ctor" << endl;
	}
	void setAuthor(const char* author);
	void setTitle(const char* title);
	const char* getAuthor() const;
	const char* getTitle() const;
	void print() const;
private:
	String author;
	String title;
	
};
inline void Book::setAuthor(const char* author)
{
	this->author.copyStr(author);
}

inline void Book::setTitle(const char* title)
{
	this->title.copyStr(title);
}

inline const char* Book::getAuthor() const
{
	return author.getLine();
}

inline const char* Book::getTitle() const
{
	return this->title.getLine();
}

inline void Book::print() const
{
	cout << "Author :: " << this->author.getLine() << endl;
	cout << "Title  :: " << this->title.getLine() << endl;
}

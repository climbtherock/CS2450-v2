// Library v0.8

#ifndef LIBRARY_H
#define LIBRARY_H


#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Date.h"
#include "Book.h"
#include "Patron.h"
#include "Boolinq.h"

typedef std::pair<Patron*, std::vector<Book*>> patronStatus;


class Library 
{
	private:
		const size_t MAX_ADULT_CHECKOUT = 5;			// Check these values
		const size_t MAX_CHILD_CHECKOUT = 2;			// Check these values
		const int TYPE_CHILD = 2;

		std::unordered_map<Patron*, std::vector<Book*>> patronBooks;
		std::vector<std::string> checkoutErrorList;
		std::vector<std::string> patronErrorList;
		std::vector<std::string> bookErrorList;
		std::vector<Patron*> patrons;
		std::vector<Book*> books;

		std::vector<std::string> Split( char*, char );
		static bool contains( std::string, std::string );

	public:
		Library();
		~Library();
		void setCurrentDate( std::string );
		void createBooks(std::istream&);
		void createPatrons(std::istream&);
		void restorePBStatus(std::istream&);
		void checkout( std::string, std::string );
		void checkin( std::string, std::string );
		void writeBooksToDB(std::ostream&);
		void writePatronsToDB(std::ostream&);
		void writePBStatusToDB(std::ostream&);
		std::string FindPatron( std::string, std::ostream& );
		std::string FindBook( std::string, std::ostream& );
		void ListBooksByPatron( std::string, std::ostream& );
		void ListOverdueBooks( std::ostream& );
		void ListCheckedOut( std::ostream& );
		bool errorsFound();
		void displayErrors( std::ostream& );
		void displayPatrons( std::ostream& );
		void displayBooks( std::ostream& );
};



#endif
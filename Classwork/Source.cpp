#include <iostream>
#include <windows.h>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <algorithm> // для sort()
#include <functional>

using namespace std;

	class Book {
	private:
		int numberBook; // номер книги
		int yearBook; // рік випуску
		string nameBook; // назва книги
		string author; // автор книги
		bool issuanceBook; // певернена книга - 1, видана книга - 0
	public:
		Book(int numberBook, int yearBook, string nameBook, string author, bool issuanceBook) {
			this->numberBook = numberBook;
			this->yearBook = yearBook;
			this->nameBook = nameBook;
			this->author = author;
			this->issuanceBook = issuanceBook;
		}
		int GetnumberBook() {
			return numberBook;
		}
		int GetyearBook() {
			return yearBook;
		}
		void SetYearBook(int yearBook) {
			this->yearBook = yearBook;
		}
		string GetnameBook() {
			return nameBook;
		}
		void SetNameBook(string nameBook) {
			this->nameBook = nameBook;
		}
		string Getauthor() {
			return author;
		}
		void SetAuthor(string author) {
			this->author = author;
		}
		bool GetissuanceBook() {
			return issuanceBook;
		}
		void SetissuanceBook(bool issuanceBook) {
			this->issuanceBook = issuanceBook;
		}

		bool operator < (const Book& book) const { // перегрузка оператора " < " для того, щоб можна було відсортувати по назві за алфавітом через функцію sort()
			return this->nameBook < book.nameBook;
		}

		void PrintBook() {
			cout << "Number book: " << numberBook << endl;
			cout << "Graduation year book: " << yearBook << endl;
			cout << "Name book: " << nameBook << endl;
			cout << "Author book: " << author << endl;
			if (issuanceBook == 1)
			{
				cout << "Book " << nameBook << " is return book." << endl;
			}
			else
			{
				cout << "Book " << nameBook << " is issuance book." << endl;
			}
		}
	};

int main() {
	deque<Book> library;
	int action = 1;
	while (action)
	{
		cout << "\n-------M E N U-------" << endl;
		cout << "1.Add book." << endl;
		cout << "2.Search book." << endl;
		cout << "3.Issuance book." << endl;
		cout << "4.Return book." << endl;
		cout << "5.Sort book by name." << endl;
		cout << "6.Delete book." << endl;
		cout << "7.Edit book." << endl;
		cout << "8.Show info all book." << endl;
		cout << "0.Exit." << endl;
		cout << "\nEnter item menu." << endl;
		cin >> action;
		switch (action)
		{
			case 1: {
				int numberBook;
				int yearBook;
				string nameBook;
				string author;
				bool issuanceBook;
				cout << "Enter number book: ";
				cin >> numberBook;
				cout << "Enter graduation year book: ";
				cin >> yearBook;
				cout << "Enter name book: ";
				cin.ignore();
				getline(cin, nameBook);
				cout << "Enter author book: ";
				getline(cin, author);
				cout << "Enter issuance or issuance book (return book = 1, issuance book = 0) : ";
				cin >> issuanceBook;
				Book book(numberBook, yearBook, nameBook, author, issuanceBook);
				library.push_back(book);
				break;
			}
			case 2: {
				int action2 = 1;
				while (action2)
				{
					cout << "1.Search by author book." << endl;
					cout << "2.Search by name book." << endl;
					cout << "0.Exit." << endl;
					cout << "\nEnter item menu." << endl;
					cin >> action2;
					switch (action2)
					{
						case 1: {
							string search_author;
							cout << "Enter author book: ";
							cin >> search_author;
							for (int i = 0; i < library.size(); i++)
							{
								if (library[i].Getauthor() == search_author)
								{
									library[i].PrintBook();
									break;
								}
								else if (i == library.size() - 1 && library[i].Getauthor() != search_author)
								{
									cout << "Not search!" << endl;
								}
							}
							cout << endl;
							break;
						}
						case 2: {
							string search_namebook;
							cout << "Enter name book: ";
							cin >> search_namebook;
							for (int i = 0; i < library.size(); i++)
							{
								if (library[i].GetnameBook() == search_namebook)
								{
									library[i].PrintBook();
									break;
								}
								else if (i == library.size() - 1 && library[i].GetnameBook() != search_namebook)
								{
									cout << "Not search!" << endl;
								}
							}
							cout << endl;
							break;
						}
						case 0: {
							break;
						}
					default:
						cout << "Not a valid menu item. Try again." << endl;
						break;
					}
				}
				break;
			}
			case 3: {
				int num_book;
				cout << "Select the number of the book you want to issue: ";
				cin >> num_book;
				for (int i = 0; i < library.size(); i++)
				{
					if (library[i].GetnumberBook() == num_book)
					{
						bool issue = library[i].GetissuanceBook();
						cout << "Write a note about the issuance of the book (enter \"0\"): ";
						cin >> issue;
						library[i].SetissuanceBook(issue); // присвоюємо значення 0 через сеттер, так як книга видана
					}
				}
				break;
			}
			case 4: {
				int num_book;
				cout << "Select the number of the book you want to return: ";
				cin >> num_book;
				for (int i = 0; i < library.size(); i++)
				{
					if (library[i].GetnumberBook() == num_book)
					{
						bool return_book = library[i].GetissuanceBook();
						cout << "Write a note about the issuance of the book (enter \"1\"): ";
						cin >> return_book;
						library[i].SetissuanceBook(return_book); // присвоюємо значення 1 через сеттер, так як книга повернена
					}
				}
				break;
			}
			case 5: {
				sort(library.begin(), library.end());  // сортування за назвою книги, так як пергрузка оператора > відбувалась саме по назві
				for (int i = 0; i < library.size(); i++)
				{
					library[i].PrintBook();
					cout << endl;
				}
				break;
			}
			case 6: {
				int num_book;
				cout << "Enter the number of the book you want to delete: ";
				cin >> num_book;
				//deque<Book>::iterator it = library.begin();
				auto it = library.begin(); // присвоюємо ітератору it початок діапазону контейнера library
				for (int i = 0; i < library.size(); i++)
				{
					if (library[i].GetnumberBook() == num_book)
					{
						advance(it, i); // ітератору it присвоюємо значення індекса i
						library.erase(it); // видаляємо елемент з відповідним індексом
					}
				}
				break;
			}
			case 7: {
				int num_book;
				cout << "Enter the number of the book you want to edit: ";
				cin >> num_book;
				int action7 = 1;
				while (action7)
				{
					cout << "1.Edit year book." << endl;
					cout << "2.Edit name book." << endl;
					cout << "3.Edit autor book." << endl;
					cout << "0.Exit." << endl;
					cout << "\nEnter item menu." << endl;
					cin >> action7;
					switch (action7)
					{
						case 1: {
							for (int i = 0; i < library.size(); i++)
							{
								if (library[i].GetnumberBook() == num_book)
								{
									cout<< "Year book: " << library[i].GetyearBook() << endl;
									int year_Book;
									cout << "Enter new year book: ";
									cin >> year_Book;
									library[i].SetYearBook(year_Book); // заміна року книги на новий через сеттер
									//cout << library[i].GetyearBook() << endl;
								}
							}
							break;
						}
						case 2: {
							for (int i = 0; i < library.size(); i++)
							{
								if (library[i].GetnumberBook() == num_book)
								{
									cout << "Name book: " << library[i].GetnameBook() << endl;
									string name_Book;
									cout << "Enter new name book: ";
									cin >> name_Book;
									library[i].SetNameBook(name_Book); // заміна назви книги на нову назву через сеттер
								}
							}
							break;
						}
						case 3: {
							for (int i = 0; i < library.size(); i++)
							{
								if (library[i].GetnumberBook() == num_book)
								{
									cout << "Autor book: " << library[i].Getauthor() << endl;
									string autor_Book;
									cout << "Enter new author book: ";
									cin >> autor_Book;
									library[i].SetAuthor(autor_Book); // заміна назви автора на нового автора через сеттер
								}
							}
							break;
						}
						case 0: {
							break;
						}
					default:
						cout << "Not a valid menu item. Try again." << endl;
						break;
					}
				}

				break;
			}
			case 8: {
				cout << "===Info all book===" << endl;
				for (int i = 0; i < library.size(); i++)
				{
					library[i].PrintBook();
					cout << endl;
				}
				break;
			}
			case 0: {
				break;
			}
			default:
				cout << "Not a valid menu item. Try again." << endl;
			break;
		}
	}
	return 0;
}
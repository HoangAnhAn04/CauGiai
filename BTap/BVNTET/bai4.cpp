#include <iostream>
#include <string>
using namespace std;
class Book {
public:
  string title;
  string author;
  int publishYear;

  void input() {
    cout << "Enter title: ";
    getline(cin >> ws, title);
    cout << "Enter author: ";
    getline(cin >> ws, author);
    cout << "Enter year of publication: ";
    cin >> publishYear;
  }
  
  void display() {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year of publication: " << publishYear << endl;
  }
};
                 
int main() {
  int n;
  cout << "Enter number of books: ";
  cin >> n;
  Book* books = new Book[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter details for book " << i + 1 << ":\n";
    books[i].input();
  }

  cout << "Books:\n";
  for (int i = 0; i < n; i++) {
    books[i].display();
  }

  cout << "Books published between 2000 and 2023:\n";
  for (int i = 0; i < n; i++) {
    if (books[i].publishYear >= 2000 && books[i].publishYear <= 2023) {
      books[i].display();
    }
  }

  delete[] books;
  return 0;
}
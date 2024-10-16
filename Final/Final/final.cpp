#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Book {
    char title[100];
    char author[100];
    char category[50];

    void display() {
        cout << "Book: " << title << " | Author: " << author << " | Category: " << category << endl;
    }
};

struct Journal {
    char title[100];
    int year;

    void display() {
        cout << "Journal: " << title << " | Year: " << year << endl;
    }
};

struct Newspaper {
    char title[100];
    int year;

    void display() {
        cout << "Newspaper: " << title << " | Year: " << year << endl;
    }
};

struct Library {
    Book* books;
    Journal* journals;
    Newspaper* newspapers;
    int bookCount, journalCount, newspaperCount;
    int bookCapacity, journalCapacity, newspaperCapacity;

    void initialize() {
        bookCapacity = journalCapacity = newspaperCapacity = 10;
        books = new Book[bookCapacity];
        journals = new Journal[journalCapacity];
        newspapers = new Newspaper[newspaperCapacity];
        bookCount = journalCount = newspaperCount = 0;
    }

    void addBook(const char* title, const char* author, const char* category) {
        if (bookCount < bookCapacity) {
            strcpy_s(books[bookCount].title, title);
            strcpy_s(books[bookCount].author, author);
            strcpy_s(books[bookCount].category, category);
            bookCount++;
        }
        else {
            cout << "No space for more books." << endl;
        }
    }

    void addJournal(const char* title, int year) {
        if (journalCount < journalCapacity) {
            strcpy_s(journals[journalCount].title, title);
            journals[journalCount].year = year;
            journalCount++;
        }
        else {
            cout << "No space for more journals." << endl;
        }
    }

    void addNewspaper(const char* title, int year) {
        if (newspaperCount < newspaperCapacity) {
            strcpy_s(newspapers[newspaperCount].title, title);
            newspapers[newspaperCount].year = year;
            newspaperCount++;
        }
        else {
            cout << "No space for more newspapers." << endl;
        }
    }

    void displayAll() const {
        cout << "Books:" << endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }

        cout << "\nJournals:" << endl;
        for (int i = 0; i < journalCount; i++) {
            journals[i].display();
        }

        cout << "\nNewspapers:" << endl;
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
        }
    }

    void removeBook(const char* title) {
        for (int i = 0; i < bookCount; i++) {
            if (strcmp(books[i].title, title) == 0) {
                books[i] = books[bookCount - 1];
                bookCount--;
                cout << "Book removed: " << title << endl;
                return;
            }
        }
        cout << "Book not found: " << title << endl;
    }

    void removeJournal(const char* title) {
        for (int i = 0; i < journalCount; i++) {
            if (strcmp(journals[i].title, title) == 0) {
                journals[i] = journals[journalCount - 1];
                journalCount--;
                cout << "Journal removed: " << title << endl;
                return;
            }
        }
        cout << "Journal not found: " << title << endl;
    }

    void removeNewspapersByYear(int year) {
        int removedCount = 0;
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].year == year) {
                newspapers[i] = newspapers[newspaperCount - 1];
                newspaperCount--;
                removedCount++;
                i--;
            }
        }
        if (removedCount > 0) {
            cout << removedCount << " newspapers removed for year " << year << "." << endl;
        }
        else {
            cout << "No newspapers found for year " << year << "." << endl;
        }
    }

    void searchBook(const char* title, const char* author) const {
        for (int i = 0; i < bookCount; i++) {
            if (strcmp(books[i].title, title) == 0 && strcmp(books[i].author, author) == 0) {
                cout << "Book found: ";
                books[i].display();
                return;
            }
        }
        cout << "Book not found: " << title << " by " << author << endl;
    }

    void searchJournal(const char* title, int year) const {
        for (int i = 0; i < journalCount; i++) {
            if (strcmp(journals[i].title, title) == 0 && journals[i].year == year) {
                cout << "Journal found: ";
                journals[i].display();
                return;
            }
        }
        cout << "Journal not found: " << title << " from " << year << endl;
    }

    void selectBooksByAuthor(const char* author) const {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (strcmp(books[i].author, author) == 0) {
                books[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No books found for author: " << author << endl;
        }
    }

    void selectBooksByCategory(const char* category) const {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (strcmp(books[i].category, category) == 0) {
                books[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No books found for category: " << category << endl;
        }
    }

    void saveToFile(const char* filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
            return;
        }

        file << bookCount << endl;
        for (int i = 0; i < bookCount; i++) {
            file << books[i].title << " , " << books[i].author << " , " << books[i].category << endl;
        }

        file << journalCount << endl;
        for (int i = 0; i < journalCount; i++) {
            file << journals[i].title << " , " << journals[i].year << endl;
        }

        file << newspaperCount << endl;
        for (int i = 0; i < newspaperCount; i++) {
            file << newspapers[i].title << " , " << newspapers[i].year << endl;
        }

        file.close();
        cout << "Library data saved to " << filename << endl;
    }

    void selectJournalsByYear(int year) const {
        bool found = false;
        for (int i = 0; i < journalCount; i++) {
            if (journals[i].year == year) {
                journals[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No journals found for year: " << year << endl;
        }
    }

    int countBooksByCategory(const char* category) const {
        int count = 0;
        for (int i = 0; i < bookCount; i++) {
            if (strcmp(books[i].category, category) == 0) {
                count++;
            }
        }
        return count;
    }

    void clear() {
        delete[] books;
        delete[] journals;
        delete[] newspapers;
    }
};

int main() {
    Library library;
    library.initialize();

    library.addBook("1984", "George Orwell", "Dystopian");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "Fiction");
    library.addBook("Pride and Prejudice", "Jane Austen", "Romance");
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "Classic");
    library.addBook("Moby-Dick", "Herman Melville", "Adventure");
    library.addBook("War and Peace", "Leo Tolstoy", "Historical");
    library.addBook("The Catcher in the Rye", "J.D. Salinger", "Fiction");
    library.addBook("Brave New World", "Aldous Huxley", "Dystopian");

    library.addJournal("Nature", 2021);
    library.addJournal("Science", 2022);
    library.addJournal("The Lancet", 2023);
    library.addJournal("New England Journal of Medicine", 2023);

    library.addNewspaper("The New York Times", 2023);
    library.addNewspaper("The Guardian", 2023);
    library.addNewspaper("The Wall Street Journal", 2022);
    library.addNewspaper("The Washington Post", 2023);

    int choice;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Add Journal\n";
        cout << "3. Add Newspaper\n";
        cout << "4. Display All Sources\n";
        cout << "5. Remove Book\n";
        cout << "6. Remove Journal\n";
        cout << "7. Remove Newspapers by Year\n";
        cout << "8. Search for Book\n";
        cout << "9. Search for Journal\n";
        cout << "10. Select Books by Author\n";
        cout << "11. Select Books by Category\n";
        cout << "12. Select Journals by Year\n";
        cout << "13. Count Books by Category\n";
        cout << "14. Save to File\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            char title[100], author[100], category[50];
            cout << "Enter book title: ";
            cin.ignore();
            cin.getline(title, 100);
            cout << "Enter book author: ";
            cin.getline(author, 100);
            cout << "Enter book category: ";
            cin.getline(category, 50);
            library.addBook(title, author, category);
            break;
        }
        case 2: {
            char title[100];
            int year;
            cout << "Enter journal title: ";
            cin.ignore();
            cin.getline(title, 100);
            cout << "Enter journal year: ";
            cin >> year;
            library.addJournal(title, year);
            break;
        }
        case 3: {
            char title[100];
            int year;
            cout << "Enter newspaper title: ";
            cin.ignore();
            cin.getline(title, 100);
            cout << "Enter newspaper year: ";
            cin >> year;
            library.addNewspaper(title, year);
            break;
        }
        case 4:
            library.displayAll();
            break;
        case 5: {
            char title[100];
            cout << "Enter book title to remove: ";
            cin.ignore();
            cin.getline(title, 100);
            library.removeBook(title);
            break;
        }
        case 6: {
            char title[100];
            cout << "Enter journal title to remove: ";
            cin.ignore();
            cin.getline(title, 100);
            library.removeJournal(title);
            break;
        }
        case 7: {
            int year;
            cout << "Enter year to remove newspapers: ";
            cin >> year;
            library.removeNewspapersByYear(year);
            break;
        }
        case 8: {
            char title[100], author[100];
            cout << "Enter book title to search: ";
            cin.ignore();
            cin.getline(title, 100);
            cout << "Enter book author to search: ";
            cin.getline(author, 100);
            library.searchBook(title, author);
            break;
        }
        case 9: {
            char title[100];
            int year;
            cout << "Enter journal title to search: ";
            cin.ignore();
            cin.getline(title, 100);
            cout << "Enter journal year to search: ";
            cin >> year;
            library.searchJournal(title, year);
            break;
        }
        case 10: {
            char author[100];
            cout << "Enter author to select books: ";
            cin.ignore();
            cin.getline(author, 100);
            library.selectBooksByAuthor(author);
            break;
        }
        case 11: {
            char category[50];
            cout << "Enter category to select books: ";
            cin.ignore();
            cin.getline(category, 50);
            library.selectBooksByCategory(category);
            break;
        }
        case 12: {
            int year;
            cout << "Enter year to select journals: ";
            cin >> year;
            library.selectJournalsByYear(year);
            break;
        }
        case 13: {
            char category[50];
            cout << "Enter category to count books: ";
            cin.ignore();
            cin.getline(category, 50);
            int count = library.countBooksByCategory(category);
            cout << "Number of books in category '" << category << "': " << count << endl;
            break;
        }
        case 14: {
            library.saveToFile("library_data.txt"); 
            break;
        }
        case 0:
            break;
        }
    } while (choice != 0);

    library.clear();
}

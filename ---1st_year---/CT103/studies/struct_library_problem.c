#include <stdio.h>

typedef struct {
    char title[20];
    char author[20];
    int year;
    float value;
}book;

void show_library();
void add_book(char t[20] char a[20], int y, float v);

book library[100]; // global library
int no_books = 0;  // also the index

void main() {
    addbook("the dispossessed", "ursula k leguin", 1974, 15.00);
    show_library();
}

void add_book (char t[20] char a[20], int y, float v) { // not quite a constructor
    if (no_books < 100) {
        strcpy_s(library[no_books].title, 20, t);
        strcpy_s(library[no_books].author, 20, a);
        library[no_books].year = y;
        library[no_books].value = v;
    }
    else {
        printf("no more room\n");
    }
}

void show_library() {
    for (int i = 0; i<no_books; i++) {
        printf("book no. %3d", no_books+1);
        printf("title:%25c\nauthor:%25c\nyear:%25d\nvalue:%25c\n", library[i].title,library[i].author,library[i].year,library[i].value);
    }
}

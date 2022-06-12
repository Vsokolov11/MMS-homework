#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 10


typedef struct book
{
    char title[101];
    char author[151];
    unsigned pages;
    double price;
} Book;


void randomName(char*);
void randomTitle(char*);
int randint(int,int);
void printBook(Book*);
int compareAuthorASC(const void*,const void*);
int compareAuthorDESC(const void*,const void*);
int compareTitleASC(const void*,const void*);
int compareTitleDESC(const void*,const void*);
int comparePagesASC(const void* bp1, const void* bp2);
int comparePagesDESC(const void* bp1, const void* bp2);
int comparePriceASC(const void* bp1, const void* bp2);
int comparePriceDESC(const void* bp1, const void* bp2);

void *linearSearch(const void *, const void *, size_t, size_t, int (*compar)(const void *, const void *));


//MAIN
int main(){
    srand(time(NULL));
    Book books[COUNT];
    int (*compf[]) (const void*, const void*)={
        compareAuthorASC,
        compareAuthorDESC,
        compareTitleASC,
        compareTitleDESC,
        comparePagesASC,
        comparePagesDESC,
        comparePriceASC,
        comparePriceDESC
    };
    int opt = 7;

    for (int i = 0; i < COUNT - 1; i++){

        randomTitle(books[i].title);
        randomName(books[i].author);
        books[i].pages = randint(50, 800);
        books[i].price = randint(5,100);
    }

    Book b1 = {
        .author = "William Golding",
        .title = "Lord of the flies",
        .price = 10,
        .pages = 350,
        
    };
    books[COUNT - 1] = b1;
    qsort(books, COUNT, sizeof(Book), compf[opt]);

    

    for (int i = 0; i < COUNT; i++)
    {
        printBook(&books[i]);
    }
    
    Book key = {.author="William",.title="Lord of the flies", .price = 10, .pages = 350};

    Book *element = linearSearch(&key, books, COUNT,  sizeof(*books), comparePriceDESC);

    if(!element){
        printf("Not found...\n");
    }
    else{
        printf("\nThe book you are seearching for: \n\n");
        printBook(element);
        putchar('\n');
    }

    return 0;
}


void randomName(char* name){

    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(5, 10);
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index++] = ' ';
    n = randint(5, 10);
    name[index++] = randint('A', 'Z');
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
}

void randomTitle(char* title){
    int n = randint(5, 10);
    unsigned index = 0;
    title[index++] = randint('A', 'Z');
    for (int i = 0; i < n; i++){
        title[index++] = randint('a', 'z');
    }
    title[index] = '\0';
}


int randint(int min, int max){
    return min + rand() % (max - min + 1);
}


void printBook(Book *b){
    printf("Title:%25s ", b->title);
    printf("Author:%25s ", b->author);
    printf("Pages:%4u ", b->pages);
    printf("Price:%4.2lf \n", b->price);
}
int compareAuthorASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b1->author, b2->author);
}

int compareAuthorDESC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b2->author, b1->author);
}
int compareTitleASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b1->title, b2->title);
}

int compareTitleDESC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b2->title, b1->title
    );
}
int comparePagesASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return b1->pages-b2->pages;
}

int comparePagesDESC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return b2->pages-b1->pages;
}
int comparePriceASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return b1->price-b2->price;
}

int comparePriceDESC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return b2->price-b1->price;
}
void *linearSearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *)){
    for (int i = 0; i < nitems; i++){
        if(compar(key, base + i * size) == 0){
            return base + i * size;
        }
    }
    return NULL;
}
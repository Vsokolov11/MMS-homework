#include<stdio.h>
#include<stdlib.h>

#define COUNT 5

typedef struct Books{
    char title[21];
    char author[21];
    unsigned pages;
    double price;
} Book;

typedef struct node{
    Book book;
    struct node* next;
} Node;


void push(Node**, Book);
void print_booklist(Node*);
int compareBooksTitleASC(Book*,Book*);
Node* sortedMerge(Node*, Node*, int(*)(Book, Book));
void frontBackSplit(Node*, Node**, Node**);
void mergeSort(Node**, int(*)(int, int));



int main(){
    FILE* fptr;
    Book books[COUNT];
    Node* booklist = NULL;
    
    char name[15];
    scanf("%s", name);
    
    fptr = fopen(name, "r+");
    fread(books, sizeof(books[0]), COUNT, fptr);
    fclose(fptr);
    for (size_t i = 0; i < COUNT; i++)
    {
        push(&booklist, books[i]);
        printf("Title:%25s ", books[i].title);
        printf("Author:%25s ", books[i].author);
        printf("Pages:%5d ", books[i].pages);
        printf("Price:%6.2lf\n", books[i].price);
    } 
    putchar('\n');putchar('\n');

    print_booklist(booklist);
    
}

void push(Node** list, Book book){
    Node* n = malloc(sizeof(Node));
    n->book = book;
    n->next = *list;
    *list = n;
}
void print_booklist(Node* list){
    Node* curr = list;
    while (curr != NULL)
    {
        printf("Title:%25s", curr->book.title);
        printf(" Author:%25s", curr->book.author);
        printf(" Pages:%5d", curr->book.pages);
        printf(" Price:%6.2lf", curr->book.price);
        putchar('\n');
        curr = curr->next;
    }
    putchar('\n');
}
int compareBooksTitleASC(Book* b1,Book* b2){
    while (res = 0)
    {
        /* code */
    }
    
}
Node* sortedMerge(Node* listA, Node* listB, int(*cmp)(Book, Book)){
    Node* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (cmp(listA->book, listB->book) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}


void frontBackSplit(Node* list, Node** front, Node** back){
    Node* slow = list;
    Node* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(Node** list, int(*cmp)(int, int)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    Node *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}
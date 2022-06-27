#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include<string.h>


#define ITEMS_COUNT 5

typedef struct item{
    uint16_t numbmer;
    char desc[250];
    double weight;
    double price;

}Item;

typedef struct node_t{
    Item data;
    struct node_t* next;
}node_t;


//FUNCTIONS
void push(node_t** , Item);
void listFree(node_t**);
double rndDouble(double,double);
int randint(int,int);
void rndDesc(char*);
double totalItemsWeight(node_t*);
node_t *minPriceItem(node_t*);
int comparePriceDESC(Item*,Item*);
void print_list(node_t*);
node_t* sortedMerge(node_t*,node_t*,int(*)(Item, Item));
void frontBackSplit(node_t*,node_t**,node_t**);
void mergeSort(node_t**,int(*)(Item, Item));

int main(){
    srand(time(NULL));
    node_t *items = NULL;
    for(int i = 0; i < ITEMS_COUNT; i++){
        Item temp;
        char desc[250];
        rndDesc(desc);

        temp.numbmer = rand() % 65000;
        strcpy(temp.desc, desc);
        temp.weight = rndDouble(0.100, 100.00);
        temp.price = rndDouble(1.00, 1500.00);
        push(&items, temp);
        //printf("%d, %lf, %lf, %s\n", temp.numbmer, temp.price, temp.weight, temp.desc);
    }
    print_list(items);
    putchar('\n');
    //print_list(items);
    node_t *minPrice = minPriceItem(items);
    printf("The Lowest priced item is: Number: %6d, Description: %s, Price: %8.3lf, Weight: %5.3lf\n",minPrice->data.numbmer,minPrice->data.desc, minPrice->data.price, minPrice->data.weight);
    double totalW = totalItemsWeight(items);
    printf("The total weight is: %.3lf\n", totalW);
    
    return 0;
}



void push(node_t** list, Item data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}
double rndDouble(double min, double max){
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void rndDesc(char* desc){
    unsigned index = 0;
    int n = randint(1, 5);
    for(int i = 0; i < n; i++){
        desc[index++] = (char)randint('A', 'Z');
        int n1 = randint(1, 10);
        for (int i = 0; i < n1; i++){
            desc[index++] = (char)randint('a', 'z');
        }
        if(i + 1 == n){
            continue;
        }
        desc[index++] = ' ';
    }
}
int randint(int min, int max){
    return min + rand() % (max - min + 1);
}
double totalItemsWeight(node_t* item){
    double total = 0;
    node_t *curr = item;
    for (size_t i = 0; i < ITEMS_COUNT; i++)
    {
        total += curr->data.weight;
        if(curr->next != NULL)
        {
            curr = curr->next;
        }
    }
    return total;
}
node_t *minPriceItem(node_t* item){
    mergeSort(&item, comparePriceDESC);
    return item;
}
int comparePriceDESC(Item *item1, Item *item2){
    Item* i1 = (Item *) item1;
    Item* i2 = (Item *) item2;
    return i2->price-i1->price;
}

void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("Number: %6d, Description: %60s, Price: %8.3lf, Weight: %5.3lf\n",current->data.numbmer,current->data.desc, current->data.price, current->data.weight);
        current = current->next;
    }
    putchar('\n');
}

//MERGED SORT
node_t* sortedMerge(node_t* listA, node_t* listB, int(*cmp)(Item, Item)){
    node_t* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (cmp(listA->data, listB->data) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}


void frontBackSplit(node_t* list, node_t** front, node_t** back){
    node_t* slow = list;
    node_t* fast = list->next;
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

void mergeSort(node_t** list, int(*cmp)(Item, Item)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    node_t *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}
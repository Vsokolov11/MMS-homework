#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

#define COUNT 5

typedef struct point_t{
    double x;
    double y;
}point_t;

typedef struct rect{
    point_t a;
    point_t b;
}Rect;

typedef struct node_t{
    Rect data;
    struct node_t* next;
}node_t;

void push(node_t** , Rect);
void listFree(node_t**);
double dblrand(double, double);
double areaRects(node_t*);
void printAreaRects(node_t*);
double areaRect(node_t*);
void filterRecs(node_t**,double, double);
void deleteNth(node_t**, size_t);

int main(){
    srand(time(NULL));
    node_t* rectlist = NULL;
    for (size_t i = 0; i < COUNT; i++)
    {
        Rect temp;
        temp.a.x = dblrand(-10.0, 10.0);
        temp.a.y = dblrand(-10.0, 10.0);
        temp.b.x = dblrand(-10.0, 10.0);
        temp.b.y = dblrand(-10.0, 10.0);
        push(&rectlist, temp);
    }
    printf("The sum of areas is: %.3lf\n", areaRects(rectlist));
    printf("Areas before filter:\n");
    printAreaRects(rectlist);
    filterRecs(&rectlist, 25.5, 40.5);
    printf("Areas after filter:\n");
    printAreaRects(rectlist);
}

void push(node_t** list, Rect data){
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

double dblrand(double min, double max){
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

double areaRects(node_t* list){
    double areaSum = 0;
    double area = 0;
    while (list != NULL)
    {
        double ax = list->data.a.x;
        double ay = list->data.a.y;
        double bx = list->data.b.x;
        double by = list->data.b.y;

        double sidea = fabs(ax-bx);
        double sideb = fabs(ay-by);
        area = sidea * sideb;
        areaSum +=area;
        list = list->next;
    }
    return areaSum;
}
void printAreaRects(node_t* list){
    double area = 0;
    int i = 1;
    while (list != NULL)
    {
        double ax = list->data.a.x;
        double ay = list->data.a.y;
        double bx = list->data.b.x;
        double by = list->data.b.y;

        double sidea = fabs(ax-bx);
        double sideb = fabs(ay-by);
        area = sidea * sideb;
        printf("The area of the %d rect is: %.2lf\n",i , area);
        list = list->next;
        i++;
    }

}

double areaRect(node_t* list){
    double area = 0;
    double ax = list->data.a.x;
    double ay = list->data.a.y;
    double bx = list->data.b.x;
    double by = list->data.b.y;
    double sidea = fabs(ax-bx);
    double sideb = fabs(ay-by);
    area = sidea * sideb;
    return area;
}
void filterRecs(node_t** list,double min, double max){
    int n = 0;
    node_t* listA = *list;
    while (listA !=NULL)
    {
        double area = areaRect(listA);
        if(area > min && area < max){
            deleteNth(list, n);
            printf("Areas to be deleted: %lf\n", area);
        }
        n++;
        listA = listA->next;
    }
}
void deleteNth(node_t** list, size_t n){
    if (*list == NULL){
        return;
    }
    if (n == 0){
        node_t* temp = *list;
        *list = (*list)->next;
        free(temp);
        return;
    }
    node_t* current = *list;
    node_t* prev = current;
    while (current && n--) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
}
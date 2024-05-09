#include <stdio.h>
#include <malloc.h>
struct node{
    int val;
    struct node *next;
} *start;

void insert(int val){
    struct node *cur = (struct node*) malloc(sizeof(struct node)), *temp;
    cur->val = val;
    cur->next = NULL;
    if(start==NULL){
        start = cur;
        return;
    }
    temp = start;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = cur;
}

void insertAtPos(int val, int pos){
    struct node *cur = (struct node*) malloc(sizeof(struct node)), *temp, *temp2;
    cur -> val = val;
    if(pos == 1){
        temp = start;
        start = cur;
        cur -> next = temp;
    } else{
        temp = start;
        for(int j=1; j<pos-1; j++){
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = cur;
        cur ->next = temp2;
    }
}

void print(){
    struct node *temp;
    if(start==NULL){
        puts("List Empty!");
        return;
    }
    temp = start;
    printf("List: ");
    do {
        printf("%d ", temp->val);
        temp = temp->next;
    } while(temp);
    puts("");
}

int main(){
    start = NULL;
    int n, i, x;

    scanf("%d", &n);
    print();
    for (i=0; i<n; i++){
        scanf("%d", &x);
        insert(x);
        print();
    }
    printf("Where do you want insert your number: ");
    scanf("%d", &i);
    printf("Enter the value you want to insert: ");
    scanf("%d", &x);
    insertAtPos(x, i);
    print();

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void begin();
void end();
void specified();
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* tail=NULL;
struct node* new=NULL;
struct node* temp=NULL;
int main(){
    create();
    display();
    begin();
    end();
    specified();
}
void create(){
    int n;
    printf("enter the total nodes");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        if(head==NULL){
                    head=new;
                    tail=new;
        }
        else{
            tail->next=new;
            tail=new;
            tail->next=head;
        }
    }
}
void display(){
        
        temp=head;
        while(temp->next!=head){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
}
void begin(){
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter node at beginning");
        scanf("%d",&new->data);
        temp=head;
        tail->next=new;
        new->next=temp;
        head=new;
        display();
}
void end(){
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter node at end");
        scanf("%d",&new->data);
        tail->next=new;
        new->next=head;
        tail=new;   
        display(); 
}
void specified(){
    int p;
    printf("enter specified position to insert");
    scanf("%d",&p);
    new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    temp=head;
    for(int i=0;i<p-2;i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    display();
}

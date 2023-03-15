#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*next;
}Node;

void addNode(Node** head,int data){
    Node*newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if(*head==NULL){
        *head = newnode;
    }else{
        Node*current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
}

void deleteNode(Node**head,int data){
    Node*current = *head;
    Node*previous = NULL;
    while (current!=NULL)
    {
        if (current->data==data)
        {
            if (previous==NULL)
            {
                *head = current->next;
            }else{
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
        
    }

}

Node*searchNode(Node*head,int data){
    Node*current = head;
    while (current!=NULL)
    {
        if (current->data==data)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void printList(Node*head){
    Node*current = head;
    while (current->next!=NULL)
    {
        printf("%d->",current->data);
        current = current->next;
    }
    printf("%d",current->data);
    printf("\n");
    
}
int main(){
    Node*head = NULL;
    while (1)
    {
        printf("please input the number: \n");
        printf("1 mean addNode\n");
        printf("2 mean deleteNode\n");
        printf("3 mean search Node\n");
        printf("4 mean printList\n");
        int num;
        int node_num;
        scanf("%d",&num);
        switch (num)
        {
        case 1:
            printf("input the node number:");
            scanf("%d",&node_num);
            addNode(&head,node_num);
            break;
        case 2:
            printf("input the node number you want delete:");
            scanf("%d",&node_num);
            deleteNode(&head,node_num);
            break;
        case 3:
            printf("input the node number you want search:");
            scanf("%d",&node_num);
            printf("your search number address is %d",searchNode(head,node_num));
            break;
        case 4:
            printList(head);
            break;
        
        }
    }
    

    
    return 0;
}
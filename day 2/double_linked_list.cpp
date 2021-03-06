#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	node *next;
	node *prev;
};

void insert_node(node **head,int val)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = val;
	new_node->prev = NULL;
	new_node->next = NULL;
	if(*head==NULL)
	{
		*head = new_node;
	}
	else
	{
		node *curr = *head;
		while((curr->next)!=NULL)
		{
			curr = curr->next;
		}
		curr->next = new_node;
		new_node->prev = curr;
	}
}
void display_list(node *head)
{
	if(head==NULL)
	{
		printf("Empty List");
	}
	else
	{
		while(head)
		{
			printf("%d ->",head->data);
			head = head->next;
		}
	}
}
void insert_pos(node **head,int val,int pos){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=val;
    new_node->next=NULL;
    new_node->prev=NULL;
    node *curr,*curr_next,*curr_prev;
    if(pos==1){
        if(*head==NULL){
            //new_node=*head;
            *head = new_node;
        }
        else{
            new_node->next=*head;
            (*head)->prev=new_node;
            *head=new_node;
        }
        return ;
    }
    else{
        curr=*head;
        //printf("%d",curr->data);
        for(int i=1;i<pos;i++){
            curr=curr->next;
            curr_prev=curr->prev;
			curr_next=curr->next;
        }
        curr_prev->next=new_node;
        new_node->next=curr;
        curr->prev=new_node;
        new_node->prev=curr_prev;
    }
}
void delete_by_val(node **head,int val)
{
	if((*head)->data ==  val)
	{
		node * temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		node *curr = *head;
		while((curr->data)!=val)
		{
			curr = curr->next;
		}
		node *curr_prev = curr->prev;
		node *curr_next = curr->next;
		curr_prev ->next = curr_next;
		curr_next->prev = curr_prev;
		free(curr);
	}
}
int main()
{
	node *head = NULL;
	insert_node(&head,10);
	insert_node(&head,20);
	insert_node(&head,30);
	//delete_by_val(&head,20);
	insert_pos(&head,50,3);
	display_list(head);
}

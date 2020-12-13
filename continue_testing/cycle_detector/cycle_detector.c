   

#include "list.h"
#include <unistd.h>
#include <stdlib.h>


/* just a cycle with a "found-myself" check */
int        cycle_detector(const t_list *list)
{
	const t_list *still = list;
	const t_list *moving= list;

	while(moving->next)
	{
		if(still == moving->next)
			return (1);
		moving = moving->next;
	}
	return (0);
}

/* this looks kinda bugged for when i try to remove head of the list
	if someone can make it work pls tell me */
void ft_list_remove_if(t_list **begin_list, int r_data, int (*cmp)(int, int))
{

	t_list	*this;
	t_list  *last;
	t_list  *forw;

	this = *begin_list;
	/* cmp and in case iteratively remove head and fetch new */
	/* this does not work */
	while(!cmp(this->data, r_data) && this)
	{
		last = this;
		this = this->next;
		begin_list = &this;
		free(last);
	}

	*begin_list = this;
	if (this->next)
		this = this->next;
	/* iteratively walk the list and cmp */
	while(this->next)
	{
		forw = this->next;
		if (!cmp(forw->data, r_data))
		{
			this->next = forw->next;
			free(forw);
		}
		this = this->next;
	}	
}	

#include <stdio.h>
void putdata(const t_list *list)
{
	const t_list *head = list;

	/* just like your typical while loop */
	while(head)
	{
		printf("%d \n", head->data);
		head = head->next;
	}
}

/* frees all*/
void freeall(t_list *list)
{
	t_list *head = list;
	t_list  *tmp = head;
	while(head)
	{
		tmp = head;	
		head = head->next;
		free(tmp);
	}
}

int custom_comparator(int a, int b)
{
	return (a-b);
}


int main()
{

	/* create a test list */
	t_list *list1=(t_list*)malloc(sizeof(t_list));
	t_list *list2=(t_list*)malloc(sizeof(t_list));
	t_list *list3=(t_list*)malloc(sizeof(t_list));
	t_list *list4=(t_list*)malloc(sizeof(t_list));
	t_list *head =(t_list*)malloc(sizeof(t_list));

	list1->next = list2;
	list1->data = 1;
	list2->next = list3;
	list2->data = 2;
	list3->next = list4;
	list3->data = 3;

	/* create a loop */
	list4->next = list1;
	list4->data = 4;
	
	
	if(cycle_detector(list2))
		write(1, "ok\n", 3);

	/* destroy a loop */
	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = NULL;

	if(!cycle_detector(list2))
		write(1, "ok\n", 3);


	/* remove an element */
	putdata(list1);
	/* THIS WILL NOT REMOVE!, head is list4 */
	ft_list_remove_if(&list4, 3, custom_comparator);
	putdata(list1);

	/* this will remove */
	ft_list_remove_if(&list1, 3, custom_comparator);
	putdata(list1);
	head = list1;

	/* THIS AINT WORKING DAAAMN WHAT AM I MISSING*/ 
	ft_list_remove_if(&head, 1, custom_comparator);
	putdata(head);


	//freeall(list1);
}
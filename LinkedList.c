#include "LinkedList.h"

List newList(){
	List l=malloc(sizeof(llist));
	if(l==NULL){
		printf("<LOG - LinkedList.c>\n\tInsufficient memory.\n<end>\n");
		exit(1);
	}
	initList(l);
	return l;
}

void initList(List list){
	list->NumEl = 0;
	list->pFirst = NULL;
	list->pLast = NULL;
}

Element addToList(void *item, List list){
	//check inputs
 	//  assert(item!=NULL); assert(list!=NULL);
	if(item == NULL || list == NULL){
		printf("<LOG - LinkedList.c>\n\tNull pointer.\n<end>\n");
		exit(1);
	}

	//Create generic element to hold item ptr
    Element NewEl;
    NewEl = (Element)malloc(sizeof(lelement));  //create generic element

	if(NewEl == NULL){
		printf("<LOG - LinkedList.c>\n\tInsufficient memory.\n<end>\n");
		exit(1);
	}

    list->NumEl = list->NumEl + 1;
    NewEl->data = item;
    if (list->NumEl == 1)
    {
      list->pFirst = NewEl;
      NewEl->prev = NULL;
      NewEl->next = NULL;
    }
    else
    {
      NewEl->prev = list->pLast;
      NewEl->next = NULL;
      list->pLast->next = NewEl;
    }
    list->pLast = NewEl;
    return NewEl;
}

void addElemToList(Element NewEl, List list){
	list->NumEl = list->NumEl + 1;
    if (list->NumEl == 1)
    {
      list->pFirst = NewEl;
      NewEl->prev = NULL;
      NewEl->next = NULL;
    }
    else
    {
      NewEl->prev = list->pLast;
      NewEl->next = NULL;
      list->pLast->next = NewEl;
    }
    list->pLast = NewEl;
    return;
	
}

void removeElemFromList(Element elem, List list){
	Element item;
	int index=-1;
	int i=0;
	FOR_EACH(item, list){
		if(item == elem){
			printf("lo encontre\n");
			index = i;
			break;
		}
		i++;
	}
	if(index < 0){
		return;
	}
	printf("el flag esta bien %i/%i\n",index,list->NumEl);
	/* Soy el primero */
	if(list->pFirst == elem){
		printf("caso A");
		list->pFirst = elem->next;
		if(elem->next != NULL){
			elem->next->prev = NULL;
		}
	}
	printf("no caso A");
	/* Soy el ultimo */
	if(list->pLast == elem){
		printf("caso B");
		list->pLast = elem->prev;
		if(elem->prev != NULL){
			elem->prev->next = NULL;
		}
	}
	printf("no caso B");
	if(elem->prev != NULL && elem->next != NULL){
		printf("caso C");
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
	}
	printf("no caso C");
	printf("caso D");
	elem->prev = NULL;
	elem->next = NULL;
	(list->NumEl)--;
	return;
}


#include "linkedList.hpp"


void checkHead(Node *head) {
	if(head == NULL) {
		std::cout<<"Head is NULL from function ::" << __func__ << "\n";
		exit(-1);
	}
}


void push(Node **head, Point p) {
	//as in stack
	checkHead(*head);
	Node *tmp = new Node;
	tmp->p = p;
	tmp->next = *head;
	(*head) = tmp;
}


Point pop(Node **head) {
	//as in stack
	Node *tmp = NULL;
	checkHead(*head);
	tmp = *head;
	Point val = (*head)->p;
	*head = (*head)->next;
	free(tmp);
	return val;
}


Node *getLast(Node *head) {
	if(head == NULL) {
		return NULL;
	}
	while(head->next != NULL) {
		head = head->next;
	}
	return head;
}


Node *getOneBeforeLast(Node *head) {
	checkHead(head);
	if(head->next == NULL) {
		return NULL;
	}
	while(head->next->next != NULL) {
		head = head->next;
	}
	return head;
}


void popBack(Node **head) {
	Node *tmp = getOneBeforeLast(*head);
	if(tmp == NULL) {
		free(*head);
		*head = NULL;
		return;
	}
	Node *last = tmp->next;
	tmp->next = NULL;
	free(last);
}


void pushBack(Node *head, Point p) {
	Node *tmp = new Node;
	head = getLast(head);
	head->next = tmp;
	tmp->p = p;
	tmp->next = NULL;
}


Node *getNth(Node *head, int n) {
	checkHead(head);
	int cnt = 0;
	while(head && cnt < n) {
		head = head->next;
		cnt++;
	}
	return head;
}


void insert(Node *head, Point p, int n) {
	//insert node after n`th elem
	int cnt = 1;
	while(head -> next && cnt < n) {
		head = head->next;
		cnt++;
	}
	Node *tmp = new Node;
	tmp->p = p;
	if(head->next) {
		tmp->next = head->next;
	} else {
		tmp->next = NULL; // inserting after last
	}
	head->next = tmp;
}


void deleteNth(Node **head, int n) {
	if(n == 0) {
		pop(head);
	}
	else {
		Node *prev = getNth(*head, n-1);
		Node *tmp = prev->next;
		if(tmp) {
			prev->next = tmp->next;
			free(tmp);
		}
		else {
			std::cout <<__func__ << " :: List out of range\n";
		}
	}
}



void deleteList(Node** head) {
	Node* current = *head;
	Node* next;
	while (current != NULL) {
    	next = current->next;
    	free(current);
    	current = next;
	}
	*head = NULL;
}


void printList(Node *head) {
	while(head!= NULL) {
		std::cout << head->p.x << "->";
		head = head->next;
	}
	std::cout << "NULL" << "\n";
}
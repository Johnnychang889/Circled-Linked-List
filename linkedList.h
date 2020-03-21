#ifndef LINKEDLIST_H
#define LINKEDLIST_H


constexpr auto width = 640;
constexpr auto height = 480;
constexpr auto N = 10;
constexpr auto MaxRad = 30;


#include <iostream>
#include <random>
#include <ctime>

struct Point {
	int x;
	int y;
	int r;
};

struct Node {
	Point p;
	Node *next;
};

void push(Node **head, Point p); // add in beginning of the list

Point pop(Node **head); // delete from head of the list

Node* getLast(Node *head);

void pushBack(Node *head, Point p);

Node *getOneBeforeLast(Node *head);

void popBack(Node **head);

Node *getNth(Node *head, int n);

void printList(Node *head);

void checkHead(Node *head);

void insert(Node *head, Point p, int n);

void deleteNth(Node **head, int n);

void deleteList(Node **head);

void createRandomList(Node *head, int n);

//utils
Point createRandomPoint();

#endif
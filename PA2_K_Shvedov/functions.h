#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA2
* Date: 15/09/2017
* Description: This is the header file where all the function prototypes are stored
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>

typedef struct duration
{
	int minutes;
	int seconds;
} Duration;

typedef struct record
{
	char artist[50];
	char album_title[50];
	char song_title[50];
	char genre[20];
	Duration song_length;
	int times_played;
	int rating;
} Record;

typedef struct node
{
	Record data;
	struct node *pNext;
	struct node *pPrev;
} Node;

//struct Node* pHead;
//struct Node *last;
//struct Node *current;

void white_on_black(void);

void main_call(void);

void display_menu(void);

void load_r(Node **head);

void store_r(Node *head);

void display_r(Node *head);

void insert_r(Node **head);

void delete_r(Node **head);

void edit_r(Node **head);

void sort_r(Node **head);

void rate_r(Node **head);

void play_r(Node *head);

void shuffle_r(Node *head);

Node * makeNode(Record newData);

void clear_screen(void);

int numb_check(char data[50]);

int random(int n);

bool empty(void);

#endif
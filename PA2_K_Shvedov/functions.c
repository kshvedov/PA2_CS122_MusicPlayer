#include "functions.h"
/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA2
* Date: 15/09/2017
* Description: This is the where all the fucntion codeing is stored
*/
struct Node* head = NULL;

/*
Function: void clear_screen(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of changing the colors to a brighter color
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void white_on_black(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
}

/*
Function: void main_caller(void)
Date Created : 15/09/2017
Date Last Modified : 22/09/2017
Description : This function is in charge of the whole prorgram, all functions and calculations are called within,
all that has to be done is for it, is to be called in main for the whole program to work
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void main_call(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	printf("This program has been stilized to ");
	SetConsoleTextAttribute(hConsole, 10);
	printf("8 bit");
	SetConsoleTextAttribute(hConsole, 15);
	printf(", \n your computer isn't lagging,\n sorry for any inconvinience\n\n");
	clear_screen();
	Node *head = NULL;
	char selection_t[50];
	int check = 0, selection = 0;
	white_on_black();
	//displays menu and propts user to make selection
	while (selection != 11)
	{
		display_menu();
		SetConsoleTextAttribute(hConsole, 15);
		gets(selection_t);
		while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > 11)
		{
			printf("Please input valid selection: ");
			gets(selection_t);
		}
		selection = atoi(selection_t);
		//depending on what they choose program takes them there (WOW, TIME TRAVEL?)
		if (selection == 1)
		{
			load_r(&head);
		}
		else if (selection == 2)
		{
			if (head != NULL)store_r(head);
			else {
				printf("Nothing to store\n");
				clear_screen();
			}
		}
		else if (selection == 3)
		{
			if (head != NULL)display_r(head);
			else { printf("Nothing to print\n");
			clear_screen();
			}
		}
		else if (selection == 4)
		{
			insert_r(&head);
		}
		else if (selection == 5)
		{
			if (head != NULL)delete_r(&head);
			else {
				printf("Nothing to delete\n");
				clear_screen();
			}
		}
		else if (selection == 6)
		{
			if (head != NULL)edit_r(&head);
			else {
				printf("Nothing to edit\n");
				clear_screen();
			}
		}
		else if (selection == 7)
		{
			if (head != NULL)sort_r(&head);
			else {
				printf("Nothing to sort\n");
				clear_screen();
			}
		}
		else if (selection == 8)
		{
			if (head != NULL)rate_r(&head);
			else {
				printf("Nothing to rate\n");
				clear_screen();
			}
		}
		else if (selection == 9)
		{
			if (head != NULL)play_r(head);
			else {
				printf("Nothing to play\n");
				clear_screen();
			}
		}
		else if (selection == 10)
		{
			if (head != NULL)shuffle_r(head);
			else {
				printf("Nothing to play\n");
				clear_screen();
			}
		}
		else if (selection == 11)
		{
			//Program says thank you before leaving, how polite?
			printf("Thank you for using this program!\n");
		}
	}
}

/*
Function: void display_menu(void)
Date Created : 15/09/2017
Date Last Modified : 22/09/2017
Description : Just prints the menu
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void display_menu(void)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	printf("      MAIN MENU\n");
	SetConsoleTextAttribute(hConsole, 15);
	printf("(1)\tLoad\n");
	printf("(2)\tStore\n");
	printf("(3)\tDisplay\n");
	printf("(4)\tInsert\n");
	printf("(5)\tDelete\n");
	printf("(6)\tEdit\n");
	printf("(7)\tSoart\n");
	printf("(8)\tRate\n");
	printf("(9)\tPlay\n");
	printf("(10)\tShuffle\n");
	SetConsoleTextAttribute(hConsole, 12);
	printf("(11)\tExit\n\n");
	SetConsoleTextAttribute(hConsole, 10);
	printf("Please make a selection: ");
}

/*
Function: void load_r(Node **head)
Date Created : 12/09/2017
Date Last Modified : 22/09/2017
Description : Loads all the information from csv file into the list using make node and a insert at front function
Input parameters : Node **head
Returns : None
Precondition : Call function
Postconditions : None
*/
void load_r(Node **head)
{
	system("cls");
	FILE *infile = NULL;
	char line[100] = "";
	char copyline[100] = "";
	char *tok;
	int i = 1, n = 0;
	Record data;
	printf("Loading file\n");
	Sleep(500);
	infile = fopen("musicPlayList.csv", "r");
	printf("File Loaded\n");
	printf("Inserting data");
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	Sleep(250);
	while (fgets(line, 100, infile) != NULL)
	{
		strcpy(copyline, line);
		if (line[0] == '\"')
		{
			strcpy(data.artist, strtok(line, "\""));
		}
		else
		{
			strcpy(data.artist, strtok(line, ","));
		}
		strcpy(data.album_title, strtok(NULL, ","));
		strcpy(data.song_title, strtok(NULL, ","));
		strcpy(data.genre, strtok(NULL, ","));
		data.song_length.minutes = atof(strtok(NULL, ":"));
		data.song_length.seconds = atof(strtok(NULL, ","));
		data.times_played = atof(strtok(NULL, ","));
		data.rating = atof(strtok(NULL, "\0"));

		insertFront(head, data);
		n++;
		printf("added record %d\n", n);
		Sleep(250);
	}
	printf("Closing file");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	Sleep(250);
	fclose(infile);
	printf("File closed\n");
	clear_screen();
}

/*
Function: void store_r(Node *head)
Date Created : 12/09/2017
Date Last Modified : 22/09/2017
Description : Stores all the current records into a csv file overwriting all old info
Input parameters : Node *head
Returns : None
Precondition : Call function
Postconditions : None
*/
void store_r(Node *head)
{
	FILE *infile = NULL;
	Node *first = (Node*)malloc(sizeof(Node));
	first = head;
	system("cls");
	printf("Opening file\n");
	Sleep(500);
	infile = fopen("musicPlayList.csv", "w");
	char name[50];
	printf("Storing records to file");
	Sleep(500);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	Sleep(250);
	int i = 0, c = 0, j = 0;
	while (head != first || j == 0)
	{
		while (head->data.artist[i] != '\0')
		{
			if (head->data.artist[i] == ',')
			{
				c = 1;
			}
			i++;
		}
		if (c == 1)
		{
			fprintf(infile, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", head->data.artist, head->data.album_title, head->data.song_title, head->data.genre,
				head->data.song_length.minutes, head->data.song_length.seconds, head->data.times_played, head->data.rating);
			head = head->pNext;
		}
		else
		{
			fprintf(infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", head->data.artist, head->data.album_title, head->data.song_title, head->data.genre,
				head->data.song_length.minutes, head->data.song_length.seconds, head->data.times_played, head->data.rating);
			head = head->pNext;
		}
		Sleep(250);
		c = 0;
		i = 0;
		j++;
	}
	printf("Files have been stored\n");
	clear_screen();
}

/*
Function: void display_r(Node *head)
Date Created : 12/09/2017
Date Last Modified : 15/09/2017
Description : Displays either all records or all from a specific artist
Input parameters : Node *head
Returns : None
Precondition : Call function
Postconditions : None
*/
void display_r(Node *head)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	Node *first = (Node*)malloc(sizeof(Node));
	temp = first = head;
	int s = 0;
	char name[50], selection_t[50];
	system("cls");
	printf("(1) Print all records\n");
	printf("(2) Print all records that match an artist\n");
	printf("Please select one:");
	gets(selection_t);
	while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > 2)
	{
		printf("Invalid Input, please try again: ");
		gets(selection_t);
	}
	s = atoi(selection_t);
	if (s == 1)
	{
		printf("\n");
		printf("Displaying all Records");
		Sleep(500);
		printf(".");
		Sleep(250);
		printf(".");
		Sleep(250);
		printf(".\n");
		Sleep(250);
		int i = 0, n = 0, c = 0;
		while (temp != first || i == 0)
		{
			i++;
			printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", i, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
				temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
			temp = temp->pNext;
			Sleep(250);
		}
	}
	else
	{
		system("cls");
		printf("Please enter artist name:");
		scanf("%s", &name);
		int i = 0, p = 0;
		while (temp != first || i == 0)
		{
			i++;
			if (strcmp(name, temp->data.artist) == 0)
			{
				printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", i, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
					temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
				p++;
			}
			temp = temp->pNext;
			Sleep(50);
		}
		if (p = 0)
		{
			printf("Sorry for the inconvinience, but no records with such artist exist\n");
		}
	}
	clear_screen();
}

/*
Function: void insert_r(Node **head)
Date Created : 21/09/2017
Date Last Modified : 22/09/2017
Description : gives the user a chance to insert a new record of their
Input parameters : Node **head
Returns : None
Precondition : Call function
Postconditions : None
*/
void insert_r(Node **head)
{
	Record data;
	system("cls");
	char artist[50], album[50], song[50], genre[50], mins[50], sec[50], played[50], rating[50];
	printf("You have chosen the option to create a new record\n");
	printf("Please input information for every field\n");
	printf("Artist: ");
	gets(artist);
	strcpy(data.artist, artist);
	printf("Album: ");
	gets(album);
	strcpy(data.album_title, album);
	printf("Song: ");
	gets(song);
	strcpy(data.song_title, song);
	printf("Genre: ");
	gets(genre);
	strcpy(data.genre, genre);
	printf("\nM:S");
	printf("\n (M) Minutes of song(next is seconds): ");
	gets(mins);
	while (numb_check(mins) == -1)
	{
		printf("Please input a valid Minutes value: ");
		gets(mins);
	}
	printf("(S) Seconds of song left: ");
	gets(sec);
	while (numb_check(sec) == -1 || numb_check(sec) < 0 || numb_check(sec) > 60)
	{
		printf("Please input a valid Seconds value: ");
		gets(sec);
	}
	printf("Times played: ");
	gets(played);
	while (numb_check(played) == -1)
	{
		printf("Please input a valid Times Played: ");
		gets(played);
	}
	printf("Rating (1-5): ");
	gets(rating);
	while (numb_check(rating) == -1 || numb_check(rating) < 1 || numb_check(rating) > 5)
	{
		printf("Please input a valid Rating (1-5): ");
		gets(rating);
	}

	strcpy(data.artist, artist);
	strcpy(data.album_title, album);
	strcpy(data.song_title, song);
	strcpy(data.genre, genre);
	data.song_length.minutes = atoi(mins);
	data.song_length.seconds = atoi(sec);
	data.times_played = atoi(played);
	data.rating = atoi(rating);

	insertFront(head, data);

	clear_screen();
}

/*
Function: void delete_r(Node **head)
Date Created : 21/09/2017
Date Last Modified : 22/09/2017
Description : gives the user a choice to input name of track and if the program finds it, it deletes it
Input parameters : Node **head
Returns : None
Precondition : Call function
Postconditions : None
*/
void delete_r(Node **head)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	Node *first = (Node*)malloc(sizeof(Node));
	temp = first = *head;
	int i = 0, c = 0, p = 0;
	char name[50], choice[50];
	system("cls");
	printf("\n");
	printf("Displaying all Records");
	Sleep(500);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	Sleep(250);
	while (temp != first || i == 0)
	{
		i++;
		printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", i, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
			temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
		temp = temp->pNext;
		Sleep(250);
	}
	temp = first;
	printf("Select which Song you would you like to delete(name):");
	gets(choice);
	printf("\n");
	printf("Looking for song");
	Sleep(500);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	i = 0;
	while (*head != first || i == 0)
	{
		i++;
		if (strcmp(choice, (*head)->data.song_title) == 0)
		{
			if (*head == (*head)->pNext)
			{
				*head = NULL;
			}
			else if (*head == first)
			{
				first->pNext->pPrev = first->pPrev;
				first->pPrev->pNext = first->pNext;
				*head = first->pNext;
				free(first);
			}
			else
			{
				(*head)->pNext->pPrev = (*head)->pPrev;
				(*head)->pPrev->pNext = (*head)->pNext;
				temp = *head;
				*head = first;
				free(temp);
			}
			p++;
		}
		*head = (*head)->pNext;
	}
	if (p == 0)
	{
		printf("Sorry for the inconvinience, but no records with such song name exist\n");
	}
	else
	{
		printf("Record was removed succefully\n");
	}
	clear_screen();
}

/*
Function: void edit_r(Node **head)
Date Created : 12/09/2017
Date Last Modified : 22/09/2017
Description : the edit function is in charge of giving the user a chance to change records values,
				the user finds records by name, selects one and then can edit all its information
Input parameters : Node **head
Returns : None
Precondition : Call function
Postconditions : None
*/
void edit_r(Node **head)
{
	char name[50], selection_t[50];
	Node *temp = (Node*)malloc(sizeof(Node));
	Node *first = (Node*)malloc(sizeof(Node));
	temp = first = *head;
	system("cls");
	printf("Please enter artist name:");
	scanf("%s", &name);
	int i = 0, j = 0, p = 0, choice = 0;
	while (temp != first || i == 0)
	{
		i++;
		if (strcmp(name, temp->data.artist) == 0)
		{
			j++;
			printf("(%d)\tRecord %d: %s, %s, %s, %s, %d:%d, %d, %d\n\n", j, i, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
				temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
			p++;
		}
		temp = temp->pNext;
		Sleep(50);
	}
	if (j == 0)
	{
		printf("Sorry for the inconvinience, but no records with such an artist exist\n");
	}
	else
	{
		printf("Please choose a record to change(number in brackets): ");
		gets(selection_t);
		while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > j)
		{
			printf("Invalid Input, please try again: ");
			gets(selection_t);
		}
		choice = atoi(selection_t);

		p = 0;
		i = 0;
		system("cls");
		while (choice != p)
		{
			i++;
			if (strcmp(name, (*head)->data.artist) == 0)
			{
				p++;
				if (choice == p)
				{
					printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n\n", i, (*head)->data.artist, (*head)->data.album_title, (*head)->data.song_title, (*head)->data.genre,
						(*head)->data.song_length.minutes, (*head)->data.song_length.seconds, (*head)->data.times_played, (*head)->data.rating);
				}
				
			}
			if(choice != p) (*head) = (*head)->pNext;
		}
		clear_screen();
		int done = 0, value = 0;
		char changed[50];
		while (done == 0)
		{
			printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n\n", i, (*head)->data.artist, (*head)->data.album_title, (*head)->data.song_title, (*head)->data.genre,
				(*head)->data.song_length.minutes, (*head)->data.song_length.seconds, (*head)->data.times_played, (*head)->data.rating);
			printf("(1)\tArtist\n");
			printf("(2)\tAlbum title\n");
			printf("(3)\tSong title\n");
			printf("(4)\tGenre\n");
			printf("(5)\tNumber of times played\n");
			printf("(6)\tRating\n\n");
			printf("select record attribute that you would you like to change:");
			choice = 0;
			gets(selection_t);
			while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > 6)
			{
				printf("Invalid Input, please try again: ");
				gets(selection_t);
			}
			choice = atoi(selection_t);
			if (choice == 1)
			{
				printf("OLD Artist name: %s\n", (*head)->data.artist);
				printf("Please eneter new Artist name:");
				gets(changed);
				strcpy((*head)->data.artist, changed);
			}
			else if (choice == 2)
			{
				printf("OLD Album title: %s\n", (*head)->data.album_title);
				printf("Please eneter new Album title:");
				gets(changed);
				strcpy((*head)->data.album_title, changed);
			}
			else if (choice == 3)
			{
				printf("OLD Song title: %s\n", (*head)->data.song_title);
				printf("Please eneter new song title:");
				gets(changed);
				strcpy((*head)->data.song_title, changed);
			}
			else if (choice == 4)
			{
				printf("OLD Genre: %s\n", (*head)->data.genre);
				printf("Please eneter new Genre:");
				gets(changed);
				strcpy((*head)->data.genre, changed);
			}
			else if (choice == 5)
			{
				printf("OLD number of times played: %d\n", (*head)->data.times_played);
				printf("Please eneter new value for times played:");
				gets(selection_t);
				while (numb_check(selection_t) == -1)
				{
					printf("Invalid Input, please try again: ");
					gets(selection_t);
				}
				value = atoi(selection_t);
				(*head)->data.times_played = value;
			}
			else
			{
				printf("OLD number of rating: %d\n", (*head)->data.rating);
				printf("Please eneter a new rating:");
				gets(selection_t);
				while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > 5)
				{
					printf("Invalid Input, must be 1-5, please try again: ");
					gets(selection_t);
				}
				value = atoi(selection_t);
				(*head)->data.rating = value;
			}
			printf("\nWould you like to change anything else?\n(1)\tYES\n(2)\tNO\n");
			gets(selection_t);
			while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > 2)
			{
				printf("Invalid Input, must be 1 or 2, please try again: ");
				gets(selection_t);
			}
			done = atoi(selection_t);
			if (done == 1) done = 0;
			clear_screen();
		}
		*head = first;
	}
}

/*
Function: void sort_r(Node **head)
Date Created : 21/09/2017
Date Last Modified : 22/09/2017
Description : gives the user a choice of parameters by which to sort the list of tracks
Input parameters : Node **head
Returns : None
Precondition : Call function
Postconditions : None
*/
void sort_r(Node **head)
{
	system("cls");
	Node *first = (Node*)malloc(sizeof(Node));
	Node *temp = (Node*)malloc(sizeof(Node));
	first = temp = *head;
	char selection_t[50], str1[50], str2[50];
	int choice = 0, i = 0, j = 1, k = 0, f = 0, r = 0, e = 0, swap = 0;
	while (temp != head || e == 0)
	{
		e++;
		printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", e, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
			temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
		temp = temp->pNext;
		Sleep(50);
	}
	e = 0;
	printf("(1) Sort based on Artist(A-Z)\n");
	printf("(2) Sort based on Album Title(A-Z)\n");
	printf("(3) Sort based on Rating(1-5)(Largest-Smallest)\n");
	printf("(4) Sort based on by times played(Largest-Smallest)\n");
	printf("Please choose a sorting technique(number in brackets): ");
	gets(selection_t);
	while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > 4)
	{
		printf("Invalid Input, please try again: ");
		gets(selection_t);
	}
	choice = atoi(selection_t);

	while (first != *head || i == 0)
	{
		i++;
		first = first->pNext;
	}
	first = *head;
	printf("Swapping records");
	Sleep(500);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	Sleep(250);
	while (j <= i)
	{
		r = i;
		k = 1;
		while (k < r)
		{
			f = 1;
			while (f < k)
			{
				first = first->pNext;
				f++;
			}
			if (choice == 1)
			{
				strcpy(str1, first->pNext->data.artist);
				strcpy(str2, first->data.artist);
				swap = strcmp(strlwr(str1), strlwr(str2));
			}
			else if (choice == 2)
			{
				strcpy(str1, first->pNext->data.album_title);
				strcpy(str2, first->data.album_title);
				swap = strcmp(strlwr(str1), strlwr(str2));
			}
			else if (choice == 3)
			{
				if (first->data.rating < first->pNext->data.rating)
				{
					swap = -1;
				}
				else swap = 0;
			}
			else
			{
				if (first->data.times_played < first->pNext->data.times_played)
				{
					swap = -1;
				}
				else swap = 0;
			}
			temp = first->pNext;
			if (swap < 0)
			{
				first->pPrev->pNext = temp;
				temp->pNext->pPrev = first;
				first->pNext = temp->pNext;
				temp->pPrev = first->pPrev;
				first->pPrev = temp;
				temp->pNext = first;
				if (k == 1)
				{
					*head = temp;
				}
			}
			first = *head;
			swap = 0;
			k++;
		}
		first = *head;
		j++;
		r--;
	}
	printf("Done sorting\n");
	while (temp != head || e == 0)
	{
		e++;
		printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", e, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
			temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
		temp = temp->pNext;
		Sleep(50);
	}
	e = 0;
	clear_screen();
}

/*
Function: void rate_r(Node **head)
Date Created : 12/09/2017
Date Last Modified : 22/09/2017
Description : the function is in charge of giving the user a chance to change the rating 
Input parameters : Node **head
Returns : None
Precondition : Call function
Postconditions : None
*/
void rate_r(Node **head)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	Node *first = (Node*)malloc(sizeof(Node));
	temp = first = *head;
	char selection_t[50];
	int i = 0, j = 0, choice = 0;
	char name[50];
	system("cls");
		printf("\n");
		printf("Displaying all Records");
		Sleep(500);
		printf(".");
		Sleep(250);
		printf(".");
		Sleep(250);
		printf(".\n");
		Sleep(250);
		while (temp != first || i == 0)
		{
			i++;
			printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", i, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
				temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
			temp = temp->pNext;
			Sleep(250);
		}
		printf("select which record would you like to change the rating on:");
		gets(selection_t);
		while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > i)
		{
			printf("Invalid Input, please try again: ");
			gets(selection_t);
		}
		choice = atoi(selection_t);
		while (j != choice)
		{
			j++;
			*head = (*head)->pNext;
		}
		system("cls");
		printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", choice, (*head)->data.artist, (*head)->data.album_title, (*head)->data.song_title, (*head)->data.genre,
			(*head)->data.song_length.minutes, (*head)->data.song_length.seconds, (*head)->data.times_played, (*head)->data.rating);
		choice = 0;
		printf("OLD number of rating: %d\n", (*head)->data.rating);
		printf("Please eneter a new rating:");
		gets(selection_t);
		while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > 5)
		{
			printf("Invalid Input, must be 1-5, please try again: ");
			gets(selection_t);
		}
		choice = atoi(selection_t);
		(*head)->data.rating = choice;
		printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", j, (*head)->data.artist, (*head)->data.album_title, (*head)->data.song_title, (*head)->data.genre,
			(*head)->data.song_length.minutes, (*head)->data.song_length.seconds, (*head)->data.times_played, (*head)->data.rating);
		clear_screen();
		*head = first;
}

/*
Function: void play_r(Node *head)
Date Created : 12/09/2017
Date Last Modified : 22/09/2017
Description : this function asks the user from which record they would like to play, and then plays from there
Input parameters : Node *head
Returns : None
Precondition : Call function
Postconditions : None
*/
void play_r(Node *head)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	Node *first = (Node*)malloc(sizeof(Node));
	temp = first = head;
	int i = 0, j = 0, choice = 0;
	char name[50], selection_t[50];
	system("cls");
	printf("\n");
	printf("Displaying all Records");
	Sleep(500);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	Sleep(250);
	while (temp != head || i == 0)
	{
		i++;
		printf("Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", i, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
			temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
		temp = temp->pNext;
		Sleep(250);
	}
	printf("select record from which you want to play:");
	gets(selection_t);
	while (numb_check(selection_t) == -1 || numb_check(selection_t) < 1 || numb_check(selection_t) > i)
	{
		printf("Invalid Input, please try again: ");
		gets(selection_t);
	}
	choice = atoi(selection_t);
	i = 0;
	system("cls");
	temp = first;
	while (temp != head || i == 0)
	{
		i++;
		if (i < choice)
		{
			printf("Scrolling\n");
			Sleep(500);
		}
		else
		{
		printf("Playing Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", i, temp->data.artist, temp->data.album_title, temp->data.song_title, temp->data.genre,
			temp->data.song_length.minutes, temp->data.song_length.seconds, temp->data.times_played, temp->data.rating);
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".\n");
		Sleep(1000);
		}
		temp = temp->pNext;
	}
	printf("Playlist finished\n");
	clear_screen();
}

/*
Function: void shuffle(Node *head)
Date Created : 22/09/2017
Date Last Modified : 22/09/2017
Description : shuffles the tracks and then plays them in that order
Input parameters : Node *head
Returns : None
Precondition : Call function
Postconditions : None
*/
void shuffle_r(Node *head)
{
	system("cls");
	Node *first = (Node*)malloc(sizeof(Node));
	first = head;
	int i = 0, j = 0, k = 0, c = 0, f = 0, *shuf;
	printf("Shuffling Playlist");
	Sleep(500);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	Sleep(250);

	while (first != head || i == 0)
	{
		i++;
		first = first->pNext;
	}
	shuf = (int*)calloc(i, sizeof(int));
	first = head;
	j = 1;
	while (j <= i)
	{
		c = 1;
		while( c == 1)
		{
			k = random(i);
			for (f = 0; f < k ; f++)
			{
				if (f == (k - 1) && shuf[f] == 0)
				{
					shuf[f] = j;
				//	printf("shuf [%d] = %d\n", f, j);
					c = 0;
				}
			}
		}
		j++;
	}
	j = 0;
	k = 0;
	c = 0;
	f = 1;
	printf("Playing records");
	Sleep(500);
	printf(".");
	Sleep(250);
	printf(".");
	Sleep(250);
	printf(".\n");
	Sleep(250);

	while (j <= i)
	{
		while (f <= shuf[j])
		{
			if (f == shuf[j])
			{
				printf("Playing Record %d: %s, %s, %s, %s, %d:%d, %d, %d\n", shuf[j], head->data.artist, head->data.album_title, head->data.song_title, head->data.genre,
					head->data.song_length.minutes, head->data.song_length.seconds, head->data.times_played, head->data.rating);
				Sleep(1000);
				printf(".");
				Sleep(1000);
				printf(".");
				Sleep(1000);
				printf(".\n");
				Sleep(1000);
			}
			head = head->pNext;
			f++;
		}
		f = 1;
		head = first;
		j++;
	}
	free(shuf);
	clear_screen();
}

/*
Function: Node * makeNode(Record newData)
Date Created : 12/09/2017
Date Last Modified : 15/09/2017
Description : Makes a node with new infrmation in it (data) and passes it back to be used in other functions
Input parameters : Record newData
Returns : Node
Precondition : Call function
Postconditions : None
*/
Node * makeNode(Record newData)
{
	Node * newNode;
	newNode = (Node*)malloc(sizeof(Node));

	if (newNode != NULL)
	{
		strcpy(newNode->data.artist, newData.artist);
		strcpy(newNode->data.album_title, newData.album_title);
		strcpy(newNode->data.song_title, newData.song_title);
		strcpy(newNode->data.genre, newData.genre);
		newNode->data.song_length.minutes = newData.song_length.minutes;
		newNode->data.song_length.seconds = newData.song_length.seconds;
		newNode->data.times_played = newData.times_played;
		newNode->data.rating = newData.rating;

		newNode->pNext = NULL;
		newNode->pPrev = NULL;
	}
	return newNode;
}

/*
Function: int insertFront(Node **head, Record data)
Date Created : 12/09/2017
Date Last Modified : 15/09/2017
Description : this function is in charge of inserting a node at front of the list
Input parameters : Node **head, Record data
Returns : int
Precondition : Call function
Postconditions : None
*/
int insertFront(Node **head, Record data)
{
	Node *newNode = NULL;
	newNode = makeNode(data);
	if (newNode != NULL)
	{
		newNode->pNext = NULL;
		newNode->pPrev = NULL;

		if (*head == NULL)
		{
			(*head) = newNode;
			(*head)->pNext = newNode;
			(*head)->pPrev = newNode;
		}
		else
		{
			newNode->pNext = *head;
			newNode->pPrev = (*head)->pPrev;
			(*head)->pPrev = newNode;
			newNode->pPrev->pNext = newNode;
		}
		*head = newNode;
		return 1;
	}

	return 0;
}

/*
Function: void clear_screen(void)
Date Created : 3 / 27 / 2017
Date Last Modified : 4 / 02 / 2017
Description : This function is in charge of pausing and the when user preses any button , clearing screen
Input parameters : None
Returns : None
Precondition : Call function
Postconditions : None
*/
void clear_screen(void)
{
	system("pause");
	system("cls");
}

/*
Function: int numb_check(char data[50])
Date Created : 22/09/2017
Date Last Modified : 22/09/2017
Description : checks if its a number
Input parameters : char data[50]
Returns : -1 if not int and the actual value if true
Precondition : Call function
Postconditions : None
*/
int numb_check(char data[50])
{
	if (data[0] == 0)
	{
		return 0;
	}
	else if (atoi(data) == 0)
	{
		printf("Invalid Input, supposed to be a number value\n");
		return -1;
	}
	else
	{
		return atoi(data);
	}
}

/*
Function: int random(int n)
Date Created : 22 / 09 / 2017
Date Last Modified : 22 / 09 / 2017
Description : makes random numbers from 1 to n
Input parameters : int n
Returns : int 
Precondition : Call function
Postconditions : None
*/
int random(int n)
{
	return (rand() % n) + 1;
}
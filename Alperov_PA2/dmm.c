/*
Name: Tony Alperov
Date: 9/5/25
Assignment: PA2
Description: The goal of this assignment is to create somewhat compiler that organizes
our digital music and gives us options as to what we want to with it. The options that will be provided
such as load, store, insert and more.
We will be gathering data from .csv files to converting them to strings which will help us satisfy the
requirments.
*/
#include "dmm.h"

void main_menu(void)
{
	printf("              ---------------------------------Welcome to Digital Music Manager---------------------------------\n");
	// Will eventually get user input from to execute command.
}

Node* makeNode(Record newData)
{
	Node* pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->data = newData;
		pMem->next = NULL;
		pMem->prev = NULL;
	}
	return pMem;
}

int insertFront(Node** pHead, Record newData)
{
	Node* pMem = makeNode(newData);
	if (pMem == NULL)
	{
		return 0;
	}

	pMem->next = *pHead;
	pMem->prev = NULL;

	if (pMem != NULL)
	{
		(*pHead)->prev = pMem;
	}
	*pHead = pMem;

	return 1;
}

void printList(Node* pHead)
{
	Node* pointer = pHead;
	if (pointer == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	while (pointer != NULL)
	{
		printf("Artist: %s\n", pointer->data.artist);
		printf("Album: %s\n", pointer->data.album_title);
		printf("Song: %s\n", pointer->data.song_title);
		printf("Genre: %s\n", pointer->data.genre);
		printf("Times Played: %d\n\n", pointer->data.times_played);
		printf("Duration:  %d:%02d\n", pointer->data.song_length.minutes, pointer->data.song_length.seconds);
		printf("Rating: %d\n", pointer->data.rating);

		pointer = pointer->next;

	}
}

int load_music_data(Node** pHead, FILE* infile)
{	
	char record[100];
	while (fgets(record, 100, infile))
	{
		Record temp;
		char* token;

		//ARTIST
		token = strtok(record, ",");
		strcpy(temp.artist, token);

		//ALBUM TITLE
		token = strtok(NULL, ",");
		strcpy(temp.album_title, token);

		//SONG TITLE
		token = strtok(NULL, ",");
		strcpy(temp.song_title, token);
		
		//GENRE
		token = strtok(NULL, ",");
		strcpy(temp.genre, token);

		//DURATION
		token = strtok(NULL, ":");
		temp.song_length.minutes = atoi(token);
		token = strtok(NULL, ",");
		temp.song_length.seconds = atoi(token);

		//TIMES PLAYED
		token = strtok(NULL, ",");
		temp.times_played = atoi(token);

		//RATING
		token = strtok(NULL, ",");
		temp.rating = atoi(token);

		Node* pMem = makeNode(temp);
		if (pMem != NULL)
		{
			insertFront(pHead, temp); 
		}

	}
	return 1;
}

int store_music_data(Node* pHead)
{
	FILE* outfile = fopen("musicPlayList.csv", "w");
	if (outfile == NULL)
	{
		return 0;
	}

	Node* pCur = pHead;
	while (pCur != NULL)
	{
		fprintf(outfile, "\"%s\",%s,%s,%s,%d:%02d,%d,%d\n",
			pCur->data.artist, pCur->data.album_title,
			pCur->data.song_title, pCur->data.genre,
			pCur->data.song_length.minutes, pCur->data.song_length.seconds,
			pCur->data.times_played, pCur->data.rating);

		pCur = pCur->next;
	}
	fclose(outfile);
	return 1;
}

void display_command(Node* pHead)
{	
	Node*  pCur = pHead;
	if (pCur == NULL)
	{
		puts("List is empty.");
		return;
	}
		printList(pHead);
}

Node* search_by_artist(Node* pHead, char* artist)
{
	Node* pCur = pHead;
	
	while (pCur != NULL)
	{
		if (strcmp(pCur->data.artist, artist) == 0)
		{
			return pCur;
		}
		pCur = pCur->next;
	}
	return NULL;
}

void edit_command(Node* pHead)
{
	char name[60];
	printf("Enter Artist to edit: \n");
	fgets(name, 60, stdin);
	name[strcspn(name, '\0')] = 0;

	Node* edit_record = search_by_artist(pHead, name);
	if (edit_record != NULL)
	{

	}
	else
	{
		printf("No records found for this artist name %s.\n", name);
	}
}



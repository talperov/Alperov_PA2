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

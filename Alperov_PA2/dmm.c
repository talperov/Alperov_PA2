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

// main menu of the DMM
void main_menu(void)
{
	printf("              ---------------------------------Welcome to Digital Music Manager---------------------------------\n");
	// Will eventually get user input from to execute command.
}

// Node that gathers new data to our DMM
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

// inserts a new Node that adds on to the New Data provided for DMM
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

// A printed list of the records of the songs.
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

// Will load up music data from the.csv file
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

// Will store up music data gathered from the.csv file
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

// Displays records with printList and searches specific records
void display_command(Node* pHead)
{
	if (pHead == NULL)
	{
		puts("List is empty.");
		return;
	}
	printList(pHead);
}

// Searches by artist so itll display in display_command
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

// Edit command for diplay to change visuals
void edit_command(Node* pHead)
{
	char name[60];
	printf("Enter Artist to edit: \n");
	fgets(name, 60, stdin);
	name[strcspn(name, '\n')] = 0;

	Node* edit_record = search_by_artist(pHead, name);

	if (edit_record != NULL)
	{
		printf("Enter new artist name: \n");
		fgets(edit_record->data.artist, 60, stdin);
		edit_record->data.artist[strcspn(edit_record->data.artist, "\n")]= 0;

		printf("Enter new album name: \n");
		fgets(edit_record->data.album_title, 60, stdin);
		edit_record->data.album_title[strcspn(edit_record->data.album_title, "\n")] = 0;

		printf("Enter new song name: \n");
		fgets(edit_record->data.song_title, 60, stdin);
		edit_record->data.song_title[strcspn(edit_record->data.song_title, "\n")] = 0;

		printf("Enter new genre name: \n");
		fgets(edit_record->data.genre, 60, stdin);
		edit_record->data.genre[strcspn(edit_record->data.genre, "\n")] = 0;

		printf("Enter duration of song in minutes first then second: \n");
		scanf("%d %d", &edit_record->data.song_length.minutes, &edit_record->data.song_length.seconds);

		printf("How much times was it played: \n");
		scanf("%d", &edit_record->data.times_played);

		printf("On a scale of (1-5) what is your rating: \n");
		scanf("%d", &edit_record->data.rating);

		getchar();
		
		printf("Record has been changed!\n");


	}
	else
	{
		printf("No records found for this artist name %s.\n", name);
	}
}




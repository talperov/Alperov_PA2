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
#ifndef DMM_H
#define DMM_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct duration // struct for Duration of music
{
	int minutes;
	int seconds;
}Duration;


typedef struct record // struct for music playlist and everything needed to know about music
{
	char artist[60];
	char album_title[60];
	char song_title[60];
	char genre[60];
	int times_played;
	int rating;
	Duration song_length;


}Record;


typedef struct node Node; // Node to move foward or previous on songs data

typedef struct node
{
	Record data;
	Node* next;
	Node* prev;
}Node;

void main_menu(void); // main menu of the DMM

Node* makeNode(Record newData); // Node that gathers new data to our DMM

int insertFront(Node** pHead, Record newData); // inserts a new Node that adds on to the New Data provided for DMM

void printList(Node* pHead); // A printed list of the records of the songs.

int load_music_data(Node **pHead, FILE *infile); // Will load up music data from the .csv file

int store_music_data(Node* pHead); // Will store up music data gathered from the .csv file

void display_command(Node* pHead); // Displays records with printList and searches specific records

Node* search_by_artist(Node* pHead, char* artist); // Searches by artist so itll display in display_command

void edit_command(Node* pHead); // Edit command for diplay to change visuals


#endif

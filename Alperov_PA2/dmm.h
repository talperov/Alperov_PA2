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

typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record
{
	/*Artist – a string
		Album title – a string
		Song title – a string
		Genre – a string
		Song length - a struct Duration type consisting of seconds and minutes, both
		integers
		Number times played – an integer
		Rating – an integer(1 – 5)*/
}Record;
#endif

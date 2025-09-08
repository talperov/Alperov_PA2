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

int main(void)
	
{
    FILE* infile = fopen("musicPlayList.csv", "r");
    if (infile != NULL)
    {
        puts("Infile opened successfully");
    }

	Node* pHead = NULL; // This starts it empty

    Record r1 = { "Swift, Taylor", "1989", "Shake it Off", "Pop", 12, 3, {3, 35} };
    

    // Insert them into the list
    insertFront(&pHead, r1);
   

    // Print list to confirm it works
    printList(pHead);


	return 0;
}

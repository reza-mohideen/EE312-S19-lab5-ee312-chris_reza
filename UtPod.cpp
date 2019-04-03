/* UtPod.cpp

Christopher Mathew - ctm2382
Reza Mohideen - rm54783
EE 312 4/2/19

*/
#include <cstdlib>
#include <iostream>
#include <time.h>
#include "UtPod.h"
#include "Song.h"


using namespace std;
//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod()
{
    podMemSize = MAX_MEMORY;
    songs = NULL;
    tail = NULL;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size)
{
    if (size > 512 || size < 0) {
        podMemSize = MAX_MEMORY;
    }
    else {
        podMemSize = size;
    }
    songs = NULL;
    tail = NULL;
}

    /* FUNCTION - int addSong
    * attempts to add a new song to the UtPod
       o returns a 0 if successful
       o returns -1 if not enough memory to add the song

    precondition: s is a valid Song

    input parms - object of type Song that caller wants to add

    output parms - Returns 0 if successful in adding the song, returns -1 if unsuccessful to add song
    */
int UtPod::addSong(Song const &s)
{
    if (getRemainingMemory() >= s.getSize())
    {
        SongNode *tmp = new SongNode;
        tmp->s = s;
        tmp->next = NULL;
        
        if (songs == NULL)
        {
            songs = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        
        return SUCCESS;
    }
    else
    {
        return NO_MEMORY;
    }
    
}

/* FUNCTION - int removeSong
    * attempts to remove a song from the UtPod
    * removes the first instance of a song that is in the the UtPod multiple times
       o returns 0 if successful
       o returns -1 if nothing is removed


     input parms - object of type of song that caller wishes to remove

     output parms - 0 if successful, -1 if unsuccessful
*/
int UtPod::removeSong(Song const &s)
{
    SongNode* current = songs;
    SongNode* previous;
    while(current != NULL)
    {
        // found song
        if (current->s == s)
        {
            // the song is the first node
            if (current == songs)
            {
                // song is the only node in linkedlist
                if (current == tail) {
                    tail = NULL;
                }
                songs = current->next;
                free(current);
                return SUCCESS;
            }
            // last song
            if (current == tail)
            {
                tail = previous;
                previous->next = NULL;
                free(current);
                return SUCCESS;
            }
            // middle songs
            previous->next = current->next;
            free(current);
            return SUCCESS;
        }
        previous = current;
        current = current->next;
        
    }
    return -1;
}

    /* FUNCTION - void shuffle
    *  shuffles the songs into random order
      o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - none, shuffles the linked list
    */
void UtPod::shuffle()
{
    SongNode* node1;
    SongNode* node2;
    SongNode* current = songs;
    int total = 0, randNum1, randNum2, cntr;
    
    // count total number of songs
    while (current != NULL) {
        total += 1;
        current = current->next;
    }
    if (total <= 1){
        return;
    }

    // initialize random seed
    srand(time(0));
    
    for (int i = 0; i < 100*total; i++)
    {
        node1 = songs;
        node2 = songs;
        randNum1 = rand() % total;
        randNum2 = rand() % total;
        // find node
        for (int j = 0; j < randNum1; j++)
        {
            node1 = node1->next;
        }
        for (int k = 0; k < randNum2; k++)
        {
            node2 = node2->next;
        }
        // swap
        Song temp = node1->s;
        node1->s = node2->s;
        node2->s = temp;
    }
    return;
}

    /* FUNCTION - void showSongList
    * prints the current list of songs in order from first to last to standard output
    * format - Title, Artist, size in MB (one song per line)

     input parms - none

     output parms - prints list of songs from head to tail
    */
void UtPod::showSongList()
{
    SongNode* current = songs;
    Song currentSong;
    while (current != NULL) {
        currentSong = current->s;
        cout << currentSong.getArtist() << ", " << currentSong.getTitle() << ", " << currentSong.getSize() << endl;
        current = current->next;
    }
    return;
}

    /* FUNCTION - void sortSongList
    *  sorts the songs in ascending order
      o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - sorts the songs from least to greatest
    */
void UtPod::sortSongList()
{
    if (songs == tail || songs == NULL)
    {
        return;
    }

    SongNode* ptr1 = songs;
    SongNode* ptr2 = ptr1->next;
    
    while(ptr1 != tail) {
        while (ptr2 != NULL) {
            if (ptr2->s < ptr1->s)
            {
                Song temp = ptr1->s;
                ptr1->s = ptr2->s;
                ptr2->s = temp;
                
            }
            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    }
    return;
}

    /* FUNCTION - void clearMemory
    * clears all the songs from memory

     input parms - none

     output parms - frees the dynamically allocated memory of the entire linked list
    */
void UtPod::clearMemory()
{
    SongNode* current = songs;
    SongNode* temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
    songs = NULL;
    tail = NULL;
    return;
}

    /* FUNCTION - int getTotalMemory
    *  returns the total amount of memory in the UtPod
      o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - returns the total memory of the UtPod
    */
int UtPod::getTotalMemory()
{
    return podMemSize;
}

    /* FUNCTION - int getRemainingMemory
    *  returns the amount of memory available for adding new songs

     input parms - none

     output parms - returns the memory that is not used up by the songs in the list
    */
int UtPod::getRemainingMemory()
{
    SongNode* current = songs;
    Song currentSong;
    int memoryUsed = 0;
    while (current != NULL) {
        currentSong = current->s;
        memoryUsed += currentSong.getSize();
        current = current->next;
    }
    return podMemSize - memoryUsed;
}

//Deconstructor for the UtPod class
UtPod::~UtPod()
{
    SongNode* current = songs;
    SongNode* savePtr;
    while(current != NULL) {
        savePtr = current->next;
        free(current);
        current = savePtr;
    }
}
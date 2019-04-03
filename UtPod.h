/* UtPod.h

Christopher Mathew - ctm2382
Reza Mohideen - rm54783
EE 312 4/2/19

*/

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
     Song s; //song in node
     SongNode *next; //points to the next node
    };

    SongNode *songs, *tail;  //the head and tail pointer

    int podMemSize;  //the total amount of memory available on the UtPod

public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod(int size);

    /* FUNCTION - int addSong
    * attempts to add a new song to the UtPod
       o returns a 0 if successful
       o returns -1 if not enough memory to add the song

    precondition: s is a valid Song

    input parms - object of type Song that caller wants to add

    output parms - Returns 0 if successful in adding the song, returns -1 if unsuccessful to add song
    */

    int addSong(Song const &s);


    /* FUNCTION - int removeSong
    * attempts to remove a song from the UtPod
    * removes the first instance of a song that is in the the UtPod multiple times
       o returns 0 if successful
       o returns -1 if nothing is removed


     input parms - object of type of song that caller wishes to remove

     output parms - 0 if successful, -1 if unsuccessful
    */

    int removeSong(Song const &s);


    /* FUNCTION - void shuffle
    *  shuffles the songs into random order
      o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - none, shuffles the linked list
    */

    void shuffle();


    /* FUNCTION - void showSongList
    * prints the current list of songs in order from first to last to standard output
    * format - Title, Artist, size in MB (one song per line)

     input parms - none

     output parms - prints list of songs from head to tail
    */

    void showSongList();


    /* FUNCTION - void sortSongList
    *  sorts the songs in ascending order
      o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - sorts the songs from least to greatest
    */

    void sortSongList();


    /* FUNCTION - void clearMemory
    * clears all the songs from memory

     input parms - none

     output parms - frees the dynamically allocated memory of the entire linked list
    */
    void clearMemory();


    /* FUNCTION - int getTotalMemory
    *  returns the total amount of memory in the UtPod
      o will do nothing if there are less than two songs in the current list

     input parms - none

     output parms - returns the total memory of the UtPod
    */
    int getTotalMemory();



    /* FUNCTION - int getRemainingMemory
    *  returns the amount of memory available for adding new songs

     input parms - none

     output parms - returns the memory that is not used up by the songs in the list
    */
    int getRemainingMemory();

    //Deconstructor for the UtPod class
    ~UtPod();

};



#endif

#include <cstdlib>
#include <iostream>
#include <time.h>
#include "UtPod.h"
#include "Song.h"


using namespace std;
UtPod::UtPod()
{
    podMemSize = MAX_MEMORY;
    songs = NULL;
    tail = NULL;
}

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
    
    // initialize random seed
    srand(time(0));
    
    for (int i = 0; i < 100; i++)
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

void UtPod::showSongList()
{
    SongNode* current = songs;
    Song currentSong;
    while (current != NULL) {
        currentSong = current->s;
        cout << currentSong.getTitle() << ", " << currentSong.getArtist() << ", " << currentSong.getSize() << endl;
        current = current->next;
    }
    return;
}

void UtPod::sortSongList()
{
    SongNode* ptr1 = songs;
    SongNode* ptr2 = ptr1->next;
    if (songs == tail || songs == NULL)
    {
        return;
    }
    while(ptr1->next != tail) {
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

int UtPod::getTotalMemory()
{
    return podMemSize;
}
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

UtPod::~UtPod()
{
    
}

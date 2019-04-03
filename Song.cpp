/* Song.cpp

Christopher Mathew - ctm2382
Reza Mohideen - rm54783
EE 312 4/2/19

*/

#include <cstdlib>
#include <iostream>
#include "Song.h"

using namespace std;
/* Constructor - Song class

     input parms - none

     output parms - none
    */
Song::Song()
{
    artist = "";
    title = "";
    size = DEFAULT_SIZE;
}

/* Constructor - Song class

     input parms - artist

     output parms - none
    */
Song::Song(string _artist)
{
    artist = _artist;
    title = "";
    size = DEFAULT_SIZE;
}

/* Constructor - Song class

     input parms - artist, title

     output parms - none
    */
Song::Song(string _artist, string _title)
{
    artist = _artist;
    title = _title;
    size = DEFAULT_SIZE;
}

/* Constructor - Song class

     input parms - artist, title, size

     output parms - none
    */
Song::Song(string _artist, string _title, int _size)
{
    artist = _artist;
    title = _title;
    size = _size;
}

 /* FUNCTION - string getArtists
        attempts to return the artist of the song


     input parms - none

     output parms - string of artist
    */
string Song::getArtist() const
{
    return artist;
}

 /* FUNCTION - void setArtists
        changes artist to new artist


     input parms - string artistName

     output parms - none
    */
void Song::setArtist(string artistName)
{
    artist = artistName;
}

 /* FUNCTION - int getSize
        gets size of song


     input parms - none

     output parms - int size
    */
int Song::getSize() const
{
    return size;
}

 /* FUNCTION - void setSize
        sets size of song


     input parms - int size

     output parms - none
    */
void Song::setSize(int _size)
{
    size = _size;
}

 /* Operator Overide - ==
        overides == operator when comparing two songs
    */
bool Song::operator ==(Song const &rhs)
{
    if (artist == rhs.artist)
    {
        if (title == rhs.title)
        {
            if (size == rhs.size)
            {
                return true;
            }
        }
    }
    return false;
}

 /* Operator Overide - >
        overides > operator when comparing two songs
    */
bool Song::operator >(Song const &rhs)
{
    if (artist != rhs.artist)
    {
        return (artist > rhs.artist);
    }
    else if (title != rhs.title)
    {
        return (title > rhs.title);
    }
    else if (size != rhs.size)
    {
        return (size > rhs.size);
    }
    else
    {
        return false;
    }
}

/* Operator Overide - <
        overides < operator when comparing two songs
    */
bool Song::operator <(Song const &rhs)
{
    if (artist != rhs.artist)
    {
        return (artist < rhs.artist);
    }
    else if (title != rhs.title)
    {
        return (title < rhs.title);
    }
    else if (size != rhs.size)
    {
        return (size < rhs.size);
    }
    else
    {
        return false;
    }
}



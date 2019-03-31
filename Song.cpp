#include <cstdlib>
#include <iostream>
#include "Song.h"

using namespace std;

Song::Song()
{
    title = "";
    artist = "";
    size = DEFAULT_SIZE;
}
Song::Song(string _title)
{
    title = _title;
    artist = "";
    size = DEFAULT_SIZE;
}

Song::Song(string _title, string _artist)
{
    title = _title;
    artist = _artist;
    size = DEFAULT_SIZE;
}

Song::Song(string _title, string _artist, int _size)
{
    title = _title;
    artist = _artist;
    size = _size;
}

string Song::getArtist() const
{
    return artist;
}

void Song::setArtist(string artistName)
{
    artist = artistName;
}

int Song::getSize() const
{
    return size;
}

void Song::setSize(int _size)
{
    size = _size;
}

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



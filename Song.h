/* Song.h

Christopher Mathew - ctm2382
Reza Mohideen - rm54783
EE 312 4/2/19

*/

#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {
    
    private:
        string title;
        string artist;
        int size;

        static const int DEFAULT_SIZE = 0;

    public:
        Song();
        Song(string artist);
        Song(string artist, string title);
        Song(string artist, string title, int size);

        string getTitle() const
        { return title; }

        void setTitle(string n)
        { title = n;}

        string getArtist() const;
        void setArtist(string artistName);
        int getSize() const;
        void setSize(int s);

        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        bool operator ==(Song const &rhs);


    };


#endif

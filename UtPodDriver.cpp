/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;


int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Beatles", "Hey Jude", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
    
    Song s2("Beatles", "Hey Jude", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
    
    Song s3("Beatles", "Hey Jude", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
    
    Song s4("Beatles", "Hey Jude", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
    
    Song s5("Beatles", "Hey Jude", 242);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    
    t.showSongList();
    
    t.shuffle();
    
    t.showSongList();
    /*
    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;
    t.clearMemory();
    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;

    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    //t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    //t.showSongList();
    //cout << "memory = " << t.getRemainingMemory() << endl;
    */
    return 0;
}

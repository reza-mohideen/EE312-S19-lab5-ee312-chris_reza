/* UtPodDriver.cpp
Driver for the UtPod.

Christopher Mathew - ctm2382
Reza Mohideen - rm54783
EE 312 4/2/19

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;


int main(int argc, char *argv[])
{   
    //Testing UtPod constructor with size parameter included
    UtPod c = 300;
    
    //Testing getTotalMemory function with UtPod of size 300
    int total =  c.getTotalMemory();
    cout << "utPod c total memory = " << total << endl;

    //Testing UtPod constructor with size parameter not included
    UtPod t;
    
    //Testing getTotalMemory function with UtPod of default size
    total =  t.getTotalMemory();
    cout << "UtPod t total memory = " << total << endl;

    //Testing these functions when zero songs are in the list
    t.showSongList();
    t.sortSongList();
    t.shuffle();

    //Testing the addSong function with an empty list
    Song s1("Beatles", "Hey Jude", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;
    
    //Testing the showSongList function with one song
    t.showSongList();

    //Tesing the getRemainingMemory function after one song
    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;
    
    //Testing the addSong function with one song already in the list
    Song s2("Ceatles", "Hey Jude", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;
    
    //Testing the showSongList function with two songs
    t.showSongList();

    //Testing the getRemainingMemory function after two songs
    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;
    
    //Testing the addSong function with multiple songs, similiar songs
    Song s3("Aeatles", "Hey Jude", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;
    
    Song s4("Xeatles", "Hey Jude", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;
    
    //Testing the addSong function and exceding max memory
    Song s5("Meatles", "Hey Jude", 500);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    Song s6("Aeatles", "Hey Jude1", 10);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("Aeatles", "Hey Jude", 1);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;
    
    Song s8("Meatles", "Hey Jude", 242);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    //Testing the song class by inputing only one parameter
    Song s9("Weatles");
    result = t.addSong(s9);
    cout << "add result = " << result << endl;

    //Testing the song class by inputing only two parameters
    Song s10("Weatles", "Hey Jude");
    result = t.addSong(s10);
    cout << "add result = " << result << endl;
    
    //Testing the showSongList function with multiple songs
    t.showSongList();

    //Testing the getRemainingMemory function with multiple songs
    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;
    
    //Testing the sortSongList function with multiple songs
    t.sortSongList();
    t.showSongList();

    //Testing the getRemainingMemory function after a sort
    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;
    
    //Testing the shuffle function with multiple songs 
    t.shuffle();
    t.showSongList();

    //Testing the getRemainingMemory functon after a shuffle
    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;
    
    //Testing the removeSong function
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    //Showing list of songs after removing a song
    t.showSongList();

    //Testing the clearMemory function
    t.clearMemory();   


    //Testing the getRemainingMemory function 
    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;

    //Testing the clearMemory function after already calling it once
    t.clearMemory();
    t.showSongList();

    result = t.getRemainingMemory();
    cout << "remaining memory = " << result << endl;
    
    
    //Testing the removeSong function with no songs
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;


    //Testing the removeSong function by trying to remove a song not in the list
    Song s20("Beatles", "Yellow Submarine", 20);
    result = t.removeSong(s20);
    cout << "delete result = " << result << endl;
      
    t.showSongList();
    

    result = t.addSong(s8);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    cout << "memory = " << t.getRemainingMemory() << endl;

    return 0;
}

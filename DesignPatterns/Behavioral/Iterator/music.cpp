#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Playlist
{
private:
    vector<string> songs;

public:
    void addSong(string song)
    {
        songs.push_back(song);
    }

    string getSong(int index)
    {
        return songs[index];
    }
    int size()
    {
        return songs.size();
    }
};

class PlaylistIterator
{
private:
    Playlist &playlist;
    int index;

public:
    PlaylistIterator(Playlist &playlist)
        : playlist(playlist), index(0)
    {
    }
    bool hasNext()
    {
        return index < playlist.size();
    }
    string next()
    {
        return playlist.getSong(index++);
    }
};

int main()
{
    // 1. Create Playlist
    Playlist playlist;

    // 2. Add songs
    playlist.addSong("Shape of You");
    playlist.addSong("Believer");
    playlist.addSong("Perfect");
    playlist.addSong("Faded");

    // 3. Create Iterator
    PlaylistIterator iterator(playlist);

    // 4. Traverse the Playlist
    while (iterator.hasNext())
    {
        cout << iterator.next() << endl;
    }

    return 0;
}
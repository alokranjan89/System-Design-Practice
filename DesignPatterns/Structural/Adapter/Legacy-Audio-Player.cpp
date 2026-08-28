#include <iostream>
using namespace std;

class Player
{
public:
    virtual void play() = 0;

    virtual ~Player() {}
};

class LegacyAudioPlayer
{
public:
    void playAudio()
    {
        cout << "Playing audio..." << endl;
    }
};

class PlayerAdapter : public Player
{
private:
    LegacyAudioPlayer& legacyAudioPlayer;

public:
    PlayerAdapter(LegacyAudioPlayer& legacyAudioPlayer)
        : legacyAudioPlayer(legacyAudioPlayer)
    {
    }

    void play() override
    {
        legacyAudioPlayer.playAudio();
    }
};

void playMusic(Player* player)
{
    player->play();
}

int main()
{
    LegacyAudioPlayer legacyPlayer;

    PlayerAdapter adapter(legacyPlayer);

    playMusic(&adapter);

    return 0;
}
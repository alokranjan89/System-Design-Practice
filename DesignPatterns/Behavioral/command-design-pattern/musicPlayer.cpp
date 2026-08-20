#include <iostream>
using namespace std;

class MusicPlayer
{
public:
    void play()
    {
        cout << "Music is Playing \n";
    }
    void pause()
    {
        cout << "Music is Pause \n";
    }

    void stop()
    {
        cout << "Music is stop \n";
    }
};

class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() {};
};

class PlayCommand : public Command
{
private:
    MusicPlayer &musicplayer;

public:
    PlayCommand(MusicPlayer &musicplayer)
        : musicplayer(musicplayer)
    {
    }

    void execute() override
    {
        musicplayer.play();
    }
};

class PauseCommand : public Command
{
private:
    MusicPlayer &musicplayer;

public:
    PauseCommand(MusicPlayer &musicplayer)
        : musicplayer(musicplayer)
    {
    }

    void execute() override
    {
        musicplayer.pause();
    }
};

class StopCommand : public Command
{
private:
    MusicPlayer &musicplayer;

public:
    StopCommand(MusicPlayer &musicplayer)
        : musicplayer(musicplayer)
    {
    }

    void execute() override
    {
        musicplayer.stop();
    }
};

class MusicRemote
{
private:
    Command *command;

public:
    MusicRemote(Command *command)
        : command(command)
    {
    }

    void setCommand(Command *command)
    {
        this->command = command;
    }

    void pressButton()
    {
        command->execute();
    }
};

int main()
{
    // 1. Create Receiver
    MusicPlayer player;

    // 2. Create Concrete Commands
    PlayCommand play(player);
    PauseCommand pause(player);
    StopCommand stop(player);

    
    MusicRemote remote(&play);

    
    remote.pressButton();

   
    remote.setCommand(&pause);
    remote.pressButton();

    
    remote.setCommand(&stop);
    remote.pressButton();

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media
{
protected:
    string title;
    string fileName;

public:
    Media(string t, string file)
    {
        title = t;
        fileName = file;
    }

    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;

    virtual void showDetails() const
    {
        cout << "Title: " << title << endl;
        cout << "File: " << fileName << endl;
    }

    virtual ~Media() {}
};

class Audio : public Media
{
public:
    Audio(string t, string file)
        : Media(t, file) {}

    void play() override
    {
        cout << "Playing audio: " << title << endl;
    }

    void pause() override
    {
        cout << "Audio paused: " << title << endl;
    }

    void stop() override
    {
        cout << "Audio stopped: " << title << endl;
    }

    void showDetails() const override
    {
        cout << "\n--- Audio ---" << endl;
        Media::showDetails();
    }
};

class Video : public Media
{
public:
    Video(string t, string file)
        : Media(t, file) {}

    void play() override
    {
        cout << "Playing video: " << title << endl;
    }

    void pause() override
    {
        cout << "Video paused: " << title << endl;
    }

    void stop() override
    {
        cout << "Video stopped: " << title << endl;
    }

    void showDetails() const override
    {
        cout << "\n--- Video ---" << endl;
        Media::showDetails();
    }
};

class Image : public Media
{
public:
    Image(string t, string file)
        : Media(t, file) {}

    void play() override
    {
        cout << "Displaying image: " << title << endl;
    }

    void pause() override
    {
        cout << "Image display paused: " << title << endl;
    }

    void stop() override
    {
        cout << "Image display stopped: " << title << endl;
    }

    void showDetails() const override
    {
        cout << "\n--- Image ---" << endl;
        Media::showDetails();
    }
};

int main()
{
    vector<Media*> mediaList;

    mediaList.push_back(new Audio("My Song", "song.mp3"));
    mediaList.push_back(new Video("My Video", "video.mp4"));
    mediaList.push_back(new Image("My Photo", "photo.jpg"));

    cout << "===== MEDIA PLAYER =====" << endl;

    for (Media* media : mediaList)
    {
        media->showDetails();
        media->play();
        media->pause();
        media->stop();
    }

    for (Media* media : mediaList)
    {
        delete media;
    }

    return 0;
}
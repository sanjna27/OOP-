#include <iostream>
#include <string>
using namespace std;

class MediaFile {
protected:
    string filePath;
    int size;  
public:
    MediaFile(string path, int s) : filePath(path), size(s) {}

    virtual void play() {  
        cout << "Playing media file: " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping media file: " << filePath << endl;
    }

    virtual ~MediaFile() {}  
};

class VisualMedia : virtual public MediaFile {  
protected:
    string resolution;
public:
    VisualMedia(string path, int s, string res) 
        : MediaFile(path, s), resolution(res) {}

    virtual void play() override {  
        cout << "Displaying visual content from " << filePath << " at resolution " << resolution << endl;
    }
};

class AudioMedia : virtual public MediaFile {  
protected:
    int sampleRate;
public:
    AudioMedia(string path, int s, int rate) 
        : MediaFile(path, s), sampleRate(rate) {}

    virtual void play() override {  
        cout << "Playing audio at " << sampleRate << " Hz" << endl;
    }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, int s, string res, int rate)
        : MediaFile(path, s), VisualMedia(path, s, res), AudioMedia(path, s, rate) {}

    void play() override {  
        cout << "Playing video with both audio and visual content..." << endl;
        VisualMedia::play();
        AudioMedia::play();
    }

    void stop() override {
        cout << "Stopping video playback: " << filePath << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, int s, string res)
        : MediaFile(path, s), VisualMedia(path, s, res) {}

    void play() override {
        cout << "Displaying image: " << filePath << " at resolution " << resolution << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, int s, int rate)
        : MediaFile(path, s), AudioMedia(path, s, rate) {}

    void play() override {
        cout << "Playing audio file: " << filePath << " at " << sampleRate << " Hz" << endl;
    }
};

int main() {
    MediaFile* media1 = new VideoFile("movie.mp4", 5000, "1920x1080", 44100);
    MediaFile* media2 = new ImageFile("picture.jpg", 1200, "1080x720");
    MediaFile* media3 = new AudioFile("song.mp3", 8000, 44100);

    media1->play();
    media1->stop();

    media2->play();
    media2->stop();

    media3->play();
    media3->stop();

    delete media1;
    delete media2;
    delete media3;

    return 0;
}

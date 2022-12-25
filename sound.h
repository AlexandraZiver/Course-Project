#ifndef SOUND_H
#define SOUND_H
#include <QMediaPlayer>
#include <QAudioOutput>

class sound
{
public:
    sound();

    void clickSound (bool isMusicPlaying) {

        sEff->setAudioOutput(sOutput);
        sEff->setSource(QUrl::fromLocalFile("qrc:/menu.mp3"));

        if (isMusicPlaying) {
            sOutput->setVolume(0.15);
            sEff->play();
        }

        else if (!isMusicPlaying) {
            sOutput->setVolume(0);
            sEff->stop();
        }

    }

    void jumpSound (bool isMusicPlaying) {

        sEff->setAudioOutput(sOutput);
        sEff->setSource(QUrl::fromLocalFile("qrc:/jump.wav"));

        if (isMusicPlaying) {
            sOutput->setVolume(0.15);
            sEff->play();
        }

        else if (!isMusicPlaying) {
            sOutput->setVolume(0);
            sEff->stop();
        }
    }

    void bonusSound (bool isMusicPlaying) {

        sEff->setAudioOutput(sOutput);
        sEff->setSource(QUrl::fromLocalFile("qrc:/bonusSound.wav"));

        if (isMusicPlaying) {
            sOutput->setVolume(0.1);
            sEff->play();
        }

        else if (!isMusicPlaying) {
            sOutput->setVolume(0);
            sEff->stop();
        }
    }



        QMediaPlayer *sEff = new QMediaPlayer;
        QAudioOutput *sOutput = new QAudioOutput;

        QMediaPlayer *music = new QMediaPlayer;
        QAudioOutput *musicOutput = new QAudioOutput;

        bool isMusicPlaying;
};

#endif // SOUND_H

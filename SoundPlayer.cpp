#include "SoundPlayer.h"

SoundPlayer::SoundPlayer(const std::string& filename)
{
    // Get the current directory
    wchar_t currentDir[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, currentDir);

    // Build the full file path
    std::wstring wideFilepath(filename.begin(), filename.end());
    filepath = currentDir;
    filepath += L"\\Sound\\";
    filepath += wideFilepath;
}

SoundPlayer::~SoundPlayer()
{

}

void SoundPlayer::Play()
{
    // Play the sound
    PlaySound(filepath.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}
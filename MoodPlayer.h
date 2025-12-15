/**
 * Program: Mood-based Music Recommender
 * Date: December 2025
 * File: MoodPlayer20615981.h
 * Description: Header file defining the MoodPlayer class structure.
 * Demonstrates encapsulation by protecting member variables.
 */

#ifndef MOODPLAYER20615981_H
#define MOODPLAYER20615981_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MoodPlayer {
private:
    // -- Encapsulated Data --
    string currentMood;
    vector<string> playlist;
    vector<string> moodHistory;
    int currentTrackIndex;

    // -- Private Helper Methods --
    void loadPlaylist();
    bool isValidMood(const string& inputMood);
    string toLowerCase(const string& str);

    // Specific loaders (Modular approach)
    void loadHappyTracks();
    void loadSadTracks();
    void loadEnergeticTracks();
    void loadRelaxedTracks();

    void printPlaylistPreview(); // Helper to show the "1, 2, 3... and more" preview

public:
    // -- Public Interface --
    MoodPlayer();

    // Core functionality
    void setMood(const string& userMood);
    string getRecommendation();
    void playTrack();
    void nextTrack();
    void showMoodHistory();
};

#endif // MOODPLAYER20615981_H

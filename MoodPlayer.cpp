/**
 * Program: Mood-based Music Recommender
 * Description: Implementation of the MoodPlayer class methods.
 * Handles playlist management, mood validation, and track playback.
 */

#include "MoodPlayer20615981.h"


// ----------------------------Constructor-----------------------------

MoodPlayer::MoodPlayer() {
    currentMood = "None";
    currentTrackIndex = 0;
}



// ------------------------Private Helper Methods---------------------------

/**
 * Helper function to convert a string to lowercase.
 * This ensures case-insensitive comparisons (e.g., "Happy" == "happy").
 * @param str: The input string to convert.
 * @return: A new string with all characters converted to lowercase.
 */
string MoodPlayer::toLowerCase(const string& str) {
    string lowerStr = str;

    // ---------------------------------------------------------
    // OPTION A: C++98 Standard (Index-Based Loop)
    // ---------------------------------------------------------
    // Explicitly iterates using an index.
    // We use size_t to match .length() return type (safe for 64-bit systems).
    for (size_t i = 0; i < lowerStr.length(); ++i) {
        lowerStr[i] = tolower(lowerStr[i]);
    }

    /*
    // ---------------------------------------------------------
    // OPTION B: C++11 Standard (Range-Based For Loop)
    // ---------------------------------------------------------
    // Modern syntax. "For every character (c) in lowerStr..."
    // Uses reference (&c) to modify the actual character in memory.

    for (char &c : lowerStr) {
        c = tolower(c);
    }
    */

    return lowerStr;
}

/**
 * Validates if the user's input matches one of the 4 supported moods.
 * @param inputMood: The raw string entered by the user.
 * @return: true if the mood is supported, false otherwise.
 */
bool MoodPlayer::isValidMood(const string& inputMood) {
    string m = toLowerCase(inputMood);
    if (m == "happy" || m == "sad" || m == "energetic" || m == "relaxed") {
        return true;
    }
    return false;
}



// ----------------Playlist Loading Logic (Modular Design)-------------------------

void MoodPlayer::loadHappyTracks() {
    playlist.push_back("Pharrell Williams - Happy");
    playlist.push_back("Katrina & The Waves - Walking on Sunshine");
    playlist.push_back("Justin Timberlake - Can't Stop the Feeling!");
    playlist.push_back("Bruno Mars - Uptown Funk");
    // Extra Tracks can be added here.
}

void MoodPlayer::loadSadTracks() {
    playlist.push_back("Adele - Someone Like You");
    playlist.push_back("Sam Smith - Stay With Me");
    playlist.push_back("Coldplay - Fix You");
    playlist.push_back("Lewis Capaldi - Someone You Loved");
    // Extra Tracks can be added here.
}

void MoodPlayer::loadEnergeticTracks() {
    playlist.push_back("Survivor - Eye of the Tiger");
    playlist.push_back("Queen - Don't Stop Me Now");
    playlist.push_back("Eminem - Lose Yourself");
    playlist.push_back("Bon Jovi - Livin' on a Prayer");
    // Extra Tracks can be added here.
}

void MoodPlayer::loadRelaxedTracks() {
    playlist.push_back("Lo-Fi Beats - Rainy Night");
    playlist.push_back("Jack Johnson - Better Together");
    playlist.push_back("Norah Jones - Don't Know Why");
    playlist.push_back("John Mayer - Gravity");
    // Extra Tracks can be added here.
}

/**
 * Master load function.
 * Clears any existing playlist and delegates loading to specific
 * helper functions based on the current mood state.
 */
void MoodPlayer::loadPlaylist() {
    playlist.clear(); // Ensure previous songs are removed
    currentTrackIndex = 0; // Reset track counter

    string m = toLowerCase(currentMood);

    if (m == "happy") loadHappyTracks();
    else if (m == "sad") loadSadTracks();
    else if (m == "energetic") loadEnergeticTracks();
    else if (m == "relaxed") loadRelaxedTracks();
}


/**
 * Displays the first 3 songs of the playlist to the user.
 * Handles cases where the playlist is smaller than 3 songs.
 */
void MoodPlayer::printPlaylistPreview() {
    cout << "Recommendation tracks:" << endl;

    // Safety check: ensure we don't access out of bounds if list is short
    int limit = 3;
    if (playlist.size() < 3) {
        limit = playlist.size();
    }

    for (int i = 0; i < limit; i++) {
        cout << (i + 1) << ". " << playlist[i] << endl;
    }

    if (playlist.size() > 3) {
        cout << "...and more" << endl;
    }
}



// -----------------------Public Interface Methods----------------------

/**
 * Sets the current mood and triggers the playlist loading process.
 * If the mood is invalid, it rejects the change.
 * @param userMood: The mood input from the user.
 */
void MoodPlayer::setMood(const string& userMood) {
    if (isValidMood(userMood)) {
        currentMood = userMood;
        moodHistory.push_back(currentMood); // Add to history

        loadPlaylist(); // Encapsulation: Internal logic handles the list generation

        cout << "\n>> Mood set to '" << currentMood << "'. Playlist loaded!" << endl;
        printPlaylistPreview(); // Show the preview immediately
    } else {
        cout << "\n>> Error: Invalid mood! Please try: Happy, Sad, Energetic, or Relaxed." << endl;
    }
}

/**
 * Retrieves the current track name safely.
 * @return: The name of the track or an error message if empty.
 */
string MoodPlayer::getRecommendation() {
    if (playlist.empty()) {
        return "No playlist loaded. Please set a mood first.";
    }
    return playlist[currentTrackIndex]; // Return the track at the current index
}

/**
 * Simulates playing the current track by printing to console.
 */
void MoodPlayer::playTrack() {
    if (playlist.empty()) {
        cout << ">> Playlist is empty! Set a mood first." << endl;
    } else {
        cout << ">> Now Playing: " << getRecommendation() << endl;
    }
}

/**
 * Advances the playlist to the next track.
 * Loops back to the start if the end of the playlist is reached.
 */
void MoodPlayer::nextTrack() {
    if (playlist.empty()) {
        cout << ">> No tracks to skip. Set a mood first." << endl;
        return;
    }

    // Move to next track
    currentTrackIndex++;

    // Wrap-around logic - Check if we reached the end of the playlist
    if (currentTrackIndex >= playlist.size()) {
        cout << ">> End of playlist reached. Restarting from the first track." << endl;
        currentTrackIndex = 0; // Loop back to start
    } else {
        cout << ">> Skipped to next track..." << endl;
    }

    // Automatically play the new track for better user experience
    playTrack();
}

/**
 * Displays a historical list of all valid moods entered during the session.
 */
void MoodPlayer::showMoodHistory() {
    cout << "\n--- Session Mood History ---" << endl;
    if (moodHistory.empty()) {
        cout << "No moods recorded yet." << endl;
    } else {
        for (size_t i = 0; i < moodHistory.size(); ++i) {
            cout << (i + 1) << ". " << moodHistory[i] << endl;
        }
    }
    cout << "----------------------------" << endl;
}

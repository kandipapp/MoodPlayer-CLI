# 🎵 MoodPlayer CLI

> A smart, console-based music recommendation engine built in C++.

![C++](https://img.shields.io/badge/Language-C++11-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)

**MoodPlayer** is an interactive software tool designed to curate music playlists based on the user's current emotional state. Built with a focus on **Object-Oriented Programming (OOP)**, it features robust input validation, dynamic playlist generation, and session-based history tracking.

---

## 🚀 Features

* **Mood-Based Curation:** Instantly generates playlists for 4 distinct mood states: *Happy, Sad, Energetic, and Relaxed*.
* **Smart Input Validation:** Includes a custom case-insensitive parser (e.g., accepts "HAPPY", "Happy", or "happy") to prevent user errors.
* **Session Personalization:** Tracks and displays a history of all moods selected during the active session.
* **Playback Simulation:** Navigate through tracks with `Next Track` functionality, featuring playlist wrapping/looping logic.
* **Encapsulated Design:** strictly adheres to OOP principles, protecting internal state integrity via private members and public interfaces.

---

## 🛠️ Tech Stack & Concepts
* **Language:** C++ (Standard 11+)
* **Architecture:** Modular Design (Driver / Interface / Implementation separation)
* **Core Concepts:**
    * Encapsulation & Data Hiding
    * `std::vector` for dynamic memory management
    * Input Sanitization & Error Handling

---

## 📂 Project Structure

The project is organized into three modular components:

| File | Description |
| :--- | :--- |
| `main.cpp` | **The Driver.** Handles the user menu loop and input capture. Acts as the UI layer. |
| `MoodPlayer.h` | **The Interface.** Header file declaring the class structure and public/private members. |
| `MoodPlayer.cpp` | **The Logic.** Contains the implementation of algorithms, playlist loaders, and validation logic. |

---

## 💻 Getting Started

### Prerequisites
* A C++ Compiler (GCC, Clang, or MSVC)

### Installation & Run
1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/YOUR_USERNAME/MoodPlayer-CLI.git](https://github.com/YOUR_USERNAME/MoodPlayer-CLI.git)
    cd MoodPlayer-CLI
    ```

2.  **Compile the source code:**
    ```bash
    g++ main.cpp MoodPlayer.cpp -o moodplayer
    ```

3.  **Run the application:**
    * On Windows:
        ```bash
        moodplayer.exe
        ```
    * On Mac/Linux:
        ```bash
        ./moodplayer
        ```

---

## 📸 Usage Demo

```text
========================================
   Welcome to MoodPlayer
========================================

1. Set Mood
2. Play Current Track
3. Next Track
4. Show Mood History
5. Exit

Enter your choice: 1
Enter your mood: Energetic

>> Mood set to 'Energetic'. Playlist loaded!
Recommendation tracks:
1. Survivor - Eye of the Tiger
2. Queen - Don't Stop Me Now
...and more
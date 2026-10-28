# Music Playlist Manager

## Project Overview
A beginner-friendly C++ Data Structures and Algorithms microproject that manages song titles using a doubly linked list and a graphical interface built with `graphics.h`.

## Features
- Add a song
- Display the playlist
- Search for a song
- Delete a song
- Move to the next song
- Move to the previous song
- Show the currently selected song
- Graphical menu with keyboard controls

## Technologies Used
- C++
- Doubly Linked List
- `graphics.h` (BGI)
- Turbo C++ 3.00

## Files
- `MUSIC.CPP` — source code
- `screenshots/` — add screenshots of the program here
- `Music_Playlist_Manager_DSA_Microproject_Final.pdf` — add your project report here if you want to include it

## How to Run
1. Open `MUSIC.CPP` in Turbo C++ 3.00 or a compatible BGI environment.
2. Ensure the BGI graphics driver is installed.
3. Check the graphics path in `initgraph(&gd, &gm, "C:\\TC\\BGI");`. Change it if your BGI folder is elsewhere.
4. Compile and run the program.
5. Use keys `1` to `6` to choose a menu item and `0` to exit.

## Data Structure
Each song node contains a title and two pointers: `prev` points to the previous song and `next` points to the next song.

## Limitations
This program stores and manages song titles only. It does not play audio files. The menu is controlled with the keyboard; the drawn boxes are visual menu items, not clickable buttons.

## Author
- Name: Add your name
- Roll Number: Add your roll number
- Department/Class: Add your department or class

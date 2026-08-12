#include <iostream>
#include <string>
#include "double_ll_h_2.h"

int main() {
    DoubleList<std::string> *playlist = nullptr;

    // 1. Create a playlist using multiple songs
    circularInsertTail(std::string("Leonara"), &playlist);
    circularInsertTail(std::string("About You"), &playlist);
    circularInsertTail(std::string("KLWKN"), &playlist);
    std::cout << "My Playlist:\n";
    printPlaylist(playlist);
    std::cout << "\n";

    // 2. Insert at the end
    std::cout << "Inserting at the end:\n";
    circularInsertTail(std::string("Heaven Knows"), &playlist);
    printPlaylist(playlist);
    std::cout << "\n";

    // 3. Delete a node
    std::cout << "Deleting a node:\n";
    circularDeleteSong(std::string("KLWKN"), &playlist);
    printPlaylist(playlist);
    std::cout << "\n";

    // 4. Play Next / Previous Song
    DoubleList<std::string> *current = playlist;

    std::cout << "Play Next Song:\n";
    playNextSong(&current);
    std::cout << "\n";

    std::cout << "Play Previous Song:\n";
    playPreviousSong(&current);

    return 0;
}
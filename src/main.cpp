#include <iostream>
#include <chrono>
#include <thread>

#include "steam/steam_api.h"
#include "song.hpp"
#include "songs/songs.hpp"

int main()
{
    bool bret;

    song_init();

    bret = SteamAPI_Init();
    if (!bret) {
        std::cerr << "failed to initialize Steam API" << std::endl;
        return 1;
    }

    SteamController()->Init();

    ControllerHandle_t controllers[STEAM_CONTROLLER_MAX_COUNT];
    ControllerHandle_t active_controller;

    std::cerr << "Checking controller" << std::endl;
    while (true) {
        SteamAPI_RunCallbacks();

        if (!active_controller) {
            int ctrl_count = SteamController()->GetConnectedControllers(controllers);
            if (ctrl_count) {
                std::cerr << "found " << ctrl_count << " controllers" << std::endl;
                active_controller = controllers[0];
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } else {
            std::cout << "Song choice: " << std::endl;
            std::cout << "0) Quit the program" << std::endl;
            std::cout << "1) Beethoven N°9" << std::endl;
            std::cout << "2) We wish you a merry christmas" << std::endl;
            std::cout << "3) Zelda's lullaby" << std::endl;
            std::cout << "4) The Heart Asks Pleasure First" << std::endl;
            std::cout << std::endl << "Please enter your choice: " << std::endl;

            int song;
            std::cin >> song;

            if (song == 0)
                break;

            switch (song) {
                case 1:
                    std::cout << "playing 'beethoven n9'" << std::endl;
                    beethoven_n9().play(active_controller);
                    break;
                case 2:
                    std::cout << "playing 'we wish you a merry christmas'" << std::endl;
                    we_wish_you_a_merry_christmas().play(active_controller);
                    break;
                case 3:
                    std::cout << "playing 'Zelda's lullaby" << std::endl;
                    zelda_lullaby().play(active_controller);
                    break;
                case 4:
                    std::cout << "playing 'The Heart Asks Pleasure First'" << std::endl;
                    the_heart_asks_pleasure_first().play(active_controller);
                    break;
                default:
                    std::cout << "Bad song" << std::endl;
                    break;
            }
        }
    }

    SteamController()->Shutdown();

    SteamAPI_Shutdown();
    return 0;
}

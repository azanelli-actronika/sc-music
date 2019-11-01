#pragma once

#include "steam/steam_api.h"

enum NotePitch {
    REST = 0,
    LA0, LA0D, SI0,
    DO1, DO1D, RE1, RE1D, MI1, FA1, FA1D, SOL1, SOL1D, LA1, LA1D, SI1,
    DO2, DO2D, RE2, RE2D, MI2, FA2, FA2D, SOL2, SOL2D, LA2, LA2D, SI2,
    DO3, DO3D, RE3, RE3D, MI3, FA3, FA3D, SOL3, SOL3D, LA3, LA3D, SI3,
    DO4, DO4D, RE4, RE4D, MI4, FA4, FA4D, SOL4, SOL4D, LA4, LA4D, SI4,
    DO5, DO5D, RE5, RE5D, MI5, FA5, FA5D, SOL5, SOL5D, LA5, LA5D, SI5,
    DO6, DO6D, RE6, RE6D, MI6, FA6, FA6D, SOL6, SOL6D, LA6, LA6D, SI6,
    DO7, DO7D, RE7, RE7D, MI7, FA7, FA7D, SOL7, SOL7D, LA7, LA7D, SI7,
    DO8,
    MAX,
};

enum NoteValue {
    WHOLE   = 0x1,
    HALF    = 0x2,
    QUARTER = 0x4,
    EIGHTH  = 0x8,
};

struct Note {
    NotePitch pitch;
    unsigned value;  /* bitflag of NoteValue */
};

class Song {
public:
    Song(unsigned bpm, Note *notes, unsigned count);
    Song(unsigned bpm, Note *left, unsigned left_count, Note *right,
            unsigned right_count);

    void play(ControllerHandle_t controller) const;

private:
    enum Hand { eLeft, eRight };

    void play_hand(ControllerHandle_t controller, Hand hand) const;
    void play_note(ControllerHandle_t controller, ESteamControllerPad side,
            const Note *note) const;
    void init_note_value_us();
    unsigned note_value_in_us(const Note *note) const;
    unsigned normalize_amplitude(const Note *note) const;

    unsigned m_bpm;

    Note *m_left;
    unsigned m_left_count;

    Note *m_right;
    unsigned m_right_count;

    struct {
        unsigned whole;
        unsigned half;
        unsigned quarter;
        unsigned eighth;
    } m_note_value_us;
};

void song_init();

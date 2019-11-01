#include "song.hpp"

#include <chrono>
#include <thread>

static double note_frequency[NotePitch::MAX] = {
    /* https://en.wikipedia.org/wiki/Piano_key_frequencies */
    [REST] = 0.0,
    [LA0] = 27.50000,
    [LA0D] = 29.13524,
    [SI0] = 30.86771,

    [DO1] = 32.70320,
    [DO1D] = 34.64783,
    [RE1] = 36.70810,
    [RE1D] = 38.89097,
    [MI1] = 41.20344,
    [FA1] = 43.65353,
    [FA1D] = 46.24930,
    [SOL1] = 48.99943,
    [SOL1D] = 51.91309,
    [LA1] = 55.00000,
    [LA1D] = 58.27047,
    [SI1] = 61.73541,

    [DO2] = 65.40639,
    [DO2D] = 69.29566,
    [RE2] = 73.41619,
    [RE2D] = 77.78175,
    [MI2] = 82.40689,
    [FA2] = 87.30706,
    [FA2D] = 92.49861,
    [SOL2] = 97.99886,
    [SOL2D] = 103.8262,
    [LA2] = 110.0000,
    [LA2D] = 116.5409,
    [SI2] = 128.4708,

    [DO3] = 130.8128,
    [DO3D] = 138.8128,
    [RE3] = 146.8324,
    [RE3D] = 155.5635,
    [MI3] = 164.8138,
    [FA3] = 174.6141,
    [FA3D] = 184.9972,
    [SOL3] = 195.9977,
    [SOL3D] = 207.6523,
    [LA3] = 220.0000,
    [LA3D] = 233.0819,
    [SI3] = 246.9417,

    [DO4] = 261.6256,
    [DO4D] = 277.1826,
    [RE4] = 293.6648,
    [RE4D] = 311.1270,
    [MI4] = 329.6276,
    [FA4] = 349.2282,
    [FA4D] = 369.9944,
    [SOL4] = 391.9954,
    [SOL4D] = 415.3047,
    [LA4] = 440.0000,
    [LA4D] = 466.1638,
    [SI4] = 493.8833,

    [DO5] = 523.2511,
    [DO5D] = 554.3653,
    [RE5] = 587.3295,
    [RE5D] = 622.2540,
    [MI5] = 659.2551,
    [FA5] = 698.4565,
    [FA5D] = 739.9888,
    [SOL5] = 783.9909,
    [SOL5D] = 830.6094,
    [LA5] = 880.0000,
    [LA5D] = 932.3275,
    [SI5] = 987.7666,

    [DO6] = 1046.502,
    [DO6D] = 1108.731,
    [RE6] = 1174.659,
    [RE6D] = 1244.508,
    [MI6] = 1318.510,
    [FA6] = 1396.913,
    [FA6D] = 1479.978,
    [SOL6] = 1567.982,
    [SOL6D] = 1661.219,
    [LA6] = 1760.000,
    [LA6D] = 1864.655,
    [SI6] = 1975.533,

    [DO7] = 2093.005,
    [DO7D] = 2217.461,
    [RE7] = 2349.318,
    [RE7D] = 2489.016,
    [MI7] = 2637.020,
    [FA7] = 2793.826,
    [FA7D] = 2959.955,
    [SOL7] = 3135.963,
    [SOL7D] = 3322.438,
    [LA7] = 3520.000,
    [LA7D] = 3729.310,
    [SI7] = 3951.066,

    [DO8] = 4186.009,
};

/* in us */
static unsigned int note_period[NotePitch::MAX];

static void note_period_init() {
    for (int i = 0; i < NotePitch::MAX; i++) {
        if (note_frequency[i] == 0.0)
            continue;

        note_period[i] = 1000000 / note_frequency[i];
    }
}

static unsigned int note_period_get(NotePitch pitch) {
    return note_period[pitch];
}

void song_init()
{
    note_period_init();
}

Song::Song(unsigned bpm, Note *notes, unsigned count)
    : m_bpm(bpm), m_left(notes), m_left_count(count), m_right(notes),
        m_right_count(count)
{
    init_note_value_us();
}

Song::Song(unsigned bpm, Note *left, unsigned left_count, Note *right,
            unsigned right_count)
    : m_bpm(bpm), m_left(left), m_left_count(left_count), m_right(right),
        m_right_count(right_count)
{
    init_note_value_us();
}

void Song::init_note_value_us()
{
    unsigned quarter = 60000000 / m_bpm;
    unsigned half = 2 * quarter;
    unsigned whole = 2 * half;
    unsigned eighth = quarter / 2;

    m_note_value_us.whole = whole;
    m_note_value_us.half = half;
    m_note_value_us.quarter = quarter;
    m_note_value_us.eighth = eighth;
}

void Song::play(ControllerHandle_t controller) const
{
        std::thread left_hand(&Song::play_hand, this, controller, eLeft);
        std::thread right_hand(&Song::play_hand, this, controller, eRight);

        left_hand.join();
        right_hand.join();
}

void Song::play_hand(ControllerHandle_t controller, Hand hand) const
{
    Note *notes;
    unsigned count;
    ESteamControllerPad pad;

    if (hand == eLeft) {
        notes = m_left;
        count = m_left_count;
        pad = k_ESteamControllerPad_Left;
    } else {
        notes = m_right;
        count = m_right_count;
        pad = k_ESteamControllerPad_Right;
    }

    for (unsigned i = 0; i < count; i++)
        play_note(controller, pad, &notes[i]);
}

void Song::play_note(ControllerHandle_t controller, ESteamControllerPad side,
        const Note *note) const
{
    unsigned value_us = note_value_in_us(note);

    if (note->pitch == REST) {
        std::this_thread::sleep_for(std::chrono::microseconds(value_us));
        return;
    }

    unsigned period = note_period_get(note->pitch);
    unsigned half_period = period / 2;

    /* substract some ms to split the note, especially when repeating the same
     * note */
    unsigned repeat = (value_us - 5000) / period;
    unsigned amplitude = normalize_amplitude(note);

    unsigned active_time = amplitude * half_period / 100;
    if (active_time > half_period)
        active_time = half_period;

    unsigned pause_time = period - active_time;

    SteamController()->TriggerRepeatedHapticPulse(controller, side, active_time,
            pause_time, repeat, 0);
    std::this_thread::sleep_for(std::chrono::microseconds(value_us));
}

unsigned Song::note_value_in_us(const Note *note) const
{
    unsigned value_us = 0;

    if (note->value & WHOLE)
        value_us += m_note_value_us.whole;
    if (note->value & HALF)
        value_us += m_note_value_us.half;
    if (note->value & QUARTER)
        value_us += m_note_value_us.quarter;
    if (note->value & EIGHTH)
        value_us += m_note_value_us.eighth;

    return value_us;
}

unsigned Song::normalize_amplitude(const Note *note) const
{
    /* Alps actuators in Steam controller have resonances frequencies around
     * 170 Hz and 350 Hz causing bad music in the third and fourth octave
     * interval */
    if (note->pitch >= DO2 && note->pitch <= LA4) {
        return 10;
    }

    return 100;
}

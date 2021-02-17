#include "fixed_delta_timer.h"
#include <iostream>
#include <algorithm>

namespace Engine {

    FixedDeltaTimer::FixedDeltaTimer() {
        last_current_time = get_current_time();
        dt = 1.0 / 60.0;
        elasped_time = 0.0;

    }

    FixedDeltaTimer::~FixedDeltaTimer() {

    }

    void FixedDeltaTimer::update() {
        double new_time = get_current_time();
        double frame_time = new_time - last_current_time;
        last_current_time = new_time;

        float delta_time;

        while(frame_time > 0.0) {
            delta_time = std::min(frame_time, dt);
            frame_time -= delta_time;
            elasped_time += delta_time; // is this really elased time ??
        }


    }


    double FixedDeltaTimer::get_current_time() {
        time_t seconds;
        time(&seconds);

        return seconds;

    }
}

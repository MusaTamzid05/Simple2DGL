#include "fixed_delta_timer.h"
#include "display.h"
#include <iostream>
#include <algorithm>

namespace Engine {

    FixedDeltaTimer::FixedDeltaTimer(Display* display):display(display) {
        current_time = get_current_time();
        delta_time = 0.01;
        elasped_time = 0.0;
        accumulator = 0.0;

    }

    FixedDeltaTimer::~FixedDeltaTimer() {

    }

    void FixedDeltaTimer::update() {
        double new_time = get_current_time();
        double frame_time = new_time - current_time;

        if(frame_time > 0.25)
            frame_time = 0.25;

        current_time = new_time;
        accumulator += frame_time;

        while(accumulator >= delta_time) {
            display->update(delta_time);
            elasped_time += delta_time;
            accumulator -= delta_time;
        }

    }


    double FixedDeltaTimer::get_current_time() {
        time_t seconds;
        time(&seconds);

        return seconds;

    }
}

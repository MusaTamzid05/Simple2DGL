#ifndef FIXED_DELTA_TIMER_H
#define FIXED_DELTA_TIMER_H

#include <time.h>

namespace Engine {

    class Display;
    class FixedDeltaTimer {

        public:

            FixedDeltaTimer(Display* display);
            virtual ~FixedDeltaTimer();

            void update();


            double current_time;
            double current_delta_time;

        private:

            double get_current_time();
            double delta_time;

            double elasped_time;
            double accumulator;

            Display* display;

            



    };


};

#endif

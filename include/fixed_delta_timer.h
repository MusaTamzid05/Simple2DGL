#ifndef FIXED_DELTA_TIMER_H
#define FIXED_DELTA_TIMER_H

#include <time.h>

namespace Engine {

    class FixedDeltaTimer {

        public:

            FixedDeltaTimer();
            virtual ~FixedDeltaTimer();

            void update();


            double last_current_time;
            double current_delta_time;

        private:

            double get_current_time();
            double dt;

            double elasped_time;

            



    };


};

#endif

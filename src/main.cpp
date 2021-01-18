#include <iostream>
#include "display.h"

int main(int argc, char** argv) {

    Engine::Display display("Display", 640, 480);
    display.run();
    return 0;
}

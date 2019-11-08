#include <Arduino.h>
#include <queue>

using namespace std;

#define TRIGGER 22
#define ECHO 23

class reader{
    public:
        void init();
        String getDistance();
        String getLevel();
};
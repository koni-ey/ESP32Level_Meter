#include <Arduino.h>

class myServer{
public:
    void init();
    void handleClient(String distance, String level);
    String getIp();



};
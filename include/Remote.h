#ifndef REMOTE_H
#define REMOTE_H

#include <IRremote.h>

class Remote
{
    IRrecv receiver;
    decode_results results;

  protected:
    int convertButtonPressToInt();

  public:
    Remote(const int);
    void enableIRIn();
    bool hasValue();
    int getValue();
    void resume();
};

#endif
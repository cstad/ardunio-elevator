#include <Remote.h>
#include <IRremote.h>

// Constructor
Remote::Remote(const int pin)
  : receiver{pin}
{
  decode_results results;
}

// Start consuming IR signals
void Remote::enableIRIn()
{
  receiver.enableIRIn();
}

bool Remote::hasValue()
{
  return receiver.decode(&results);
}

// Get the number button pressed if there was one otherwise return null
int Remote::getValue()
{
  return convertButtonPressToInt();
}

// Consume the next IR signal
void Remote::resume()
{
  receiver.resume();
}

int Remote::convertButtonPressToInt()
{
  switch(results.value) {
    case 0xFF30CF: return 1;
    case 0xFF18E7: return 2;
    case 0xFF7A85: return 3;
    case 0xFF10EF: return 4;
    case 0xFF38C7: return 5;
    case 0xFF5AA5: return 6;
    case 0xFF42BD: return 7;
    case 0xFF4AB5: return 8;
    case 0xFF52AD: return 9;
    default: return 0;
  }
}
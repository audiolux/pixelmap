#include "pixelmap/pixelmap.h"
#include <FastLED.h>
#include <Logging.h>

#define LOGLEVEL LOG_LEVEL_INFOS

using namespace pixelmap;

Input* input = new WaveInput(3.0);
LEDStrip strip = LEDStrip(128);
LEDs leds = LEDs(strip, 0, 128);

Visualization* viz = new RippleVisualization(input, 128);
Animation* anim = new PassThroughAnimation(viz, leds);

void setup() {
  Log.Init(LOGLEVEL, 9600);
  Log.Info("setup()");

  FastLED.addLeds<WS2811, 6, RGB>(strip.leds, 128);
  FastLED.show();

  Looper* looper = Looper::instance();
  looper->addInput(input);
  looper->addVisualization(viz);
  looper->addAnimation(anim);

  Log.Info("Finished setup()");
}

void loop() {
  Looper::instance()->loop();
}

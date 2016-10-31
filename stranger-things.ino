#include "FastLED/FastLED.h"
FASTLED_USING_NAMESPACE;
#define LED_TYPE            WS2811  // Set to your led type (see FastLED) 
#define NUM_LEDS            100     // Set to the number of leds in your string
#define DATA_PIN            6       // Wire your leds to this digital pin
#define SKIP_INDEX          -1
#define BRIGHTNESS          96
#define FRAMES_PER_SECOND   120
CRGB leds[NUM_LEDS];

bool flickerOn = true;
bool idleMode = true;

void setup() {
    FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    // Set up web control
    Particle.function("led",ledToggle);
}

void loop() {
  setColors();
  if (flickerOn) {
    addFlicker(30);
  }

  FastLED.show();  
  FastLED.delay(1000/FRAMES_PER_SECOND); 
 
  // In "Idle Mode," occasionally spell out messages
  if (!idleMode) {
    int r = random(0,10000);
    if (r == 1) {
      spell("Happy Halloween");
    } else if (r == 2) {
      spell("Help me");
    } else if (r == 3) {
      spell("Are you there");
    } // Add your own messages here
  }
}

// Web control function
int ledToggle(String command)
{
    if (command=="setupMode") {
        setupMode();
        return 1;
    } else if (command=="idleOn") {
        // Turn on randomly-occurring messages
        idleMode = true;
    } else if (command=="idleOff") {
        // Turn off randomly-occurring messages,
        // e.g., to ensure only stream of message does not get interrupted
        idleMode = false;
    } else if (command=="flickerOn") {
        flickerOn = true;
    } else if (command=="flickerOff") {
        // Turn the flickering off -- may be better for some lighting conditions
        flickerOn = false;
    } else if (command=="glowdown") {
        glowdown();
        return 1;
    } else if (command == "off") {
        FastLED.clear(); 
        FastLED.show();
        return 1;
    } else {
        // Spell out unrecognized commands
        spell(command); 
        return 1; 
    }
}

// Colors based on show screencaps
void setColors() {
    int color_count = 7;
    CRGB colors[7] = {
        CRGB::DarkBlue,
        CRGB::DeepPink,
        CRGB::LightGreen,
        CRGB::DeepSkyBlue,
        CRGB::DarkOrange,
        CRGB::Fuchsia,
        CRGB::Turquoise
    };
    for (int i = 0; i < color_count; ++i) {
        for (int j = i; j < NUM_LEDS; j += color_count) {
            leds[j] = colors[i];
        }
    }
}

void addFlicker(int chanceOfFlicker) 
{
  if( random(0,100) < chanceOfFlicker) {
    leds[ random16(NUM_LEDS) ] -= CRGB::White;
  }
}

// Gradually lower to the lights for dramatic effect (usually before spelling)
void glowdown() {
  for (int i = 100; i > 0; --i){

      for(int x = 0; x < NUM_LEDS; ++x){
          leds[x].fadeLightBy( 32 ); // 12.5%
      }
          
      FastLED.show();
      delay(50); 
    }      
}

void glowLight(int i, int duration)
{
    CRGB current = leds[i];
    leds[i].maximizeBrightness();
    FastLED.show();
    delay(duration);
    leds[i] = current;
    FastLED.show();
}

// Lower the lights dramatically, then spell out the String by glowing each
// letter one by one
void spell(String str)
{
    glowdown();
    str.toLowerCase(); 
    for (int i = 0; i < str.length(); ++i) {
        char tmp = str[i];
        int j = getLetterInt(tmp);
        if (j == SKIP_INDEX) {
            continue;
        }
        // Randomize duration of lights and delay between lights for a little
        // extra organic/creepy factor
        glowLight(j % NUM_LEDS, random(3, 13) * 100);
        delay(random(3, 13) * 100);
    }
}

// Very memory-limited, so better to do a bunch of ifs than store a map (sorry)
// Organized by light order for easier adgustment
int getLetterInt(char letter) {
    // First row - left to right
    if (letter == 'a') {
        return 97;
    } else if (letter == 'b') {
        return 95;
    } else if (letter == 'c') {
        return 92;
    } else if (letter == 'd') {
        return 90;
    } else if (letter == 'e') {
        return 87;
    } else if (letter == 'f') {
        return 83;
    } else if (letter == 'g') {
        return 81;
    } else if (letter == 'h') {
        return 76;
    // Second row - right to left
    } else if (letter == 'q') {
        return 72;
    } else if (letter == 'p') {
        return 69;
    } else if (letter == 'o') {
        return 67;
    } else if (letter == 'n') {
        return 64;
    } else if (letter == 'm') {
        return 61;
    } else if (letter == 'l') {
        return 59;
    } else if (letter == 'k') {
        return 55;
    } else if (letter == 'j') {
        return 54;
    } else if (letter == 'i') {
        return 51;    
    // Third row - left to right
    } else if (letter == 'r') {
        return 43;
    } else if (letter == 's') {
        return 41;
    } else if (letter == 't') {
        return 39;
    } else if (letter == 'u') {
        return 36;
    } else if (letter == 'v') {
        return 34;
    } else if (letter == 'w') {
        return 30;
    } else if (letter == 'x') {
        return 27;
    } else if (letter == 'y') {
        return 25;
    } else if (letter == 'z') {
        return 22;
    } 
    return SKIP_INDEX; // out of alphabet
}

// Light all letters of the alphabet to make 
// physical alignment of letters easier
void setupMode() 
{
    String str = "abcdefghqponmlkjirstuvwxyz";
    CRGB color = CRGB::White;
    for (int i = 0; i < str.length(); ++i) {
        char tmp = str[i];
        int j = getLetterInt(tmp);
        leds[j] = color;
        color -= CRGB(0,13,13);
    }
    FastLED.show(); 
}

#include <EEPROM.h>

#include "Adafruit_WS2801.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
#include <avr/power.h>
#endif

uint8_t dataPin  = 8;     // White wire
uint8_t clockPin = 9;     // Green wire
int leds = 21;            // Antal LEDs i slingan

int button = 2;
int push = 0;

int r = 0;
int g = 0;
int b = 0;
int bulle = 0;
int fade_in  = 7000;    // def 20  7000 
int st_pause = 4000;    // def 500
int fade_out = 7000;    // def 3000
int in_between = 2000;  // delay mellan stjärnbilder
int mode;               // väljer vilken stjärnbild som visas
int addr = 1;           //adressen där mode sparas i EEPROM

long rand_mode;

//--------------------------------------------------------------------------------------------------------------------
int const_1 = 0;      //  PEGASUS
int const_2 = 1;      //  SVANEN
int const_3 = 6;      //  LYRAN
int const_4 = 7;      //  HERKULES
int const_5 = 8;      //  NORRA KRONAN
int const_6 = 9;      //  BJÖRNVÄKTAREN
int const_7 = 5;      //  DRAKEN
int const_8 = 3;      //  CEPHEUS
int const_9 = 2;      //  CASSIOPEIA
int const_10 = 4;     //  LILLA BJÖRN
int const_11 = 10;    //  STORA BJÖRN (KARLAVAGNEN)
int const_12 = 11;    //  LEJONET
int const_13 = 12;    //  KRÄFTAN
int const_14 = 13;    //  TVILLINGARNA
int const_15 = 14;    //  KUSKEN
int const_16 = 15;    //  PERSEUS
int const_17 = 16;    //  OXEN
int const_18 = 17;    //  ORION
int const_19 = 18;    //  HAREN
int const_20 = 19;    //  STORA HUND
int const_21 = 20;    //  LILLA HUND


Adafruit_WS2801 strip = Adafruit_WS2801(leds, dataPin, clockPin);

//-------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------VOID_SETUP-------------

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip.begin();
  strip.show();

  pinMode(button, INPUT);
  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  mode = EEPROM.read(addr);      // Läser vilket mode som användes senast från EEPROM
  // Serial.println("EEPROM read");
  // delay(1000);
  // Serial.println("Mode is:");
  // Serial.println(mode);
  // delay(1000);
  // Serial.println("Adding one to mode....");
  // delay(1000);

  ++mode;                       // byter till nästa mode
  if (mode > 6){
    mode = 0;
  }

  // Serial.println("Mode is now:");
  // Serial.println(mode);
  // delay(2000);
  // Serial.println("STARTING....");
  // Serial.println("...");
  // delay(1000);
  // Serial.println("...");
  // delay(1000);
  // Serial.println("...");
  
  EEPROM.write(addr, mode);     // Skriver värdet på detta mode till EEPROM
  
}

//-------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------VOID_LOOP--------------

void loop() {

// TODO Fix menu selection without resetting.


//  rand_mode = random(5);
//  Serial.println(rand_mode);
//  if (rand_mode == 0){mode_one();}
//  else if (rand_mode == 1){mode_two();}
//  else if (rand_mode == 2){mode_three();}
//  else if (rand_mode == 3){mode_four();}
//  else {all_on();}
  
    Serial.println(mode);
    if (mode == 0){mode_one();}
    else if (mode == 1){mode_two();}
    else if (mode == 2){mode_three();}
    else if (mode == 3){mode_four();}
    else if (mode == 4){mode_five();}
    else if (mode == 5){mode_six();}
    else {all_off();}
  }
    
  


//-------------------------------------------------------------------------------------------------------------------
void mode_one(){mag_order();} 

void mode_two(){blue_order();}

void mode_three(){vit_order();}

void mode_four(){vetint();}

void mode_five(){sos();}

void mode_six(){all_on();}




//--------------------------------------------------------------------------------------------FADE_1-21_MAGENTA------
void sos(){
all_on();
delay(100);
all_off();
delay(100);
all_on();
delay(100);
all_off();
delay(100);
all_on();
delay(100);
all_off();
delay(100);
all_on();
delay(100);
all_off();
delay(100);
all_on();
delay(100);
all_off();
delay(100);
}

//-------------------------------------------------------------------------------------------------------------------
void mag_order(){

  Serial.println("Mag_order");
  st(const_1,255,0,255);
  st(const_2,255,0,255);
  st(const_3,255,0,255);
  st(const_4,255,0,255);
  st(const_5,255,0,255);
  st(const_6,255,0,255);
  st(const_7,255,0,255);
  st(const_8,255,0,255);
  st(const_9,255,0,255);
  st(const_10,255,0,255);
  st(const_11,255,0,255);
  st(const_12,255,0,255);
  st(const_13,255,0,255);
  st(const_14,255,0,255);
  st(const_15,255,0,255);
  st(const_16,255,0,255);
  st(const_17,255,0,255);
  st(const_18,255,0,255);
  st(const_19,255,0,255);
  st(const_20,255,0,255);
  st(const_21,255,0,255);
  mag_order();
}

//-------------------------------------------------------------------------------------------------------------------
void vit_order(){

  Serial.println("Vit_order");
  st(const_1,255,255,255);
  st(const_2,255,255,255);
  st(const_3,255,255,255);
  st(const_4,255,255,255);
  st(const_5,255,255,255);
  st(const_6,255,255,255);
  st(const_7,255,255,255);
  st(const_8,255,255,255);
  st(const_9,255,255,255);
  st(const_10,255,255,255);
  st(const_11,255,255,255);
  st(const_12,255,255,255);
  st(const_13,255,255,255);
  st(const_14,255,255,255);
  st(const_15,255,255,255);
  st(const_16,255,255,255);
  st(const_17,255,255,255);
  st(const_18,255,255,255);
  st(const_19,255,255,255);
  st(const_20,255,255,255);
  st(const_21,255,255,255);
  vit_order();
}

void rand_const(){
  
  for (int i = 0; i < leds; i++){
 int con = random(0, 20);
 st(con, 255, 255, 255);
  }
 rand_const();
}

//--------------------------------------------------------------------------------------------FADE_IN_AND_OUT--------

void blue_order(){

  Serial.println("Blue_order");
  st(const_1,0,0,255);
  st(const_2,0,0,255);
  st(const_3,0,0,255);
  st(const_4,0,0,255);
  st(const_5,0,0,255);
  st(const_6,0,0,255);
  st(const_7,0,0,255);
  st(const_8,0,0,255);
  st(const_9,0,0,255);
  st(const_10,0,0,255);
  st(const_11,0,0,255);
  st(const_12,0,0,255);
  st(const_13,0,0,255);
  st(const_14,0,0,255);
  st(const_15,0,0,255);
  st(const_16,0,0,255);
  st(const_17,0,0,255);
  st(const_18,0,0,255);
  st(const_19,0,0,255);
  st(const_20,0,0,255);
  st(const_21,0,0,255);
  blue_order();
}

//-------------------------------------------------------------------------------------------------------------------


void st(int cons, int col_r, int col_g, int col_b){
  
  for (int i = 0; i < leds; i++){
    strip.setPixelColor(i, 0, 0, 0);
  }  

  strip.show();
  delay(10);

  for (int i = 0; i < 255; i++){   
    bulle++;
    if (bulle < col_r && bulle > 0){r++;}
    if (bulle < col_g && bulle > 0){g++;}
    if (bulle < col_b && bulle > 0){b++;} 
    strip.setPixelColor(cons, r, g, b);
    strip.show();
    delayMicroseconds(fade_in);
  }
  
  delay(st_pause); 

  for (int i = 0; i < 255; i++){
    bulle--;
    if (bulle < col_r && bulle > 0){r--;}
    if (bulle < col_g && bulle > 0){g--;}
    if (bulle < col_b && bulle > 0){b--;} 
    strip.setPixelColor(cons, r, g, b);
    strip.show();
    delayMicroseconds(fade_out);
    
  }
  delay(in_between);

}

//-------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------ALL_ON_WHITE-----------

void all_on(){
  Serial.println("All_on");
  for (int i = 0; i < leds; i++){
    strip.setPixelColor(i,255,255,255);
    strip.show();
  } 
  all_on();
}

//-------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------ALL_OFF----------------

void all_off(){
  Serial.println("All_off");
  for (int i = 0; i < leds; i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
  all_off();
} 

//-------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------VET_INTE_VARFÖR_JAG_ÄR-

void vetint(){
  for (int i = 0; i < leds; i++){
    int wich = random(0,leds);
    int colorR = random(0,255);
    int colorG = random(0,255);
    int colorB = random(0,255);
    strip.setPixelColor(wich, colorR, colorG, colorB);
  strip.show();
  }
  delay(10);
  vetint();
}

////-------------------------------------------------------------------------------------------------------------------
////--------------------------------------------------------------------------------------------Kopierat_från_exempelkoden
//
//// Slightly different, this one makes the rainbow wheel equally distributed 
//// along the chain
//void rainbowCycle(uint8_t wait) {
//  int i, j;
//  
//  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
//    for (i=0; i < strip.numPixels(); i++) {
//      // tricky math! we use each pixel as a fraction of the full 96-color wheel
//      // (thats the i / strip.numPixels() part)
//      // Then add in j which makes the colors go around per pixel
//      // the % 96 is to make the wheel cycle around
//      strip.setPixelColor(i, Wheel( ((i * 256 / strip.numPixels()) + j) % 256) );
//    }  
//    strip.show();   // write all the pixels out
//    delay(wait);
//  }
//}
//
//void rainbow(uint8_t wait) {
//  int i, j;
//   
//  for (j=0; j < 256; j++) {     // 3 cycles of all 256 colors in the wheel
//    for (i=0; i < strip.numPixels(); i++) {
//      strip.setPixelColor(i, Wheel( (i + j) % 255));
//    }  
//    strip.show();   // write all the pixels out
//    delay(wait);
//  }
//}
//
//// fill the dots one after the other with said color
//// good for testing purposes
//void colorWipe(uint32_t c, uint8_t wait) {
//  int i;
//  
//  for (i=0; i < strip.numPixels(); i++) {
//      strip.setPixelColor(i, c);
//      strip.show();
//      delay(wait);
//  }
//}


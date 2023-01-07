// Embedded Challenge Fall 2022
// Group 

// Anupam Tiwari , ast9885
// Dhana Laxmi Sirigireddy, ds6992
// Lakshitha Vivekananda, lv2218
// Divya Sai Tirumalasetty , dt2482



#include "mbed.h"

// Analog input pin for reading pressure sensor voltage
AnalogIn   ain(PA_0,3);

// Counter for keeping track of how long the pressure sensor voltage has been below 2.1V
uint32_t counter=0;

// Timer for measuring time intervals
Timer t;

#include <mbed.h>
// this file has all the functions for interacting with the screen
#include "drivers/LCD_DISCO_F429ZI.h"
#define BACKGROUND 1
#define FOREGROUND 0
#define GRAPH_PADDING 5

// LCD screen object
LCD_DISCO_F429ZI lcd;

// buffer for holding displayed text strings
char display_buf[2][60];

// Width and height of the graph area on the screen
uint32_t graph_width = lcd.GetXSize() - 2 * GRAPH_PADDING;
uint32_t graph_height = graph_width;

// sets the background layer to be visible, transparent, and resets its colors to all black
void setup_background_layer()
{
  lcd.SelectLayer(BACKGROUND);
  lcd.Clear(LCD_COLOR_BLACK);
  lcd.SetBackColor(LCD_COLOR_BLACK);
  lcd.SetTextColor(LCD_COLOR_GREEN);
  lcd.SetLayerVisible(BACKGROUND, ENABLE);
  lcd.SetTransparency(BACKGROUND, 0x7Fu);
}

// resets the foreground layer to all black
void setup_foreground_layer()
{
  lcd.SelectLayer(FOREGROUND);
  lcd.Clear(LCD_COLOR_BLACK);
  lcd.SetBackColor(LCD_COLOR_BLACK);
  lcd.SetTextColor(LCD_COLOR_LIGHTGREEN);
}

int main()
{
  // Set up the background and foreground layers of the LCD screen
  setup_background_layer();

  setup_foreground_layer();

  // Select the foreground layer for drawing
  lcd.SelectLayer(FOREGROUND);

  // Display a message on the screen
  lcd.DisplayStringAt(0, LINE(17), (uint8_t *)display_buf[0], LEFT_MODE);       // setting up the stm32 display board
  lcd.SelectLayer(FOREGROUND);

  while (1)
  {
    while (1)
    {
          printf("normal %f",ain.read_voltage());                               //reading and printing analog voltage difference created by pressure sensor
          volatile float voltage=ain.read_voltage();                            // Store the voltage in a local variable
          if(voltage>2.10){                                                     // If the voltage is greater than 2.1 V
              printf("In\n");                                                   // Print "In"
              snprintf(display_buf[4],60,"Baby is Safe");                                     //"Baby is safe" is displayed on the screen if voltage is greater than 2.1 V
              lcd.DisplayStringAt(0, LINE(16), (uint8_t *)display_buf[4], LEFT_MODE);
              lcd.SetTextColor(LCD_COLOR_GREEN);                                              // Set the text color to green
              counter=0;                                                                      // Reset the counter
          }
          else{
              printf("Out\n");                                                  // If the voltage is less than or equal to 2.1 V
              counter++;                                                        // Increment the counter
              if(counter>=10)                                                   // If the counter is greater than or equal to 10
              {
                  lcd.SetTextColor(LCD_COLOR_RED); 
                  snprintf(display_buf[2],60,"Baby in danger");                               //"Baby is safe" is displayed on the screen if voltage is less than 2.1 V for counter value >= 10
                  lcd.DisplayStringAt(0, LINE(16), (uint8_t *)display_buf[2], LEFT_MODE);     // Set the text color to red
              }

          }
          thread_sleep_for(1000);                                                             // Sleep for one second
    }
  }
}
#include <LiquidCrystal_I2C.h> // Defining our constant variables


#define totalLEDs 3

#define MAX_DELAY  2000
#define MIN_DELAY   250
#define DELAY_STEP  100

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // allows communication with LCD

bool gameRunning; // Defining our varying variables
int LEDs[TotalLEDs] ={};
int LDRs[TotalLEDs] ={};
int LEDsActive;
int shots;


unsigned int ledDelay;
unsigned int score;
unsigned long ledOn;


void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
 
  lcd.begin(16,2); // setting the LCD screen to print a starter game message
  lcd.setCursor(1,0);
  lcd.print("  Shoot Shoot  ");
  lcd.setCursor(1,1);
  lcd.print("   By Team 2   ");
  delay(2000);
  for(int i = 0; i < totalLEDs; i++) // setting the LEDs
  {
    pinMode(LEDs[i], OUTPUT);
    pinMode(LDRs[i], INPUT);
    digitalWrite(LEDs[i], LOW);
  }
 
  ledDelay = MAX_DELAY;//
  gameRunning = true;
  score=0;
  LEDsActive = -1;
 
  lcdAnimation(); // Moving to the lcdAnimation() function
}

void lcdAnimation()
{
  Serial.println("Game Starting); // animating the LCD
  lcd.setCursor(1,0);
  lcd.print("Get Ready.   );
  lcd.setCursor(1,1);
  lcd.print("  * * * * * *   ");
}

void randomLED()
{
  if (activeLEDs > -1)  // if the LED has been on for too long, end game
  {
    if ((millis() - ledOn) > LEDDelay) 
    {
      end();
    }
    return;
  }
  delay(random(500, 3000));
  LEDsActive = random(0, TotalLEDs); // picking a random LED
  digitalWrite(LEDs[LEDsActive], HIGH);
  ledOn = millis();
  if (ledDelay > (MIN_DELAY + DELAY_STEP)) 
  {
    leddelay -= DELAY_STEP;
  }
}

void checkTarget()
{
  if (LEDsActive == -1) {
    return;
  }
  for (int i = 0; i < TotalLEDs; i++) {
    if (digitalRead(LDRs[i]) == HIGH) { // checking each LDR to see if its been hit
      continue;
    }

    if ((LEDsActive == i)) { // checking if the LDR that has been hit corresponds with the
      digitalWrite(LEDs[LEDsActive], LOW); // LED thats been turn on
      LEDsActive = -1;
      score++; // increase score by 1 if true
      lcd.setCursor(1,1);
      lcd.print("                ");
      lcd.setCursor(1,0);
      lcd.print("   Score: ");
      lcd.print(score);
      lcd.print("    ");
      return;
   }
}

void end()
{   
    gameRunning = false;
    Serial.println("Game Over");
    lcd.setCursor(1,0);
    lcd.print("   Game Over    "); // displaying game over
    lcd.setCursor(1,1);
    lcd.print("Score: ");// and final score on LCD
    lcd.print(score);
    lcd.print("      ");
    Serial.println("Score: " + String(score));
    for(int k = 0;k < TotalLEDs; k++) // turning off each LED
    {
      digitalWrite(LEDs[k], LOW);
    }
}


void loop()
{
  while(gameRunning == true)
  {
    randomLED();// if the game has started, go to randomLED() function
    checkTarget(); //and go to checkTarget() function
  }
}

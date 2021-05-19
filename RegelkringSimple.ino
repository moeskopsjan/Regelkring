/* Jan Moeskops - mei 2021
 *  Dit project is een eenvoudige regelkring
 *  Als temp.sensor gebruiken we hier DS18b20 op Digi pin 2
 *  Er is ook een LCD-I2C aangesloten (LCD1602)
 *  
 *  Volgende libraries zijn nodig : 
 *  LiquidCrystal van Frank de Brabander
 *  DallasTemperature van Miles Burton, Tim Newsome ....
 *  
 *  De waarde wordt getoond op LCD
 *  Een leerling houdt de LCD in het oog en 
 *  - warmt (met de hand) de temp.sensor op als de text AAN verschijnt
 *  - koelt (met water) de temp.sensor op als de text AAN verschijnt
 *  
 *  In de seriële plotter verschijnt een live grafiek
 *  
 */

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);


int gewenst = 23;
int gemeten;
int verwarming = 0;
int mintemp = 22;
int maxtemp = 25;


/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  lcd.begin();
  Serial.begin(9600);
  //Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  //Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  //Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  //Serial.print("Temperature for the device 1 (index 0) is: ");
  gemeten = sensors.getTempCByIndex(0);
  Serial.print(gewenst);
  Serial.print(",");
  Serial.print(sensors.getTempCByIndex(0));  
  Serial.print(",");
  Serial.println(verwarming);
  lcd.setCursor(0,0);
  lcd.print("Temp.: ");
  lcd.print(sensors.getTempCByIndex(0));
  lcd.setCursor(0,1);
  lcd.print("Gewenst: ");
  lcd.print(gewenst);

  if(gemeten < maxtemp)
    {
    //digitalWrite(pinChauffage, HIGH);
    digitalWrite(13,HIGH);
    verwarming = 20;   // om dit zichtbaar op serial plotter te kunnen zien
    lcd.setCursor(13,1);
    lcd.print("AAN");
    }
    else if(gemeten > mintemp)
    {
    //digitalWrite(pinChauffage, LOW);
    digitalWrite(13,LOW);
    verwarming = 0;   // om dit zichtbaar op serial plotter te kunnen zien
    lcd.setCursor(13,1);
    lcd.print("UIT");
    }



  
}

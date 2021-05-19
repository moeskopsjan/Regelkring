# Regelkring
Dit project is een eenvoudige regelkring, die een live een grafiek toon in de seriële plotter van Arduino IDE

Als temp.sensor gebruiken we hier DS18b20 op Digi pin 2. Er is ook een LCD-I2C aangesloten (LCD1602)

Volgende libraries zijn nodig : 
 *  LiquidCrystal van Frank de Brabander
 *  DallasTemperature van Miles Burton, Tim Newsome ....
 
De waarde wordt getoond op LCD en een leerling houdt de LCD goed in het oog en 
 * warmt (met de hand) de temp.sensor op als de text AAN verschijnt
 * koelt (met water) de temp.sensor op als de text AAN verschijnt
 
 In de seriële plotter verschijnt een live grafiek

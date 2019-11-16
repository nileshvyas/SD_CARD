/*
 *  Arduino SD Card Tutorial Example
 *  
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 */
#include <SD.h>
#include <SPI.h>
File myFile;
int pinCS = 53; // Pin 10 on Arduino Uno
void setup() 
{
    
    Serial.begin(9600);
    pinMode(pinCS, OUTPUT);
  
    // SD Card Initialization
    if (SD.begin())
    {
        Serial.println("SD card is ready to use.");
    } 
    else
    {
        Serial.println("SD card initialization failed");
        return;
    }
  
    // Create/Open file 
    myFile = SD.open("nilesh1.csv", FILE_WRITE);
  
    // if the file opened okay, write to it:
    if (myFile) 
    {
        Serial.println("Writing to file...");
        // Write to file
        myFile.println("Sr_No,Time,Temp");
        myFile.close(); // close the file
        Serial.println("Done.");
    }
    // if the file didn't open, print an error:
    else 
    {
        Serial.println("error opening test.txt");
    }
    // Reading the file
    myFile = SD.open("nilesh1.csv");
    if (myFile) 
    {
        Serial.println("Read:");
        // Reading the whole file
        while (myFile.available()) 
        {
            Serial.write(myFile.read());
        }
        myFile.close();
    }
    else 
    {
        Serial.println("error opening test.txt");
    }
   
}
void loop() 
{
  // empty
}

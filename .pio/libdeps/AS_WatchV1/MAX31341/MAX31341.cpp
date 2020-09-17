#include "MAX31341.h"
#include <Arduino.h>
#include <Wire.h>

uint8_t DeviceAdress;
String requestBit; 


MAX31341::MAX31341(bool AD0 = true) 
{
    if (AD0) 
    {
        DeviceAdress = 0xD2;
    } 

    else 
    {
        DeviceAdress = 0xD4;
    }
    Wire.begin(DeviceAdress);
}

String MAX31341::GetSeconds()
{
    Wire.requestFrom(Seconds, 7);
    while(Wire.available()) 
        {
            char requestByte = Wire.read();   
            requestBit += requestByte;        
        }
    return requestBit;
}

void MAX31341::SetSeconds(int sec)
{
    Wire.beginTransmission(DeviceAdress);
    Wire.write(Seconds);
    Wire.write(sec);
    Wire.endTransmission();
}

String MAX31341::GetMinutes()
{
    Wire.requestFrom(Minutes, 7);
    while(Wire.available()) 
        {
            char requestByte = Wire.read();   
            requestBit += requestByte;        
        }
    return requestBit;
}

void MAX31341::SetMinutes(int min)
{
    Wire.beginTransmission(DeviceAdress);
    Wire.write(Minutes);
    Wire.write(min);
    Wire.endTransmission();
}

String MAX31341::GetHours()
{
    Wire.requestFrom(Hours, 7);
    while(Wire.available()) 
        {
            char requestByte = Wire.read();   
            requestBit += requestByte;        
        }
    return requestBit;
}

void MAX31341::SetHours(int H)
{
    Wire.beginTransmission(DeviceAdress);
    Wire.write(Hours);
    Wire.write(H);
    Wire.endTransmission();
}

String MAX31341::GetDay()
{
    Wire.requestFrom(Day, 7);
    while(Wire.available()) 
        {
            char requestByte = Wire.read();   
            requestBit += requestByte;        
        }
    return requestBit;
}

void MAX31341::SetDay(int D)
{
    Wire.beginTransmission(DeviceAdress);
    Wire.write(Day);
    Wire.write(D);
    Wire.endTransmission();
}

String MAX31341::GetMonth()
{
    Wire.requestFrom(Month, 7);
    while(Wire.available()) 
        {
            char requestByte = Wire.read();   
            requestBit += requestByte;        
        }
    return requestBit;
}

void MAX31341::SetMonth(int D)
{
    Wire.beginTransmission(DeviceAdress);
    Wire.write(Day);
    Wire.write(D);
    Wire.endTransmission();
}
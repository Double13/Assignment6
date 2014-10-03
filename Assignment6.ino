int led[6] = { 3, 5, 6, 9, 10, 11}; // Assign the pins for the leds
int fadeChannel = 0;  // fade channel input
int fade, i;

 
void setup()
{
for (i = 0; i < 6; i++)  // Tell the arduino that the leds are digital outputs
  pinMode(led[i], OUTPUT);
}
 
void loop()
{
fade = analogRead(fadeChannel);  // read the fade channel
fade = fade / 170;    // adjusts the sensitivity  

 
  if (fade == 0)  // if the potentiometer is 0 then turn off all leds
   {
   for(i = 0; i < 6; i++)
     {
     digitalWrite(led[i], LOW);
     }
  }
 
  else
  {
   for (i = 0; i < fade; i++) // turn on the leds up to the potentiometer value
    {
     digitalWrite(led[i], HIGH);
    }
 
    for(i = i; i < 6; i++)  // turn off the leds above the potentiometer value
     {
      digitalWrite(led[i], LOW);
     }
  }
}

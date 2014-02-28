
/*
 * LilyPad tutorial: color (RGB LEDs) + Switch
 *
 * Uses a LilyPad RGB LED module to play with
  * dynamic colored light. See this web color chart
  * for the (Red,Green,Blue) values of different colors:
 * http://www.visibone.com/colorlab/
 */
 

int redPin = 11;	// R petal on RGB LED module connected to digital pin 11
int greenPin = 9;	// G petal on RGB LED module connected to digital pin 9
int bluePin = 10;	// B petal on RGB LED module connected to digital pin 10

int switchPin = 5;	// switch connected to digital pin 5
int switchValue;	// a variable to keep track of when switch is pressed
 	 
 	 
void setup()	 
{	                                                   
        
         pinMode(switchPin, INPUT);	// sets the switchPin to be an input
         digitalWrite(switchPin, HIGH);	// sets the default (unpressed) state of switchPin to HIGH
        
         pinMode(redPin, OUTPUT);	// sets the redPin to be an output
         pinMode(greenPin, OUTPUT);	// sets the greenPin to be an output
         pinMode(bluePin, OUTPUT);	// sets the bluePin to be an output
}	 
 	 
void loop()	// run over and over again
{	 
 
  switchValue = digitalRead(switchPin);	// check to see if the switch is pressed
          if (switchValue == LOW) {	// if the switch is pressed then,
                    // Basic colors:
                    color(255, 0, 0);	// turn the RGB LED red
                    delay(1000);	// delay for 1 second
                    color(0,255, 0);	// turn the RGB LED green
                    delay(1000);	// delay for 1 second
                    color(0, 0, 255);	// turn the RGB LED blue
                    delay(1000);	// delay for 1 second
 
                    // Example blended colors:
                    color(255,255,0);	// turn the RGB LED yellow
                    delay(1000);	// delay for 1 second
                    color(255,255,255);	// turn the RGB LED white
                    delay(1000);	// delay for 1 second
                    color(128,0,255);	// turn the RGB LED purple
                    delay(1000);	// delay for 1 second                   
          }	  
          else {	// otherwise,
                    color(0,0,0);	// turn the RGB LED off
                    delay(1000);	// delay for 1 second	
          }
} 
          
 	 
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{	 
          analogWrite(redPin, 255-red);	 
          analogWrite(bluePin, 255-blue);
          analogWrite(greenPin, 255-green);
}	 
 



/*
 * Jen's LilyPad tutorial: color (RGB LEDs) + 3 Controllers
 * switch turns on RED
 * light turns on GREEN
 * cold sensor turns on BLUE
 * To play with
 * dynamic colored light. See this web color chart
 * for the (Red,Green,Blue) values of different colors:
 * http://www.visibone.com/colorlab/
 */
 

int redPin = 11;	// R petal on RGB LED module connected to digital pin 11
int greenPin = 9;	// G petal on RGB LED module connected to digital pin 9
int bluePin = 10;	// B petal on RGB LED module connected to digital pin 10

int redVal = 0;            // variable to store Red
int greenVal = 0;           // variable to store Green
int blueVal = 0;            // variable to store Blue 


int switchPin = 5;	// switch connected to digital pin 5
int switchValue;	// a variable to keep track of when switch is pressed

int tempPin = A2;	// tempSensor connected to analog pin A2	
int tempValue;	        // a variable to keep track of temp

int lightPin = A3;        //lightSensor connected to analog pin A3
int lightValue;	        // a variable to keep track of light

	 
void setup()	 
{	                                                   
         //switch
         pinMode(switchPin, INPUT);	// sets the switchPin to be an input
         digitalWrite(switchPin, HIGH);	// sets the default (unpressed) state of switchPin to HIGH
        
         //light
         pinMode(lightPin, INPUT);	// sets the lightPin to be an input
        
         //temp
         pinMode(tempPin, INPUT);       // set the tempPin as an input
         
         //RGB
         pinMode(redPin, OUTPUT);	// sets the redPin to be an output
         pinMode(greenPin, OUTPUT);	// sets the greenPin to be an output
         pinMode(bluePin, OUTPUT);	// sets the bluePin to be an output
         
         Serial.begin(9600);  // We'll output some information over serial
}	 
 	 
void loop()	// run over and over again
{	 
  
  //if switch is pressed turn RGB LED blue on
  switchValue = digitalRead(switchPin);	// check to see if the switch is pressed
          if (switchValue == LOW) {	// if the switch is pressed then,
                    // Basic colors:
                    blueVal=255;          // turn the RGB LED blue on
                    color(redVal, greenVal, blueVal);	
            } 	 
          else {
                 blueVal=0;               // turn the RGB LED blue off
                 color(redVal, greenVal, blueVal); 
               } 
         
 
 // //if its hot turn RGB LED red on    
  // tempValue = analogRead(tempPin);  
        //  if (analogRead(tempPin)  > 160) {	// if its hot go blue                   
       //             redVal=255;// turn the RGB LED blue
       //             color(redVal, greenVal, blueVal);	
      //               }	  
      //      else {
      //           redVal=0; 
     //            color(redVal, greenVal, blueVal); 
     //          } 
    
    
   // if its dark turn the RGB LED green on
   lightValue = analogRead(lightPin);	
   if(analogRead(lightPin) < 100){    // if its dark 
                    greenVal=255;     // turn the RGB LED green on
                    color(redVal, greenVal, blueVal);	
                     }	  
        else {
                greenVal=0;         // turn the RGB LED green off
                 color(redVal, greenVal, blueVal); 
               }    
   
                    //// Example blended colors:
                    //color(255,255,0);	// turn the RGB LED yellow
                    //delay(1000);	// delay for 1 second
                    //color(255,255,255);	// turn the RGB LED white
                    //delay(1000);	// delay for 1 second
                    //color(128,0,255);	// turn the RGB LED purple
                    //delay(1000);	// delay for 1 second       

    /* from here on down, we'll just print out the status of every input */
    Serial.print("Switch=");
    Serial.print(digitalRead(switchPin));

    Serial.print("  Temp=");
    Serial.print(analogRead(tempPin));

    Serial.print("  Light=");
    Serial.println(analogRead(lightPin));
} 
          
 	 
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{	 
          analogWrite(redPin, 255-red);	 
          analogWrite(bluePin, 255-blue);
          analogWrite(greenPin, 255-green);
}	 
 


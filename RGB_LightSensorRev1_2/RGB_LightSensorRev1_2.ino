
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

int lightPin = A3;        // lightSensor connected to analog pin A3

int lightValue = 0;	  //   a variable to keep track of light
double light = 0.0;    // filter variable for light
double alphaL = 0.2;   // filter coeff for light

void setup()	 
{	                                                   
         //light
         pinMode(lightPin, INPUT);	// sets the lightPin to be an input

         //RGB
         pinMode(redPin, OUTPUT);	// sets the redPin to be an output
         pinMode(greenPin, OUTPUT);	// sets the greenPin to be an output
         pinMode(bluePin, OUTPUT);	// sets the bluePin to be an output
         
         Serial.begin(9600);  // We'll output some information over serial
}	 
 	 
void loop()	// run over and over again
{	  
   // if its dark turn the RGB LED on
   lightValue = analogRead(lightPin);
   // Filter :: lightNew = (lightRaw - lightOld)*alpha + lightOld;
   light = ((lightValue - light)*alphaL) + light; // Filters the input to light
   if(light < 25){    // if its dark THRESHOLD = 25
                    greenVal=255; redVal = 255; blueVal = 255;    // turn the RGB LED on
                    color(redVal, greenVal, blueVal);
                     }	  
        else {
                greenVal=0; blueVal = 0; redVal = 0; // turn the RGB LED off
                 color(redVal, greenVal, blueVal); 
               }    
               
    /* from here on down, we'll just print out the status of light */
    Serial.print("Light=");
    Serial.println(light);
} 
          
 	 
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function
{	 
          analogWrite(redPin, 255-red);	 
          analogWrite(bluePin, 255-blue);
          analogWrite(greenPin, 255-green);
}	 
 


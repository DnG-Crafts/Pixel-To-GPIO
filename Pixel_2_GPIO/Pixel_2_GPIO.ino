
//----PWM pins
int pin_red = 9;
int pin_blue = 10;
int pin_green = 11;

//-----relay pins
int relay_red = 14;
int relay_green = 15;
int relay_blue = 16;
int relay_white = 17;

//-- brightness threshold
int rgb_th = 80;
int wht_th = 95;

int readRGB(int pin)
{
  unsigned long H = pulseIn(pin, HIGH, 2000);
  unsigned long L = pulseIn(pin, LOW, 2000);
  if (H == 0 || L == 0){return  digitalRead(pin) ? 100 : 0;}
  return (100 * H) / (H + L);
}


void setup() {
  //Serial.begin(115200);
  pinMode(pin_red, INPUT_PULLUP); 
  pinMode(pin_green, INPUT_PULLUP);
  pinMode(pin_blue, INPUT_PULLUP); 
  pinMode(relay_red, OUTPUT);
  pinMode(relay_green, OUTPUT);
  pinMode(relay_blue, OUTPUT);
  pinMode(relay_white, OUTPUT);
}


void loop() {
  int RED = readRGB(pin_red);
  int GREEN = readRGB(pin_blue);
  int BLUE = readRGB(pin_green);

/*
//-------------------- off channel-------------------------------
// may mess with latched relays on blanking signals
  if (RED == 100 && GREEN == 100 && BLUE == 100) 
  {
     //Serial.println("off");
     digitalWrite(relay_red, LOW);
     digitalWrite(relay_green, LOW);
     digitalWrite(relay_blue, LOW);
     digitalWrite(relay_white, LOW); 
     exit;
  }
*/

/*
//-------------------- white channel-------------------------------
// can be used as a 4th channel by detecting the state of all 3 color channels
  if (RED < 100 && GREEN < 100 && BLUE < 100 && RED > wht_th && GREEN > wht_th && BLUE > wht_th) 
  {
    //Serial.println("white ch1");
    digitalWrite(relay_white, LOW);
    exit;
  }
  else if (RED < 100 && GREEN < 100 && BLUE < 100) 
  {
    //Serial.println("white ch2");
    digitalWrite(relay_white, HIGH);
    exit;
  }
*/


//-------------------- red channel-------------------------------
  if (RED < 100 && RED > rgb_th) 
  {
    // Serial.println("red ch1");
     digitalWrite(relay_red, LOW);
  }
  
   else if (RED < 100) 
  {
    // Serial.println("red ch2");
     digitalWrite(relay_red, HIGH);
  }


//-------------------- green channel-------------------------------
  if (GREEN < 100 && GREEN > rgb_th) 
  {
    // Serial.println("green ch1");
     digitalWrite(relay_green, LOW);
  }
  else if (GREEN < 100) 
  {
    // Serial.println("green ch2");
     digitalWrite(relay_green, HIGH);
  }


//-------------------- blue channel-------------------------------
  if (BLUE < 100 && BLUE > rgb_th) 
  {
   //  Serial.println("blue ch1");
     digitalWrite(relay_blue, LOW);
  }
  else if (BLUE < 100) 
  {
    // Serial.println("blue ch2");
     digitalWrite(relay_blue, HIGH);
  }

}

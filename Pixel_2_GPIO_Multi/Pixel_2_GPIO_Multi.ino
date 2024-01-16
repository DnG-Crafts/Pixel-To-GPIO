
//-- pwm pins
int pin_red1 = 12;
int pin_blue1 = 11;
int pin_green1 = 10;
int pin_red2 = 9;
int pin_blue2 = 8;
int pin_green2 = 7;
int pin_red3 = 6;
int pin_blue3 = 5;
int pin_green3 = 4;

//-- relay pins
int relay_red1 = 14;
int relay_green1 = 15;
int relay_blue1 = 16;
int relay_red2 = 17;
int relay_green2 = 18;
int relay_blue2 = 19;
int relay_red3 = 3;
int relay_green3 = 2;
int relay_blue3 = 13;

//-- brightness threshold
int rgb_th = 80;




int readRGB(int pin)
{
  unsigned long H = pulseIn(pin, HIGH, 2000);
  unsigned long L = pulseIn(pin, LOW, 2000);
  if (H == 0 || L == 0){return  digitalRead(pin) ? 100 : 0;}
  return (100 * H) / (H + L);
}


void setup() {
  //Serial.begin(115200);
  pinMode(pin_red1, INPUT_PULLUP); 
  pinMode(pin_green1, INPUT_PULLUP);
  pinMode(pin_blue1, INPUT_PULLUP); 
  pinMode(pin_red2, INPUT_PULLUP); 
  pinMode(pin_green2, INPUT_PULLUP);
  pinMode(pin_blue2, INPUT_PULLUP); 
  pinMode(pin_red3, INPUT_PULLUP); 
  pinMode(pin_green3, INPUT_PULLUP);
  pinMode(pin_blue3, INPUT_PULLUP); 
  pinMode(relay_red1, OUTPUT);
  pinMode(relay_green1, OUTPUT);
  pinMode(relay_blue1, OUTPUT);
  pinMode(relay_red2, OUTPUT);
  pinMode(relay_green2, OUTPUT);
  pinMode(relay_blue2, OUTPUT);
  pinMode(relay_red3, OUTPUT);
  pinMode(relay_green3, OUTPUT);
  pinMode(relay_blue3, OUTPUT);
}


void loop() {
  int RED1 = readRGB(pin_red1);
  int GREEN1 = readRGB(pin_blue1);
  int BLUE1 = readRGB(pin_green1);
  
  int RED2 = readRGB(pin_red2);
  int GREEN2 = readRGB(pin_blue2);
  int BLUE2 = readRGB(pin_green2);
  
  int RED3 = readRGB(pin_red3);
  int GREEN3 = readRGB(pin_blue3);
  int BLUE3 = readRGB(pin_green3);


  


/*
//-------------------- pixel off channel-------------------------------
// may mess with latched relays on blanking signals
  if (RED1 == 100 && GREEN1 == 100 && BLUE1 == 100) 
  {
     //Serial.println("all off 1");
     digitalWrite(relay_red1, LOW);
     digitalWrite(relay_green1, LOW);
     digitalWrite(relay_blue1, LOW); 
  }

  if (RED2 == 100 && GREEN2 == 100 && BLUE2 == 100) 
  {
     //Serial.println("all off 2");
     digitalWrite(relay_red2, LOW);
     digitalWrite(relay_green2, LOW);
     digitalWrite(relay_blue2, LOW);
  }

  if (RED3 == 100 && GREEN3 == 100 && BLUE3 == 100) 
  {
     //Serial.println("all off 3");
     digitalWrite(relay_red3, LOW);
     digitalWrite(relay_green3, LOW);
     digitalWrite(relay_blue3, LOW);   
  }
*/



//-------------------- red channel1-------------------------------
  if (RED1 < 100 && RED1 > rgb_th) 
  {
    //Serial.println("red1 ch1");
     digitalWrite(relay_red1, LOW);
  }
  
   else if (RED1 < 100) 
  {
    //Serial.println("red1 ch2");
     digitalWrite(relay_red1, HIGH);
  }


//-------------------- green channel1-------------------------------
  if (GREEN1 < 100 && GREEN1 > rgb_th) 
  {
    //Serial.println("green1 ch1");
     digitalWrite(relay_green1, LOW);
  }
  else if (GREEN1 < 100) 
  {
    //Serial.println("green1 ch2");
     digitalWrite(relay_green1, HIGH);
  }


//-------------------- blue channel1-------------------------------
  if (BLUE1 < 100 && BLUE1 > rgb_th) 
  {
     //Serial.println("blue1 ch1");
     digitalWrite(relay_blue1, LOW);
  }
  else if (BLUE1 < 100) 
  {
    //Serial.println("blue1 ch2");
     digitalWrite(relay_blue1, HIGH);
  }




//-------------------- red channel2-------------------------------
  if (RED2 < 100 && RED2 > rgb_th) 
  {
    //Serial.println("red2 ch1");
     digitalWrite(relay_red2, LOW);
  }
  
   else if (RED2 < 100) 
  {
    //Serial.println("red2 ch2");
     digitalWrite(relay_red2, HIGH);
  }


//-------------------- green channel2-------------------------------
  if (GREEN2 < 100 && GREEN2 > rgb_th) 
  {
    //Serial.println("green2 ch1");
     digitalWrite(relay_green2, LOW);
  }
  else if (GREEN2 < 100) 
  {
    //Serial.println("green2 ch2");
     digitalWrite(relay_green2, HIGH);
  }


//-------------------- blue channel2-------------------------------
  if (BLUE2 < 100 && BLUE2 > rgb_th) 
  {
     //Serial.println("blue2 ch1");
     digitalWrite(relay_blue2, LOW);
  }
  else if (BLUE2 < 100) 
  {
    //Serial.println("blue2 ch2");
     digitalWrite(relay_blue2, HIGH);
  }




//-------------------- red channel3-------------------------------
  if (RED3 < 100 && RED3 > rgb_th) 
  {
     //Serial.println("red3 ch1");
     digitalWrite(relay_red3, LOW);
  }
  
   else if (RED3 < 100) 
  {
     //Serial.println("red3 ch2");
     digitalWrite(relay_red3, HIGH);
  }


//-------------------- green channel3-------------------------------
  if (GREEN3 < 100 && GREEN3 > rgb_th) 
  {
     //Serial.println("green3 ch1");
     digitalWrite(relay_green3, LOW);
  }
  else if (GREEN3 < 100) 
  {
     //Serial.println("green3 ch2");
     digitalWrite(relay_green3, HIGH);
  }


//-------------------- blue channel3-------------------------------
  if (BLUE3 < 100 && BLUE3 > rgb_th) 
  {
     //Serial.println("blue3 ch1");
     digitalWrite(relay_blue3, LOW);
  }
  else if (BLUE3 < 100) 
  {
     //Serial.println("blue3 ch2");
     digitalWrite(relay_blue3, HIGH);
  }

}

const int buttonPin = 8;    
const int ledPin = 13;      
const int buzzer = 14;

int dotLed = 10;
int dashLed = 11;

int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=9;
int h=12;

int ledState = HIGH;         
int buttonState = LOW;             
int lastButtonState = LOW;  
int doesitwork = LOW;  

 // depending on your skill and how fast your fingers are you can change this value to make typing a message faster or slower
long signal_length = 0;
long pause = 0;

String morse = "";
String dash = "-";
String dot = ".";

boolean cheker = false;
boolean linecheker = false;

long lastDebounceTime = 0;  
long debounceDelay = 50; 

void setup()
{
  Serial.begin(9600);
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(dotLed, OUTPUT);
  pinMode(dashLed, OUTPUT);
  
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);

  while(!digitalRead(buttonPin))
    ;
  
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState && lastButtonState)       // basic state machine depending on the state of the signal from the button
  {
    ++signal_length;       
    
  }
  else if(!buttonState && lastButtonState)          //this part of the code happens when the button is released and it send either * or - into the buffer
  {
     
     if (signal_length<150)
     {
       morse =  morse + dot;
       Serial.println(".");
       digitalWrite(dotLed, LOW);
       delay(20);
       digitalWrite(dotLed, HIGH);
       digitalWrite(dashLed, LOW);
     } 
      else if (signal_length>=150 && signal_length<800)
      {
        morse = morse +  dash;
        Serial.println("-");
        digitalWrite(dashLed, LOW);
        delay(20);
        digitalWrite(dashLed, HIGH);
        digitalWrite(dotLed, LOW);
      }
    
    signal_length=0; 
    digitalWrite(13, LOW); 
    noTone(buzzer); 
  }
  else if(buttonState && !lastButtonState)          // this part happens when the button is pressed and its use to reset several values
  {
    pause=0;
    digitalWrite(13, HIGH);  
    cheker = true;
    linecheker = true;
  }
  else if (!buttonState && !lastButtonState)
  {  
    ++pause;
    if (( pause>1200 ) && (cheker))
    { 
      printaj(morse);
      cheker = false;
      morse = "";
    }
    if ((pause>1200) && (linecheker))
    {
      Serial.println();
      linecheker = false;
      digitalWrite(10, LOW);    
      digitalWrite(11, LOW);
    }
  }
  lastButtonState=buttonState;
  delay(1);
}
void printaj(String prevodilac)   //ugly part of the code but it works fine
{                                 //compare morse string to known morse values and print out the letter or a number 
                                  //the code is written based on the international morse code, one thing i changed is that insted of typing a special string to end the line it happens with enough delay  

    if (prevodilac==".-")
    showa();
  else if (prevodilac=="-...")  
    showb();
  else if (prevodilac=="-.-.")  
    showc();
  else if (prevodilac=="-..")  
    showd();
  else if (prevodilac==".")  
    showe();
  else if (prevodilac=="..-.")  
    showf;
  else if (prevodilac=="--.")  
    showg();
  else if (prevodilac=="....")  
    showh();
  else if (prevodilac=="..")  
    showi();
  else if (prevodilac==".---")  
    showj();
  else if (prevodilac=="-.-")  
    showk();
  else if (prevodilac==".-..")  
    showl();
  else if (prevodilac=="--")  
    showm();
  else if (prevodilac=="-.")  
    shown();
  else if (prevodilac=="---")  
    showo();
  else if (prevodilac==".--.")  
    showp();
  else if (prevodilac=="--.-")  
    showq();
  else if (prevodilac==".-.")  
    showr();
  else if (prevodilac=="...")  
    shows();
  else if (prevodilac=="-")  
    showt();
  else if (prevodilac=="..-")  
    showu;
  else if (prevodilac=="...-")  
    showv();
  else if (prevodilac==".--")  
    showw();
  else if (prevodilac=="-..-")  
    showx();
  else if (prevodilac=="-.--")  
    showy();
  else if (prevodilac=="--..")  
    showz();

  else if (prevodilac==".----")  
    show1();
  else if (prevodilac=="..---")  
    show2();
  else if (prevodilac=="...--")  
    show3();
  else if (prevodilac=="....-")  
    show4();
  else if (prevodilac==".....")  
    show5();
  else if (prevodilac=="-....")
    show6();
  else if (prevodilac=="--...")  
    show7();
  else if (prevodilac=="---..")  
    show8();
  else if (prevodilac=="----.")  
    show9();
  else if (prevodilac=="-----")  
    show0();
  
  Serial.print(" ");
    
  prevodilac="";
}
  
void showa()
{
  Serial.println("A");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showb()
{
  Serial.println("B");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showc()
{
  Serial.println("C");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}
void showd()
{
  Serial.println("D");
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}
void showe()
{
  Serial.println("E");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showf()
{
  Serial.println("F");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);//LOW
  digitalWrite(c,LOW);//LOW
  digitalWrite(d,LOW);//LOW
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showg()
{
  Serial.println("G");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);//LOW
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);//LOW
}
void showh()
{
  Serial.println("H");
  digitalWrite(a,LOW);//LOW
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);//LOW
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showi()
{
  Serial.println("I");
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
void showj()
{
  Serial.println("J");
  digitalWrite(a,LOW);//LOW
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);//LOW
  digitalWrite(g,LOW);//LOW
}

void showk()
{
  Serial.println("K");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void showl()
{
  Serial.println("L");
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}

void showm()
{
  Serial.println("M");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void shown()
{
  Serial.println("N");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void showo()
{  
  Serial.println("O");
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}
void showp()
{
  Serial.println("P");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);//LOW
  digitalWrite(d,LOW);//LOW
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showq()
{
  Serial.println("Q");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showr()
{  
  Serial.println("R");
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}
void shows()
{
  Serial.println("S");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);//LOW
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);//LOW
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showt()
{
  Serial.println("T");
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showu()
{
  Serial.println("U");
  digitalWrite(a,LOW);//LOW
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}
void showv()
{
  Serial.println("V");
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}
void showw()
{
  Serial.println("W");
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showx()
{
  Serial.println("X");
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showy()
{
  Serial.println("Y");
  digitalWrite(a,LOW);//LOW
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);//LOW
  digitalWrite(e,LOW);//LOW
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void showz()
{
  Serial.println("Z");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);//LOW
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);//LOW
  digitalWrite(g,HIGH);
}
void show1()
{
  Serial.println("1");
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
void show2()
{
  Serial.println("2");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}
void show3()
{
  Serial.println("3");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}
void show4()
{
  Serial.println("4");
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void show5()
{
  Serial.println("5");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void show6()
{
  Serial.println("6");
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void show7()
{
  Serial.println("7");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
void show8()
{
  Serial.println("8");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void show9()
{
  Serial.println("9");
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void show0()
{
  Serial.println("0");
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}

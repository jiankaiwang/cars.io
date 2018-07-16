int  lt;
int  rg;
int  cn;
int  status;
int cp;

void forward() {
  digitalWrite(10,HIGH);
  analogWrite(5,250);
  digitalWrite(11,HIGH);
  analogWrite(6,250);
}

void left() {
  digitalWrite(10,HIGH);
  analogWrite(5,250);
  digitalWrite(11,LOW);
  analogWrite(6,0);
}

void right() {
  digitalWrite(10,LOW);
  analogWrite(5,0);
  digitalWrite(11,HIGH);
  analogWrite(6,250);
}

void stop() {
  analogWrite(5,0);
  analogWrite(6,0);
}

void setup()
{
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(12, INPUT);
  pinMode(8, INPUT);
    lt = '0';
  rg = '0';
  cn = '0';
  status = '0';

  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);

  cp = 0;
}


void loop()
{
    lt = digitalRead(7);
    rg = digitalRead(12);
    cn = digitalRead(8);
    status = lt * 4 + (cn * 2 + rg);
    Serial.println(status);
    
     switch (status) {
      case 0:
      case 2:
      case 5:
        forward();
        cp = 0;
        break;
      case 1:
      case 3:
        right();
        cp = 0;
        break;
      case 4:
      case 6:
        left();
        cp = 0;
        break;
       default:
       case 7:
        cp += 1;
        break;
     }

     if(cp > 10) {
      stop();
     }
}

int lock = 2; // Pin declarations
int unlock = 3;
int starter = 4;
int parkLight = 5;
int headLight = 6;
int ign1 = 7;
int ign2 = 8;
String data;

String lockStatus;
String parklightStatus;
String headlightStatus;
String engineStatus;
String ign1Status;
String ign2Status;

void setup() {
  pinMode(lock, OUTPUT);
  pinMode(unlock, OUTPUT);
  pinMode(starter, OUTPUT);
  pinMode(parkLight, OUTPUT);
  pinMode(headLight, OUTPUT);
  pinMode(ign1, OUTPUT);
  pinMode(ign2, OUTPUT);

  digitalWrite(lock, HIGH);
  digitalWrite(unlock, HIGH);
  digitalWrite(starter, HIGH);
  digitalWrite(parkLight, HIGH);
  digitalWrite(headLight, HIGH);
  digitalWrite(ign1, HIGH);
  digitalWrite(ign2, HIGH);


  lockStatus="true";
  parklightStatus="false";
  headlightStatus="false";
  engineStatus = "false";
  ign1Status = "false";
  ign2Status = "false";
  
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    data = Serial.readString();
    //Serial.println(data);
  }

    if(data == "GETCARSTATUS")
    {
      String stat =  "{\"lockStatus\":\""+lockStatus+"\",\"parklightStatus\":\""+parklightStatus+"\",\"headlightStatus\":\""+headlightStatus+"\",\"engineStatus\":\""+engineStatus+"\",\"ign1Status\":\""+ign1Status+"\",\"ign2Status\":\""+ign2Status+"\"}";
      Serial.println(stat);
      data="";
    }

    if (data == "CMDLOCKANDCLOSEWINDOWS") 
    {
    digitalWrite(lock, LOW);
    digitalWrite(parkLight, LOW);
    delay(500);
    digitalWrite(parkLight, HIGH);
    delay(11000);
    Serial.println("CMDLOCKANDCLOSEWINDOWS");
    lockStatus = "true";
    digitalWrite(lock, HIGH);
    data="";
    }

    if (data == "CMDLOCK") 
    {
    digitalWrite(lock, LOW);
    digitalWrite(parkLight, LOW);
    Serial.println("CMDLOCK");
    delay(400);
    digitalWrite(parkLight, HIGH);
    delay(200);
    digitalWrite(parkLight, LOW);
    delay(400);
    digitalWrite(parkLight, HIGH);
    digitalWrite(lock, HIGH);
    lockStatus = "true";
    data="";
    }

    if (data == "CMDUNLOCK") 
    {
    digitalWrite(unlock, LOW);
    digitalWrite(parkLight, LOW);
    Serial.println("CMDUNLOCK");
    delay(500);
    digitalWrite(parkLight, HIGH);
    delay(500);
    digitalWrite(unlock, HIGH);
    lockStatus = "false";
    data="";
    }
  
    if (data == "CMDPARKLIGHTON") 
    {
    digitalWrite(parkLight, LOW);
    Serial.println("CMDPARKLIGHTON");
    parklightStatus="true";
    data="";
    }
  
    if (data == "CMDPARKLIGHTOFF") 
    {
    digitalWrite(parkLight, HIGH);
    Serial.println("CMDPARKLIGHTOFF");
    parklightStatus="false";
    data="";
    }
  
    if (data == "CMDHEADLIGHTON") 
    {
    digitalWrite(parkLight, LOW);
    digitalWrite(headLight, LOW);
    Serial.println("CMDHEADLIGHTON");
    headlightStatus="true";
    parklightStatus="true";
    data="";
    }
  
    if (data == "CMDHEADLIGHTOFF") 
    {
    digitalWrite(parkLight, HIGH);
    digitalWrite(headLight, HIGH);
    Serial.println("CMDPARKLIGHTOFF");
    headlightStatus="false";
    parklightStatus="false";
    data="";
    }

        if (data == "CMDIGN1ON") 
    {
    digitalWrite(ign1, LOW);
    Serial.println("CMDIGN1ON");
    ign1Status="true";
    data="";
    }

        if (data == "CMDIGN1OFF") 
    {
    digitalWrite(ign1, HIGH);
    Serial.println("CMDIGN1OFF");
    ign1Status="false";
    data="";
    }

        if (data == "CMDIGN2ON") 
    {
    digitalWrite(ign2, LOW);
    Serial.println("CMDIGN2ON");
    ign2Status="true";
    data="";
    }

        if (data == "CMDIGN2OFF") 
    {
    digitalWrite(ign2, HIGH);
    Serial.println("CMDIGN2OFF");
    ign2Status="false";
    data="";
    }

        if (data == "CMDIGNALLON") 
    {
    digitalWrite(ign1, LOW);
    digitalWrite(ign2, LOW);
    Serial.println("CMDIGNALLON");
    ign1Status="true";
    ign2Status="true";
    data="";
    }

        if (data == "CMDIGNALLOFF") 
    {
    digitalWrite(ign1, HIGH);
    digitalWrite(ign2, HIGH);
    Serial.println("CMDIGNALLOFF");
    ign1Status="false";
    ign2Status="false";
    engineStatus="false";
    data="";
    }

        if (data == "CMDSTARTENGINE")
    {
      if(ign1Status =="false" && ign2Status =="false")
      {
    digitalWrite(ign1, LOW);
    digitalWrite(ign2, LOW);
      }
    delay(1500);
    digitalWrite(starter, LOW);
    delay(1250);
    digitalWrite(starter, HIGH);
    Serial.println("CMDSTARTENGINE");
    engineStatus="true";
    ign1Status="true";
    ign2Status="true";
    data="";
    }

    
        if (data == "CMDEMERGENCY")
    {
    digitalWrite(starter, HIGH);
    digitalWrite(ign1, HIGH);
    digitalWrite(ign2, HIGH);
    Serial.println("CMDEMERGENCY");
    engineStatus="false";
    ign1Status="false";
    ign2Status="false";
    data="";
    }
    
}

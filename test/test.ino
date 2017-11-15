
#include <SoftwareSerial.h>
SoftwareSerial BTSerial = SoftwareSerial(10, 11); // RX | TX

char data[20];

  
void setup() {
  Serial.begin(115200);  //initial the Serial with 115200 speed
  pinMode(2,OUTPUT); //set port as OUTPUT
  pinMode(3,OUTPUT); //set port as OUTPUT
  pinMode(4,OUTPUT); //set port as OUTPUT
  pinMode(5,OUTPUT); //set port as OUTPUT
}

/**
 * clear the char array to receive the next values
 */
void emptyData(){
  for (int x=0;x<20;x++){
    data[x] = '\0';
  }
}

void retrieveDataRx() {
  emptyData();
  if(Serial.available()) {
    Serial.readBytes(data,20);  // retrieve the 20 characters max received
    Serial.println(data);
    
  }
}

/**
 * Compare the data with the expected value
 */
bool compareDataRx(const char * value){
  if (strcmp(data, value) == 0){
    Serial.println(value);
    return true;
  }
  return false;
}

void loop() {
  Serial.write(Serial.read());
  //retrieveDataRx();
}



//TODO: make this smarter
bool isTurnOn(){ return compareDataRx("turn on"); }
bool isTurnOff(){ return compareDataRx("turn off"); }
bool isOpenWindow(){ return compareDataRx("window on"); }
bool isCloseWindow(){ return compareDataRx("window off"); }
bool isOpenDoor(){ return compareDataRx("door on"); }
bool isCloseDoor(){ return compareDataRx("door off"); }
bool isAllOn(){ return compareDataRx("all on"); }
bool isAllOff(){ return compareDataRx("all off"); }

/*
 * Loop through all the available pins and set to HIGH
 */
void openAll(){
  for (int i=2;i<=5;i++){
    openPin(i);
  }
}

/*
 * Loop through all the available pins and set to LOW
 */
void closeAll(){
  for (int i=2;i<=5;i++){
    closePin(i);
  }
}


void openPin(const int pin){
    digitalWrite(pin, HIGH);   // sets the pin on
}

void closePin(const int pin){
    digitalWrite(pin, LOW);   // sets the pin off
}

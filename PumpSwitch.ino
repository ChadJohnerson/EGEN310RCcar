int pumpSwitch = 13;          //set pin 13 for logic to switch on and off
char data = 0;                //Variable for storing received data
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(pumpSwitch, OUTPUT);        //Sets digital pin 13 as output pin
}
void loop(){
  if(Serial.available() > 0){  // Send data only when you receive data:
    data = Serial.read();      //Read the incoming data 
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line for readability when debugging
    if(data == '1')            //Checks whether value of data is equal to 1 
      digitalWrite(pumpSwitch, HIGH);  //If value is 1 then pump turns ON
    else if(data == '0')       //Checks whether value of data is equal to 0
      digitalWrite(pumpSwitch, LOW);   //If value is 0 then pump turns OFF
  }                            

}


#include <Wire.h>

#define MD03_1    0x58
#define MD03_2    0x59
#define CMD_reg   0x00
#define SPEED_reg 0x02
#define ACC_reg   0x03 
 int joyFB = A1 ; //joystick forward and backward
 int joyLR = A2 ; //joystick left and right
 int valueFB = 0; //variable value forward backward
 int valueLR = 0; //variable value left right

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  pinMode(joyFB,INPUT);
  pinMode(joyLR,INPUT);
}


void loop()
{

  valueFB = analogRead(joyFB);
  valueLR = analogRead(joyLR);
  
  if ( valueFB < 600 and valueFB > 400 and valueLR >400 and  valueLR < 600){// staat stil
    Wire.beginTransmission(MD03_1); // transmit to md03 1
    Wire.write(CMD_reg);        // command byte
    Wire.write(0);              // full stop  motor 1
    Wire.endTransmission();    // stop transmitting
    Wire.beginTransmission(MD03_2); // transmit to md03 2
    Wire.write(CMD_reg);        // command byte
    Wire.write(0);              //  full stop motor 2 
    Wire.endTransmission();    // stop transmitting
    
  }
  else if (valueFB > 600 )    {            // rijd voorwaarst

    Wire.beginTransmission(MD03_1); 
    Wire.write(SPEED_reg);          
    Wire.write(128);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(SPEED_reg);          
    Wire.write(128);           
    Wire.endTransmission();

    Wire.beginTransmission(MD03_1); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(ACC_reg);         
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_1); 
    Wire.write(CMD_reg);        
    Wire.write(1);              // sets motor to forward
    Wire.endTransmission();    
    Wire.beginTransmission(MD03_2); 
    Wire.write(CMD_reg);        
    Wire.write(1);              // sets motor to forward
    Wire.endTransmission();   
  
      if(valueFB > 600 and valueLR > 600) {                                      // rijd link vooruit

          Wire.beginTransmission(MD03_1); 
          Wire.write(SPEED_reg);         
          Wire.write(128);             
          Wire.endTransmission();
          Wire.beginTransmission(MD03_2); 
          Wire.write(SPEED_reg);         
          Wire.write(64);             
          Wire.endTransmission();
          
          Wire.beginTransmission(MD03_1); 
          Wire.write(ACC_reg);          
          Wire.write(27);              
          Wire.endTransmission();
          Wire.beginTransmission(MD03_2);
          Wire.write(ACC_reg);         
          Wire.write(27);             
          Wire.endTransmission();
          Wire.beginTransmission(MD03_1); 
          Wire.write(CMD_reg);       
          Wire.write(1);              
          Wire.endTransmission();   
          Wire.beginTransmission(MD03_2); 
          Wire.write(CMD_reg);       
          Wire.write(1);             
          Wire.endTransmission();    
          
         }

        else if (valueFB > 600 and valueLR < 400)                                //rijd rechts vooruit
        {  
        Wire.beginTransmission(MD03_1); 
        Wire.write(SPEED_reg);          
        Wire.write(64);             
        Wire.endTransmission();
        Wire.beginTransmission(MD03_2); 
        Wire.write(SPEED_reg);          
        Wire.write(128);              
        Wire.endTransmission();
  
        Wire.beginTransmission(MD03_1); 
        Wire.write(ACC_reg);          
        Wire.write(27);             
        Wire.endTransmission();
        Wire.beginTransmission(MD03_2); 
        Wire.write(ACC_reg);       
        Wire.write(27);             
        Wire.endTransmission();
        Wire.beginTransmission(MD03_1);
        Wire.write(CMD_reg);       
        Wire.write(1);              
        Wire.endTransmission();    
        Wire.beginTransmission(MD03_2); 
        Wire.write(CMD_reg);        
        Wire.write(1);             
        Wire.endTransmission();    
         }
      
  }
    else if (valueFB < 400) {                               //rijd achteruit
      Wire.beginTransmission(MD03_1); 
      Wire.write(SPEED_reg);          
      Wire.write(128);             
      Wire.endTransmission();
      Wire.beginTransmission(MD03_2); 
      Wire.write(SPEED_reg);        
      Wire.write(128);              
      Wire.endTransmission();

      Wire.beginTransmission(MD03_1);
      Wire.write(ACC_reg);          
      Wire.write(27);             
      Wire.endTransmission();
      Wire.beginTransmission(MD03_2);
      Wire.write(ACC_reg);          
      Wire.write(27);             
      Wire.endTransmission();
      Wire.beginTransmission(MD03_1); 
      Wire.write(CMD_reg);        
      Wire.write(2);               // sets motor to backwards
      Wire.endTransmission();    
      Wire.beginTransmission(MD03_2); 
      Wire.write(CMD_reg);       
      Wire.write(2);              // sets motor to backwards 
      Wire.endTransmission();    
    
       if( valueFB < 400 and valueLR > 600) {                                      // rijd links archteruit
          Wire.beginTransmission(MD03_1); 
          Wire.write(SPEED_reg);         
          Wire.write(128);            
          Wire.endTransmission();
          Wire.beginTransmission(MD03_2); 
          Wire.write(SPEED_reg);          
          Wire.write(64);             
          Wire.endTransmission();
      
          Wire.beginTransmission(MD03_1);
          Wire.write(ACC_reg);         
          Wire.write(27);              
          Wire.endTransmission();
          Wire.beginTransmission(MD03_2); 
          Wire.write(ACC_reg); 
          Wire.write(27);              
          Wire.endTransmission();
          Wire.beginTransmission(MD03_1); 
          Wire.write(CMD_reg);       
          Wire.write(2);              
          Wire.endTransmission();    
          Wire.beginTransmission(MD03_2); 
          Wire.write(CMD_reg);       
          Wire.write(2);              
          Wire.endTransmission();    
        }

        else if ( valueFB < 400 and valueLR < 400)        // rijd rechts achteruit
        {
          Wire.beginTransmission(MD03_1);
          Wire.write(SPEED_reg);          
          Wire.write(64);              
          Wire.endTransmission();
          Wire.beginTransmission(MD03_2); 
          Wire.write(SPEED_reg);          
          Wire.write(128);              
          Wire.endTransmission();
      
          Wire.beginTransmission(MD03_1); 
          Wire.write(ACC_reg);        
          Wire.write(27);            
          Wire.endTransmission();
          Wire.beginTransmission(MD03_2);
          Wire.write(ACC_reg);          
          Wire.write(27);            
          Wire.endTransmission();
          Wire.beginTransmission(MD03_1); 
          Wire.write(CMD_reg);       
          Wire.write(2);             
          Wire.endTransmission();    
          Wire.beginTransmission(MD03_2); 
          Wire.write(CMD_reg);        
          Wire.write(2);             
          Wire.endTransmission();  
        }
    }
  else if (valueLR > 600){                      //draait links
    Wire.beginTransmission(MD03_1); 
    Wire.write(SPEED_reg);         
    Wire.write(128);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(SPEED_reg);         
    Wire.write(0);              
    Wire.endTransmission();

    Wire.beginTransmission(MD03_1); 
    Wire.write(ACC_reg);         
    Wire.write(27);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2);
    Wire.write(ACC_reg);      
    Wire.write(27);           
    Wire.endTransmission();
    Wire.beginTransmission(MD03_1);
    Wire.write(CMD_reg);      
    Wire.write(1);             
    Wire.endTransmission();    
    Wire.beginTransmission(MD03_2); 
    Wire.write(CMD_reg);        
    Wire.write(1);             
    Wire.endTransmission();   
  }
  else if (valueLR < 400 ) {                                 //draait rechts 
    Wire.beginTransmission(MD03_1); 
    Wire.write(SPEED_reg);         
    Wire.write(0);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(SPEED_reg);        
    Wire.write(128);             
    Wire.endTransmission();

    Wire.beginTransmission(MD03_1); 
    Wire.write(ACC_reg);          
    Wire.write(27);              
    Wire.endTransmission();
    Wire.beginTransmission(MD03_2); 
    Wire.write(ACC_reg);        
    Wire.write(27);             
    Wire.endTransmission();
    Wire.beginTransmission(MD03_1); 
    Wire.write(CMD_reg);        
    Wire.write(1);             
    Wire.endTransmission();    
    Wire.beginTransmission(MD03_2); 
    Wire.write(CMD_reg);        
    Wire.write(1);             
    Wire.endTransmission();   


  }
  
}


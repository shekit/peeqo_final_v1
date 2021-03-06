/////////////////////////////
//        SAY NO           //
/////////////////////////////


void sayNoMovement(){
   if(sayNoPos >= sayNoMax || sayNoPos <= sayNoMin){
      if(sayNoPos >= sayNoMax){
         sayNoPos = sayNoMax; 
      } else {
         sayNoPos = sayNoMin;
      }
      
      sayNoSpeed *= -1;
   } 
   
   float prevVal = sayNoPos;
   boolean transitioned = false;
   
   sayNoPos += sayNoSpeed;
   
   if(prevVal <90 && sayNoPos >=90){
      transitioned = true; 
   }
   if(prevVal >=90 && sayNoPos <90){
      transitioned = true; 
   }
   
   if(transitioned) {
      sayNoShiftCount++;
      if(sayNoShiftCount >= sayNoShiftThresh){
         sayNoSpeed = 0;
         sayNoPos = 90;
         sayNoShiftCount = 0;
         sayNoBoolean = false;
         sad = false;
         atRest = true;
      } 
   }  
}

void sayNo(){
   servoNeck.write((int)sayNoPos); 
}

/////////////////////////////
//        SAY YES          //
/////////////////////////////


void sayYesMovement(){
   
   if(sayYesPos >= sayYesMax || sayYesPos <= sayYesMin){
      if(sayYesPos >= sayYesMax){
         sayYesPos = sayYesMax; 
      } else {
         sayYesPos = sayYesMin;
      }
      
      sayYesSpeed *= -1;
   } 
   
   float prevVal = sayYesPos;
   boolean transitioned = false;
   
   sayYesPos += sayYesSpeed;
   //Serial.println(servoHead.read());
   if(prevVal <90 && sayYesPos >=90){
      transitioned = true; 
   }
   if(prevVal >=90 && sayYesPos <90){
      transitioned = true; 
   }
   
   if(transitioned) {
      sayYesShiftCount++;
      if(sayYesShiftCount >= sayYesShiftThresh){
         sayYesSpeed = 0;
         sayYesPos = 90;
         sayYesShiftCount = 0;
         sayYesBoolean = false;
         atRest = true;  // so eyes go back to blinking
         //changeEyes(happyEyeOn,happyEyeOnLength,happyEyeOff,happyEyeOffLength); has to be put here if you want it to work, otherwise servos dun work
      } 
   }  
}

void sayYes(){
   servoHead.write((int)sayYesPos); 
}


/////////////////////////////
//        BE SAD           //
/////////////////////////////


void beSadMovement(){
   if(beSadPos <= beSadMin){
      beSadPos = beSadMin;
      beSadSpeed = 0;
      beSadBoolean = false;
   } 
   
   beSadPos -= beSadSpeed;  
}

void beSad(){
   servoHead.write((int)beSadPos); 
}

void beSadNeckMovement(){
   if(beSadNeckPos >= beSadNeckMin){
      beSadNeckPos = beSadNeckMin;
      beSadNeckSpeed = 0;
      beSadNeckBoolean = false;
   } 
   
   beSadNeckPos += beSadNeckSpeed;  
}

void beSadNeck(){
   servoNeck.write((int)beSadNeckPos); 
}

/////////////////////////////
//        BE HAPPY         //
/////////////////////////////


void beHappyMovement(){
   if(beHappyPos >= beHappyMax){
      beHappyPos = beHappyMax;
      beHappySpeed = 0;
      beHappyBoolean = false;
   } 
   
   beHappyPos += beHappySpeed;  
}

void beHappy(){
   servoHead.write((int)beHappyPos); 
}

void beHappyNeckMovement(){
   if(beHappyNeckPos >= beHappyNeckMax){
      beHappyNeckPos = beHappyNeckMax;
      beHappyNeckSpeed = 0;
      beHappyNeckBoolean = false;
   } 
   
   beHappyNeckPos += beHappyNeckSpeed;  
}

void beHappyNeck(){
   servoNeck.write((int)beHappyNeckPos); 
}

/////////////////////////////
//       RESET HEAD        //
/////////////////////////////

void resetHeadMovement(){
   float resetHeadPos = servoHead.read();
   
   if(resetHeadPos >= resetHead){
     if(resetHeadPos == resetHead){
        resetHeadPos = resetHead;
        resetHeadSpeed = 0;
        resetHeadBoolean = false; 
     }
     
     resetHeadPos -= resetHeadSpeed;
     
   }
     
   if(resetHeadPos <= resetHead){
     if(resetHeadPos == resetHead){
        resetHeadPos = resetHead;
        resetHeadSpeed = 0;
        resetHeadBoolean = false;  
     }
    
     resetHeadPos += resetHeadSpeed; 
   }
      
}

void resetHeadServo(){
   //float resetHeadPos = servoHead.read();
   servoHead.write(initialServoHeadPos);

}

/////////////////////////////
//       RESET NECK        //
/////////////////////////////

void resetNeckMovement(){
  float resetNeckPos = servoNeck.read();
  
  if(resetNeckPos >= resetNeck){
     if(resetNeckPos == resetNeck){
        resetNeckPos = resetNeck;
        resetNeckSpeed = 0;
        resetNeckBoolean = false; 
     }
     
     resetNeckPos -= resetNeckSpeed;
     
   }
     
   if(resetNeckPos <= resetNeck){
     if(resetNeckPos == resetNeck){
        resetNeckPos = resetNeck;
        resetNeckSpeed = 0;
        resetNeckBoolean = false;  
     }
    
     resetNeckPos += resetNeckSpeed; 
   }
}

void resetNeckServo(){
   servoNeck.write(initialServoNeckPos); 
}

void resetArmServo(){
   servoArm.write(initialServoArmPos); 
}

void resetServos() {
   servoHead.write(initialServoHeadPos);
   servoNeck.write(initialServoNeckPos); 
   servoArm.write(initialServoArmPos);
}


/////////////////////////////
//       WAKE UP           //
/////////////////////////////

void wakeUpMovement() {
    if(servoHead.read() >= 90){
      wakeUpPos = 90;
      wakeUpSpeed = 0;
      wakeUpServo = false;
   } 
   
   wakeUpPos += wakeUpSpeed;
  
}

void wakeUp(){
  servoHead.write((int)wakeUpPos);
}

/////////////////////////////
//       SLEEP             //
/////////////////////////////

void sleepMovement() {
    if(servoHead.read() <= initialServoHeadPos){
      sleepPos = initialServoHeadPos;
      sleepSpeed = 0;
      sleepServo = false;
   } 
   
   sleepPos -= sleepSpeed;
  
}

void sleep(){
  servoHead.write((int)sleepPos);
}



/////////////////////////////
//          DANCE          //
/////////////////////////////

void danceHeadMovement() {
  if(danceHeadPos >= danceHeadMax || danceHeadPos <= danceHeadMin){
      if(danceHeadPos >= danceHeadMax){
         danceHeadPos = danceHeadMax; 
      } else {
         danceHeadPos = danceHeadMin;
      }
      
      danceHeadSpeed *= -1;
   } 
   
   float prevVal = danceHeadPos;
   boolean transitioned = false;
   
   danceHeadPos += danceHeadSpeed;
   
   if(prevVal <90 && danceHeadPos >=90){
      transitioned = true; 
   }
   if(prevVal >=90 && danceHeadPos <90){
      transitioned = true; 
   }
   
   if(transitioned) {
      danceHeadShiftCount++;
      if(danceHeadShiftCount >= danceHeadShiftThresh){
         danceHeadSpeed = 0;
         danceHeadPos = 90;
         danceHeadShiftCount = 0;
         danceHeadBoolean = false;
      } 
   }
  
  
}

void danceNeckMovement() {
  if(danceNeckPos >= danceNeckMax || danceNeckPos <= danceNeckMin){
      if(danceNeckPos >= danceNeckMax){
         danceNeckPos = danceNeckMax; 
      } else {
         danceNeckPos = danceNeckMin;
      }
      
      danceNeckSpeed *= -1;
   } 
   
   float prevVal = danceNeckPos;
   boolean transitioned = false;
   
   danceNeckPos += danceNeckSpeed;
   
   if(prevVal <90 && danceNeckPos >=90){
      transitioned = true; 
   }
   if(prevVal >=90 && danceNeckPos <90){
      transitioned = true; 
   }
   
   if(transitioned) {
      danceNeckShiftCount++;
      if(danceNeckShiftCount >= danceNeckShiftThresh){
         danceNeckSpeed = 0;
         danceNeckPos = 90;
         danceNeckShiftCount = 0;
         danceNeckBoolean = false;
      } 
   }
}

void danceHead() {
  servoHead.write((int)danceHeadPos);
}

void danceNeck() {
  servoNeck.write((int)danceNeckPos);
}


/////////////////////////////
//       HIGH FIVE UP         //
/////////////////////////////

void highFiveUp(){
  servoArm.write(highFiveUpPos);
}

/////////////////////////////
//       HIGH FIVE DOWN        //
/////////////////////////////

void highFiveDown(){
  servoArm.write(initialServoArmPos);
}



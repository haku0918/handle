
//////////
/////////  All Serial Handling Code,
/////////  It's Changeable with the 'outputType' variable
/////////  It's declared at start of code.
/////////
int bef_ibi=-1,Time=0,avg,sleepy=0,check=0;
long sum=0L;

void serialOutput(){   // Decide How To Output Serial.


}

//  Decides How To OutPut BPM and IBI Data
void serialOutputWhenBeatHappens(){

   switch(outputType){
    case PROCESSING_VISUALIZER:
      sendDataToSerial('S', Signal);     // goes to sendDataToSerial function
      break;
    case SERIAL_PLOTTER:  // open the Arduino Serial Plotter to visualize these data
   //   if(IBI<=300) break;
   /*   if(bef_ibi==-1) bef_ibi=IBI;
      else{
        if((abs(IBI-bef_ibi)/(float)IBI)>0.35) break;
      }*/
    //  Serial.print("IBI : ");
   //   if(IBI==bef_ibi) break;
   //   bef_ibi=IBI;
      sum+=(IBI-vals[Time]);
      vals[Time]=IBI;
 //       Serial.print(Time);
 //     Serial.print(",");
 //     Serial.print(IBI);
 //     Serial.print(",");
      if(check==0) Serial.println(sum/(Time+1));
      else Serial.println(sum/100);
      Time++;
      if(Time==1000){
        avg=sum/1000;
        Time=0;
        check=1;
        if(avg<=850){
          sleepy=0;
          break;
        }
        sleepy++;
        if(sleepy>=3){      
          Serial.println("Play record");
          digitalWrite(play,HIGH);
          delay(1000);
          digitalWrite(play,LOW);
        }
      }
      break;
    default:
      break;
  }
  /*switch(outputType){
    case PROCESSING_VISUALIZER:    // find it here https://github.com/WorldFamousElectronics/PulseSensor_Amped_Processing_Visualizer
      sendDataToSerial('B',BPM);   // send heart rate with a 'B' prefix
      sendDataToSerial('Q',IBI);   // send time between beats with a 'Q' prefix
      break;

    default:
      break;
  }*/
}

//  Sends Data to Pulse Sensor Processing App, Native Mac App, or Third-party Serial Readers.
void sendDataToSerial(char symbol, int data ){
//    Serial.print(symbol);
//    Serial.println(data);
  }

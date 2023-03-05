#define l A1
#define r A0
#define f A2
#define b A3
#include<Servo.h>
Servo w1;
Servo f1;
Servo w2;
Servo f2;
Servo t1;
Servo t2;
Servo k1;
Servo k2;
Servo a1;
Servo a2;
int wa1=90;
int wa2=90;
int fa1=90;
float ta1=90;
float ka1=90;
float aa1=90;
int ta2=90;
int ka2=90;
int aa2=90;
int fa2=90;
void setup() {
  Serial.begin(9600);
                                  
   pinMode(f,INPUT_PULLUP);
   pinMode(b,INPUT_PULLUP);
   pinMode(f,INPUT_PULLUP);
   pinMode(l,INPUT_PULLUP);
   pinMode(r,INPUT_PULLUP);
  w1.attach(7);
  t1.attach(6);
  k1.attach(5);
  a1.attach(4);
  f1.attach(2);
  w2.attach(12);
  t2.attach(11);
  k2.attach(10);
  a2.attach(9);
  f2.attach(8);
       delay(500);
  
}
void loop() {
  delay(500);
                            
  int q=5;
  int fstate=digitalRead(f);
  int bstate=digitalRead(b);
  int lstate=digitalRead(l);
  int rstate=digitalRead(r);
   Serial.print("f=");
  Serial.print(fstate);
   Serial.print("  b=");
  Serial.print(bstate);
   Serial.print("  l=");
  Serial.print(lstate);
   Serial.print("  r=");
  Serial.println(rstate);
  Serial.print(wa1);
  Serial.print(wa2);
  Serial.print(ta1);
  Serial.print(ta2);
  Serial.print(ka1);
  Serial.print(ka2);
  Serial.print(aa1);
  Serial.print(aa2);
  Serial.print(fa1);
  Serial.println(fa2);
 if((rstate==0)&&(fstate==0))///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////right
  {
    while(wa1<120)               //laen left=++,right=--
    {
      wa1++;
      wa2++;                 
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q);
    }
    while(ka1>40)                  //lift
    {
     if(ta1<130)
     {ta1++;}
      ka1--;
      aa1++;
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      delay(q);
    }
    while(wa2>80)                //dynamic lean move= right  //////////////////////////////70
    {
      if(wa1<120)
      {wa1++;
      fa1++;
      }
       wa2--;
      fa2--;
      w1.write(wa1);
      f2.write(fa2);
      f1.write(fa1);
      w2.write(wa2);
      delay(q);
    }
     while(wa1>70)               //laen left=++,right=--
    {
      wa1--;
      wa2--;                 
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q);
    }
    
    while(ta1>90)           //standing back by extending legs ( remain leaned )
    {
      ta1--;
      ka1++;
      aa1--;
      if(wa2<70)
      {
        wa2++;
        fa2++;
      }
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q);
      
    }
    while(wa1<90)               //laen left=++,right=--
    {
      wa1++;
      wa2++;                 
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q);
    }
   { t1.write(ta1=90);                //back to 90
      k1.write(ka1=90);
      a1.write(aa1=90);
      f1.write(fa1=90);
      w1.write(wa1=90);
      a2.write(aa2=90);
      t2.write(ta2=90);
      k2.write(ka2=90);
      f2.write(fa2=90);
      w2.write(wa2=90);
      delay(q);}
      
  }
  if((lstate==0)&&(fstate==0))/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////left
  {
    while(wa1>60)               //laen left=++,right=--
    {
      wa1--;
      wa2--;                 
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q);
    }
    while(ta2>40)                   //lift
    {
      if(aa1<92)
     { aa1++;}
      ta2--;
      ka2--;
     if(ta2>70)
     {aa2--;}
       a2.write(aa2);
      t2.write(ta2);
      k2.write(ka2);
      delay(q);
    }
    while(wa1<100)                //dynamic lean move= left 
    {
      if(wa2>60)
      {wa2--;
      fa2--;
      }
       wa1++;
      fa1++;
      w1.write(wa1);
      f2.write(fa2);
      f1.write(fa1);
      w2.write(wa2);
      delay(q);
    }
     while(wa2<110)               //laen left=++,right=--
    {
      wa1++;
      wa2++;                 
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q);
    }
    
    while(ta2<90)           //standing back by extending legs ( remain leaned )
    {
     if(ta2<90)
     {ta2++;}
      ka2++;
     if(aa2<90)
     {aa2++;}
      if(wa1>110)
      {
        wa1--;
        fa1--;
      }
      t2.write(ta2);
      k2.write(ka2);
      a2.write(aa2);
      w1.write(wa1);
      f1.write(fa1);
      delay(q);
      
    }
    while(wa1>90)               //laen left=++,right=--
    {
      wa1--;
      wa2--;                 
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q);
    }
   { t1.write(ta1=90);                //back to 90
      k1.write(ka1=90);
      a1.write(aa1=90);
      f1.write(fa1=90);
      w1.write(wa1=90);
      a2.write(aa2=90);
      t2.write(ta2=90);
      k2.write(ka2=90);
      f2.write(fa2=90);
      w2.write(wa2=90);
      delay(q);}
      
  }
  int q1=5;
   if((fstate==0)&&(bstate==1)&&(lstate==1)&&(rstate==1))////////////////////////////////////////////////////////////////////////////////////////////////forward
  { 
   while(wa2<120)               //laen left=++,right=--
    {
      wa1++;
      wa2++;                 
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q1);
    } 
    while(ta1<150)              //perfect lift right
    {
      ta1++;
      //if(ka1>60)
      {ka1--;}
    // if(aa1<120)
     {aa1++;}
      t1.write(ta1);               
      k1.write(ka1);
      a1.write(aa1);
      delay(q1);
    }
    while(ta2<120)             //move forward by moving left leg
    {
      ta2++;
      aa2--;
      aa2--;
      ka2--;
      t2.write(ta2);
      k2.write(ka2);
      a2.write(aa2);
      delay(q1);
    }
     while(wa1>70)               //laen left=++,right=--
    {
      wa1--;
      wa2--;                 
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q1);
    }
    while(ta1>90)             //expanding right leg to normal
    {
      ta1--;
      ka1++;
      aa1--;
      t1.write(ta1);               
      k1.write(ka1);
      a1.write(aa1);
      delay(q1); 
    }
    {
      t2.write(ta2=90);
      a2.write(aa2=90);
      t1.write(ta1=90);               
      k1.write(ka1=90);
      a1.write(aa1=90);
      delay(q1); 
    }
    
    /*  
    while(ta2>60)          // lift left (perfect)
    {
      ta2--;
      if(ka2>60)
      {ka2--;}
    if(aa2>60)
    {aa2--;}
      t2.write(ta2);
      k2.write(ka2);
      a2.write(aa2);
      delay(q1); 
    }
    while(ta2<90)          //expand left  (perfect)
    {
      ta2++;
     if(ka2<90)
     {ka2++;}
     if(aa2<90)
     {aa2++;}
      t2.write(ta2);
      k2.write(ka2);
      a2.write(aa2);
      delay(q1); 
    }
   */
     while(wa2<90)               //laen left=++,right=--
    {
      
      wa1++;
      wa2++;                 
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q1);
    } 
  
     {
     t1.write(ta1=90);                //back to 90
      k1.write(ka1=90);
      a1.write(aa1=90);
      f1.write(fa1=90);
      w1.write(wa1=90);
      a2.write(aa2=90);
      t2.write(ta2=90);
      k2.write(ka2=90);
      f2.write(fa2=90);
      w2.write(wa2=90);
      delay(q);}
    
   }
   int q2=5;
 if((fstate==1)&&(bstate==0)&&(lstate==1)&&(rstate==1)) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////back
  {
    while (wa2 < 120)            //laen left=++,right=--
    {
      wa1++;
      wa2++;
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q2);
    }
    while (ta1 < 120)           //perfect lift right
    {
      ta1++;
      if (ka1 > 60)
      {
        ka1--;
      }
      if (aa1 < 120)
      {
        aa1++;
      }
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      delay(q2);
    }
    while(ta2>60) //move back WTH left
    {
     ta2--;
     ta2--;
     aa2++;
    // if(ta2>50)
     //{aa2++;}
     t2.write(ta2);
     a2.write(aa2);
      delay(15);
    }
    
    while (wa1 > 70)            //laen left=++,right=--
    {
      wa1--;
      wa2--;
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q2);
    }
    while (ta1 > 90)          //expanding right leg to normal
    {
      ta1--;
      ka1++;
      aa1++;
     //if(aa1>90)
     //{aa1--;}
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      delay(q2);
    }
    while (ka2>60)       // lift left
    {
      //ta2--;
      ka2--;
      aa2--;
      t2.write(ta2);
      k2.write(ka2);
      a2.write(aa2);
      delay(q2);
    }
    while(ta1<120)     //moving back WTH right
    {
      ta1++;
      aa1--;
      t1.write(ta1);
      a1.write(aa1);
      delay(15);
    }
    while (wa2 < 100)            //laen left=++,right=--
    {
      wa1++;
      wa2++;
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(q2);
    }
    while(ta1>90)
    {
     if(ta1>90)
     {ta1--;}
    // if(aa1>90)
     //{aa1--;}
     if(aa1<90)
     {aa1++;}
     if(ta2<90)
     {ta2++;}
     if(ka2<90)
     {ka2++;}
     if(aa2<90)
     {aa2++;}
      t2.write(ta2);
      k2.write(ka2);
      a2.write(aa2);
      t1.write(ta1);
      a1.write(aa1);
      delay(q2);
    }
    while(aa2>90)
    {
      aa2--;
      //aa1++;
      a2.write(aa2);
      a1.write(aa1);
      delay(q2);
    }
    { 
     t1.write(ta1=90);                //back to 90
      k1.write(ka1=90);
      a1.write(aa1=90);
      f1.write(fa1=90);
      w1.write(wa1=90);
      a2.write(aa2=90);
      t2.write(ta2=90);
      k2.write(ka2=90);
      f2.write(fa2=90);
      w2.write(wa2=90);
      delay(q);}    
  }
int tl=10;
   if((fstate==1)&&(bstate==1)&&(lstate==0)&&(rstate==1)) //turnleft//////////////////////////////////////////////////////////////////
  { 
   
      while(ta1>60)              //turn slip left
    {
      ta1--;
      aa1++;
      ta2--;
      aa2++;
      t2.write(ta2);
      a2.write(aa2);
      t1.write(ta1);
      a1.write(aa1);
      delay(10);
    }
     while (wa1<120)            //laen left=++,right=--
    {
      wa1++;
      wa2++;
      fa1++;
      fa2++;
      t1.write(ta1);
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(tl);
    }
     while (ta1 < 120)           //perfect lift right
    {
      ta1++;
      if (ka1 > 70)
      {
        ka1--;
      }
      if (aa1 < 100)
      {
        aa1++;
      }
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      delay(q2);
    }
     while(ta2<90)     //slid back of t left
    {
      ta1++;
      aa1--;
      ta2++;
      aa2--;
      t2.write(ta2);
      a2.write(aa2);
      t1.write(ta1);
      a1.write(aa1);
      delay(tl);
    }
    while (ta1 > 90)          //expanding right leg to normal
    {
      ta1--;
      if(ka1<90)
      {ka1++;}
     if(aa1>90)
     {aa1--;}
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      delay(q2);
    } 
      while (wa1>90)            //laen left=++,right=--
    {
      wa1--;
      wa2--;
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(5);
    }
    
   }
    int tr=10;
 if((fstate==1)&&(bstate==1)&&(lstate==1)&&(rstate==0)) //turnright///////////////////////////////////////////////////////////////////////////////////
 {
     
     while(ta1<110)              //turn slip right
    {
      ta1++;
      aa1--;
      ta2++;
      aa2--;
      t2.write(ta2);
      a2.write(aa2);
      t1.write(ta1);
      a1.write(aa1);
      delay(10);
    }

   
     while (wa1>80)            //laen left=++,right=--
    {
      wa1--;
      wa2--;
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(5);
    } 
      while(ta2>60)          // lift left (perfect)
    {
      ta2--;
      if(ka2>60)
      {ka2--;}
    if(aa2>60)
    {aa2--;}
      t2.write(ta2);
      k2.write(ka2);
      a2.write(aa2);
      delay(q1); 
    }
    while(ta1>90)     //silde turn right
    {
      ta1--;
      aa1++;
      ta2--;
      aa2++;
      t2.write(ta2);
      a2.write(aa2);
      t1.write(ta1);
      a1.write(aa1);
      delay(tr);
    }
     while(ta2<90)          //expand left  (perfect)
    {
      ta2++;
     if(ka2<90)
     {ka2++;}
     if(aa2<90)
     {aa2++;}
      t2.write(ta2);
      k2.write(ka2);
      a2.write(aa2);
      delay(q1); 
    }
   while (wa1<90)            //laen left=++,right=--
    {
      wa1++;
      wa2++;
      fa1++;
      fa2++;
      t1.write(ta1);
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(tl);
    }
   
 } 

 
   int leanspeed=10;
if((rstate==0)&&(bstate==0))///////////////////////////lean pick right/////////////////////////////////
   {
    while(ka1>30)           //down
    {
      if(ta1<150)
      {ta1++;}
        ka1--;
      if (aa1 <150)
      {
        aa1++;
      }
      if(ta2>30)
      {ta2--;}
      if(ka2>30)
      {ka2--;}
      if(aa2>30)
      {aa2--;}
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      a2.write(aa2);
      t2.write(ta2);
      k2.write(ka2);
      delay(leanspeed);
    
    }
     while (wa1 > 60)            //laen left=++,right=--
    {
      wa1--;
      wa2--;
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(leanspeed);
    }
    while(ka1<90)            //expanding legs
    {
      ka1++;
      ta1--;
      aa1--;
      ta2++;
      ka2++;
      aa2++;
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      a2.write(aa2);
      t2.write(ta2);
      k2.write(ka2);
      delay(leanspeed); 
    }
     {
      t1.write(ta1=90);                //back to 90
      k1.write(ka1=90);
      a1.write(aa1=90); 
      a2.write(aa2=90);
      t2.write(ta2=90);
      k2.write(ka2=90);
      delay(leanspeed);
      } 
       while (wa1<90)            //laen left=++,right=--
    {
      wa1++;
      wa2++;
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(leanspeed);
    }   
     
      }
  if((lstate==0)&&(bstate==0))////////////////////////////////////////////////////////////////flat slid
   {
    
    while(wa1<180)
    {
      
      fa1++;
      wa1++;
      fa2--;
      wa2--; 
      w2.write(wa2);
      f2.write(fa2);
      f1.write(fa1);
      w1.write(wa1);
      delay(5); 
    }
  
    while(wa1>90)
    {
      fa1--;
      wa1--;
      fa2++;
      wa2++;
      w2.write(wa2);
      f2.write(fa2);
      f1.write(fa1);
      w1.write(wa1);
      delay(5);
    }
    { 
     t1.write(ta1=90);                //back to 90
      k1.write(ka1=90);
      a1.write(aa1=90);
      f1.write(fa1=90);
      w1.write(wa1=90);
      a2.write(aa2=90);
      t2.write(ta2=90);
      k2.write(ka2=90);
      f2.write(fa2=90);
      w2.write(wa2=90);
      delay(5);
      }    
    /* while(ka1>30)           //down
    {
      if(ta1<150)
      {ta1++;}
        ka1--;
      if (aa1 <150)
      {
        aa1++;
      }
      if(ta2>30)
      {ta2--;}
      if(ka2>30)
      {ka2--;}
      if(aa2>30)
      {aa2--;}
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      a2.write(aa2);
      t2.write(ta2);
      k2.write(ka2);
      delay(leanspeed);
    }
     while (wa1<120)            //laen left=++,right=--
    {
      wa1++;
      wa2++;
      fa1++;
      fa2++;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(leanspeed);
    }
     while(ka1<90)            //expanding legs
    {
      ka1++;
      ta1--;
      aa1--;
      ta2++;
      ka2++;
      aa2++;
      t1.write(ta1);
      k1.write(ka1);
      a1.write(aa1);
      a2.write(aa2);
      t2.write(ta2);
      k2.write(ka2);
      delay(leanspeed); 
    }
    while (wa1>90)            //laen left=++,right=--
    {
      wa1--;
      wa2--;
      fa1--;
      fa2--;
      w1.write(wa1);
      f1.write(fa1);
      w2.write(wa2);
      f2.write(fa2);
      delay(leanspeed);
    }*/
   }
  
}

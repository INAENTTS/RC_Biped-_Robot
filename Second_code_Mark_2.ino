#include <math.h>
#include <Servo.h>  
#define l A1
#define r A0
#define f A2
#define b A3               
                           
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
float wa1=90;
float wa2=90;
float fa1=90;
float ta1=90;
float ka1=90;
float aa1=90;
float ta2=90;
float ka2=90;
float aa2=90;
float fa2=90;
                          
float x=0;
float y=6;
float x2=0;
float y2=5;
float zb;
float z1;
float z2;
float i;

float A;
float B;
float T;
float Al;
float Bl;
float Tl;
float ap;
float bp;
float zba;
float z1a;
float z2a;
float L1=x*x+y*y;
float L2=x2*x2+y2*y2;
int cr( float x,float y)///////////////////calculating the right leg angles as a function of end co-ordinates
 { 
  Serial.println(L1);
  if(L1<=49)
  { A=atan(x/y)*57.2957795;
  B=acos((sqrt(x*x+y*y))/8)*57.2957795;
  ta1=A+B+60;
  ka1=150-2*B;
  aa1=61.04-A+B;
 // Serial.println("cr"); 
  }
  }
int cl(float x2,float y2)////////////////// calculating the left leg angles as a function of end co-ordinates
{
   Serial.println(L2);
  if(L2<=36)
  { Al=atan(x2/y2)*57.2957795;
  Bl=acos((sqrt(x2*x2+y2*y2))/6)*57.2957795;
  ta2=90-Al-Bl;
  ka2=90-2*Bl;//150-2*Bl-2.09;
  aa2=90+Al-Bl;//118.96+Al-Bl;
  //Serial.println("cl"); 
  }
                         Serial.println(Al);
                         Serial.println(Bl);
                         Serial.print("*");
                         Serial.println(ta2);
                         Serial.println(ka2);
                         Serial.println(aa2);
}
int lean( float zb)  ///////////////////////////// movement along z axis of center point (in the plane of two legs)
{
  //Serial.println ("bigin");
  zba=asin(zb/y)*57.2957795;
  float Z=90+(zba); 
 /* Serial.println (Z);
   Serial.println (fa1);
   Serial.println (abs(fa1-Z));
   Serial.println (fa1+((Z-fa1)/abs(Z-fa1)));*/
                                                     //wa2=wa1=90-(90-zba)*(zb/(abs(zb))); 
                                                    //fa2=fa1=90-(90-zba)*(zb/(abs(zb)));
  for(fa1 ; (abs(fa1-Z))>0.6  ;fa1=fa1+((Z-fa1)/abs(Z-fa1)))
    { 
      w1.write(fa1);
      f1.write(fa1);
      w2.write(fa1);               
      f2.write(fa1);
      delay(5);
     // Serial.println((fa1));
    }
    //Serial.println("d");
 } 
int rl( float h)//////////////////////////////////////lifting right leg by height h
{
  
  for( y ; abs(y-h)>=0.6; y=y+0.2*((h-y)/abs(h-y)))
  {
      cr(x,y);
       t1.write(ta1);               
       k1.write(ka1);
       a1.write(aa1);
       delay(5);
      // Serial.println("b");
  }
  
}
int ll( float h)///////////////////////////////////////lifting left leg by height h
{
  for( y2 ; abs(y2-h)>=0.6; y2+0.2*((h-y2)/abs(h-y2)))
  {
      cl(x2,y2);
       t2.write(ta2);               
       k2.write(ka2);
       a2.write(aa2);
       delay(5);
  }
  
}

int sf( float H ,float s)/////////////////////////////step forward
 {
  lean(3);
  //rl(6-H);
  for(x=0;x<=s;x=x+0.2)
 {
 // y=6-H*sqrt(1-((x*x)/(s*s)));
 // cr( x,y);
  
                         Serial.println(A);
                         Serial.println(B);
                         Serial.print("*");
                         Serial.println(ta1);
                         Serial.println(ka1);
                         Serial.println(aa1);
                         Serial.println("*** f");
 if(x2>(-s))  
 { x2=x2-0.2;
//  y2=5;
   //y2=5+H*sqrt(1-((x2*x2)/(s*s)));
   cl(x2,y2);
  
                         Serial.println(Al);
                         Serial.println(Bl);
                         Serial.print("*");
                         Serial.println(ta2);
                         Serial.println(ka2);
                         Serial.println(aa2);
                         Serial.println("*** b");
   t2.write(ta2);               
   k2.write(ka2);
   a2.write(aa2);}
   t1.write(ta1);               
   k1.write(ka1);
   a1.write(aa1);
  
   delay(20);
   
  
 }
 Serial.println("* emd");
 lean(-3);
 ll(5-H);
 for ( x ;x>=0;x=x-0.2)
 {
  cr(x,y);
 
  x2=x2+0.2;
   y2=5-H*sqrt(1-(x2*x2)/(s*s));
   cl(x2,y2);
 
   t2.write(ta2);               
   k2.write(ka2);
   a2.write(aa2);

   t1.write(ta1);               
   k1.write(ka1);
   a1.write(aa1);
   delay(10);
 }
 rl(6);
 ll(5);
 lean(0);
 x=x2=0;

  w1.write(wa1=90);
      f1.write(fa1=90);
      w2.write(wa2=90);               
      f2.write(fa2=90);
      t2.write(ta2=90);
      a2.write(aa2=90);
      t1.write(ta1=90);               
      k1.write(ka1=90);
      a1.write(aa1=90);
      delay(5);
      Serial.println("*********************************************end sf");
 }
 int sb( float H ,float s)///////////////////////////////////////////step backwards
 {
  lean(-1.75);
  rl(6-H);
  for(x=0;x>=-s;x=x-0.2)
  
  {
  y=6-H*sqrt(1-(x*x)/(s*s));
  cr( x,y);

                         Serial.println(A);
                         Serial.println(B);
                         Serial.print("*");
                         Serial.println(ta1);
                         Serial.println(ka1);
                         Serial.println(aa1);
                         Serial.print("***");
   
  x2=x2+0.2;
  cl(x2,y2);
  
  
                         Serial.println(Al);
                         Serial.println(Bl);
                         Serial.print("*");
                         Serial.println(ta2);
                         Serial.println(ka2);
                         Serial.println(aa2);
                         Serial.print("***");
   t2.write(ta2);               
   k2.write(ka2);
   a2.write(aa2);

   t1.write(ta1);               
   k1.write(ka1);
   a1.write(aa1);
   delay(10);
  
 }
 lean(1.75);
 ll(5-H);
 for ( x ;x<=0;x=x+0.2)
 {
  cr(x,y);
 
  x2=x2-0.2;
   y2=5-H*sqrt(1-(x2*x2)/(s*s));
   cl(x2,y2);

   t2.write(ta2);               
   k2.write(ka2);
   a2.write(aa2);

   t1.write(ta1);               
   k1.write(ka1);
   a1.write(aa1);
   delay(10);
 }
 ll(5);
 lean(0);
  w1.write(wa1=90);
      f1.write(fa1=90);
      w2.write(wa2=90);               
      f2.write(fa2=90);
      t2.write(ta2=90);
      a2.write(aa2=90);
      t1.write(ta1=90);               
      k1.write(ka1=90);
      a1.write(aa1=90);
      delay(5);
 }
 int ro( float rr)/////////////////////////////////////////////////////////// rotate(tilt) the upper plane by angle rr 
 {
  for( i ; abs(rr)-abs(i)>=0; i=i+((rr)/abs(rr)))
  {
     if(rr>0)
    {Serial.println( "1");
      if ( y>0 && y2<=6)
      {
        y=y-1.75*tan(i*0.0174533);
        y2=y2+1.75*tan(i*0.0174533);
        cr(x,y);
   
      }
      if( y==0 && y2<=6)
      {
        y2=y2+3.5*tan(i*0.0174533);
       
      }
      if ( y>0 && y2==6)
      {
        y=y-3.5*tan(i*0.0174533);
        
      }
      Serial.println(y);
      Serial.println(y2); 
    }
    else if(rr<0)
    {Serial.println( "2");
      if ( y<7 && y2>0)
      {
        y=y+1.75*tan(i*0.0174533);
        y2=y2-1.75*tan(i*0.0174533);
      }
      if( y==7 && y2>0)
      {
        y2=y2-3.5*tan(i*0.0174533);
      }
      if ( y<7 && y2==0)
      {
        y=y+3.5*tan(i*0.0174533);
      }
       Serial.println(y);
      Serial.println(y2); 
    }
    Serial.println(y);
      Serial.println(y2); 
    Serial.println(i);
    cr(x,y);
   cl(x2,y2);
   fa1=fa1-i;
   fa2=fa2-i; 
   t2.write(ta2);               
   k2.write(ka2);
   a2.write(aa2);
   t1.write(ta1);               
   k1.write(ka1);
   a1.write(aa1);
   f1.write(fa1);               
   f2.write(fa1);
   delay(0);
  }
 }
void setup()// **********************************************************************************************************************************************************************8
{ 
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
  f1.attach(3);
  w2.attach(12);
  t2.attach(11);
  k2.attach(10);
  a2.attach(9);
  f2.attach(8);

  {
       w1.write(wa1=90);
      f1.write(fa1=90);
      w2.write(wa2=90);               
      f2.write(fa2=90);
      t2.write(ta2=90);
      a2.write(aa2=90);
      t1.write(ta1=90);               
      k1.write(ka1=90);
      a1.write(aa1=90);
  }
       delay(500);
 // sf(1,3);
} 

void loop()// **********************************************************************************************************************************************************************8
{ 
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
  //sf(1,2);
 // ro(10);
 //ll(3);
 //////////////////////////////////////////////////////////////////////////////////right leg performing given function
for(x=-3;x<=3;x=x+0.2)  
 {
 
 y=6-1*sin(1.0472*x);              ///////sine
 //y=6-1*sqrt(1-((x*x)/(9)));     /////////ellips( uncomment to trace ellips and comment sine function (above line) and set the limits
  cr( x,y);
  t1.write(ta1);               
   k1.write(ka1);
   a1.write(aa1);
 delay(50);
 }
 for(x=3;x>=-3;x=x-0.2)
 {
 // y=6+2*sqrt(1-((x*x)/(9)));
 y=6-1*sin(1.0472*x);
  cr( x,y);
  t1.write(ta1);               
   k1.write(ka1);
   a1.write(aa1);
 delay(50);
 }
 //delay(1000);
  
  Serial.println("end****loop");


 int l=4;
 x=l;
 if((fstate==0)&&(bstate==1)&&(lstate==1)&&(rstate==1))//////example run
 {
  // this line of code will run on giving forward as input
 }
 //conditions          for         RC      module     input     (dfault input =1, when given input turns =0)
 //if((fstate==1)&&(bstate==0)&&(lstate==1)&&(rstate==1)) ///////////////////////////////////////////////////////////////////back
 //if((fstate==1)&&(bstate==1)&&(lstate==0)&&(rstate==1)) ///////////////////////////////////////////////////////////////////turnleft
 //if((fstate==1)&&(bstate==1)&&(lstate==1)&&(rstate==0)) ///////////////////////////////////////////////////////////////////turnright
 //if((rstate==0)&&(bstate==0))//////////////////////////////////////////////////////////////////////////////////////////////lean pick right
 //if((lstate==0)&&(bstate==0))//////////////////////////////////////////////////////////////////////////////////////////////flat slid
 
}

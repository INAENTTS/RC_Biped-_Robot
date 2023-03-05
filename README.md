# RC_Biped-_Robot  
designed and build radio controlled biped (two legged ) robot   
aim was to achive a robot which I can develop (implement new things) furthe.  
 Link to Youtube Video on my channel :  https://youtu.be/LNznLZhhkq8  
Build with:  

    Sg90 servo motors: these motors have very low torque and have poor design therefor I had to modify (can work without
        modification also) the motor they are nearly square withe some space left empty,I rearange the components in it and made it
        rectangular as it was required . 
    Arduino: Used for controlling the servos.
    MPU6050: I tried to add self balance to the robot.
    RC module: To controll the robot externaly i used the simle rc module of a rc car (Right,Left,Forward,Backwards) and I was
        able to give 8 comands.
Problems:  

  Motors:  
  The aim of modifying the servo was to make it fit properly in a small robot so that it dose not look bulky it did not
           improve its functioning but improved structurally  
  code:  
  firstly controled the motor by directly giving the angles (using while loops) and defined limits by observations
         secondy used the polar co-ordinates for each leg to define its position in its palne, this enabled to define the motions
         using functions, here I have directly solved the equations for the angels of the thee servo motor as afunction of the co
         ordinates of end point (one can use invers kinematics) 

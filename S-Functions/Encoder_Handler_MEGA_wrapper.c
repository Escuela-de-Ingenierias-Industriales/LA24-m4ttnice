
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <math.h>

# ifndef MATLAB_MEX_FILE
# include <Arduino.h>


//#define pinA1 27
//#define pinB1 26

//#define pinA2 25
//#define pinB2 33

typedef struct { int pinA; int pinB; int pos;} Encoder;    
volatile Encoder Enc[2] = {{0,0,0}, {0,0,0}};

/* auxiliary function to handle encoder attachment           */
int getIntNum(int pin) {
/* returns the interrupt number for a given interrupt pin 
   see http://arduino.cc/it/Reference/AttachInterrupt        */
switch(pin) {
  case 2:
    return 0;
  case 3:
    return 1;
  case 21:
    return 2;
  case 20:
    return 3;
  case 19:
    return 4;
  case 18:
    return 5;   
  default:
    return -1;
  }
}


/* Interrupt Service Routine: change on pin A for Encoder 0  */
void irsPinAEn0(){

  /* read pin B right away                                   */
  int drB = digitalRead(Enc[0].pinB);
  
  /* possibly wait before reading pin A, then read it        */
  int drA = digitalRead(Enc[0].pinA);

  /* this updates the counter                                */
  if (drA == HIGH) {   /* low->high on A? */
      
    if (drB == LOW) {  /* check pin B */
  	Enc[0].pos++;  /* going clockwise: increment         */
    } else {
  	Enc[0].pos--;  /* going counterclockwise: decrement  */
    }
    
  } else {                       /* must be high to low on A */
  
    if (drB == HIGH) { /* check pin B */
  	Enc[0].pos++;  /* going clockwise: increment         */
    } else {
  	Enc[0].pos--;  /* going counterclockwise: decrement  */
    }
    
  } /* end counter update                                    */

} /* end ISR pin A Encoder 0                                 */



/* Interrupt Service Routine: change on pin B for Encoder 0  */
void isrPinBEn0(){ 

  /* read pin A right away                                   */
  int drA = digitalRead(Enc[0].pinA);
  
  /* possibly wait before reading pin B, then read it        */
  int drB = digitalRead(Enc[0].pinB);

  /* this updates the counter                                */
  if (drB == HIGH) {   /* low->high on B? */
  
    if (drA == HIGH) { /* check pin A */
  	Enc[0].pos++;  /* going clockwise: increment         */
    } else {
  	Enc[0].pos--;  /* going counterclockwise: decrement  */
    }
  
  } else {                       /* must be high to low on B */
  
    if (drA == LOW) {  /* check pin A */
  	Enc[0].pos++;  /* going clockwise: increment         */
    } else {
  	Enc[0].pos--;  /* going counterclockwise: decrement  */
    }
    
  } /* end counter update */

} /* end ISR pin B Encoder 0  */

/* Interrupt Service Routine: change on pin A for Encoder 1  */
void irsPinAEn1(){

  /* read pin B right away                                   */
  int drB = digitalRead(Enc[1].pinB);
  
  /* possibly wait before reading pin A, then read it        */
  int drA = digitalRead(Enc[1].pinA);

  /* this updates the counter                                */
  if (drA == HIGH) {   /* low->high on A? */
      
    if (drB == LOW) {  /* check pin B */
  	Enc[1].pos++;  /* going clockwise: increment         */
    } else {
  	Enc[1].pos--;  /* going counterclockwise: decrement  */
    }
    
  } else { /* must be high to low on A                       */
  
    if (drB == HIGH) { /* check pin B */
  	Enc[1].pos++;  /* going clockwise: increment         */
    } else {
  	Enc[1].pos--;  /* going counterclockwise: decrement  */
    }
    
  } /* end counter update                                    */

} /* end ISR pin A Encoder 1                                 */


/* Interrupt Service Routine: change on pin B for Encoder 1  */
void isrPinBEn1(){ 

  /* read pin A right away                                   */
  int drA = digitalRead(Enc[1].pinA);
  
  /* possibly wait before reading pin B, then read it        */
  int drB = digitalRead(Enc[1].pinB);

  /* this updates the counter                                */
  if (drB == HIGH) {   /* low->high on B? */
  
    if (drA == HIGH) { /* check pin A */
  	Enc[1].pos++;  /* going clockwise: increment         */
    } else {
  	Enc[1].pos--;  /* going counterclockwise: decrement  */
    }
  
  } else { /* must be high to low on B                       */
  
    if (drA == LOW) {  /* check pin A */
  	Enc[1].pos++;  /* going clockwise: increment         */
    } else {
  	Enc[1].pos--;  /* going counterclockwise: decrement  */
    }
    
  } /* end counter update                                    */

} /* end ISR pin B Encoder 1                                 */

# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 2

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void Encoder_Handler_Mega_Outputs_wrapper(int32_T *pos,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
/* wait until after initialization is done */
if (xD[0]==1) {
    
    /* don't do anything for mex file generation */
  
    # ifndef MATLAB_MEX_FILE
            
        /* get encoder position and set is as output */
        pos[0]=Enc[0].pos;
        pos[1]=Enc[1].pos;
    # endif
    
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void Encoder_Handler_Mega_Update_wrapper(int32_T *pos,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {
    
    /* don't do anything for MEX-file generation */
    # ifndef MATLAB_MEX_FILE
    
        /* enc[0] is the encoder number and it can be 0,1 or 2   */
        /* if other encoder blocks are present in the model      */
        /* up to a maximum of 3, they need to refer to a         */
        /* different encoder number                              */
            
        /* store pinA and pinB in global encoder structure Enc   */
        /* they will be needed later by the interrupt routine    */
        /* that will not be able to access s-function parameters */   

    //Left Encoder

        Enc[0].pinA=27;      /* set pin A1               */
        Enc[0].pinB=26;      /* set pin B1              */
    //Right Encoder
        Enc[1].pinA=25;      /* set pin A2               */
        Enc[1].pinB=33;      /* set pin B2              */


        /* set encoder pins as inputs                     */
    //Left Encoder
        pinMode(Enc[0].pinA, INPUT); 
        pinMode(Enc[0].pinB, INPUT); 
    //Right Encoder
        pinMode(Enc[1].pinA, INPUT); 
        pinMode(Enc[1].pinB, INPUT); 
        
        /* turn on pullup resistors                              */
    //Left Encoder 
        digitalWrite(Enc[0].pinA, HIGH); 
        digitalWrite(Enc[0].pinB, HIGH); 
    //Right Encoder 
        digitalWrite(Enc[1].pinA, HIGH); 
        digitalWrite(Enc[1].pinB, HIGH); 

///////

        /* attach interrupts                                     */
            attachInterrupt(getIntNum(Enc[0].pinA), irsPinAEn0, CHANGE);
            attachInterrupt(getIntNum(Enc[0].pinB), isrPinBEn0, CHANGE);

            attachInterrupt(getIntNum(Enc[1].pinA), irsPinAEn1, CHANGE);
            attachInterrupt(getIntNum(Enc[1].pinB), isrPinBEn1, CHANGE);



    ////////////

        # endif
    
    /* initialization done */ 
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}


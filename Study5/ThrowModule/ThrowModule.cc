
#include "ThrowModule.h"

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
ThrowModule::Init()
{
    
    OUTPUT_servo_position = GetOutputArray("OUTPUT_servo_position");
    
    INPUT_head_position = GetInputArray("INPUT_head_position");

    t = 0;
    
}


void
ThrowModule::Tick()
{
    
    
    
   
        
        float angle = INPUT_head_position[0];
        
        if(angle > 150 and angle < 210) {
        
        OUTPUT_servo_position[0] = angle;
        //OUTPUT_servo_position[0] = 160;
        OUTPUT_servo_position[1] = 100;
        OUTPUT_servo_position[2] = 160;
        
        }
        
    
   
    /**
        if(input_array_NbrMarkers[0] == 1) { // if found 1 marker -> Load position!
    
            OUTPUT_servo_position[0] = 180 + OUTPUT_focus_position[0];
            OUTPUT_servo_position[1] = 100;
            OUTPUT_servo_position[2] = 160;
            
    
        } else if (input_array_NbrMarkers[0] == 2) { // if found 2 markers -> Throw away!
        
            OUTPUT_servo_position[0] = 180 + OUTPUT_focus_position[0];
            OUTPUT_servo_position[1] = 200;
            OUTPUT_servo_position[2] = 200;
        
        } else {                           // else -> go to start position
    
            OUTPUT_servo_position[0] = 180 + OUTPUT_focus_position[0];
            OUTPUT_servo_position[1] = 180;
            OUTPUT_servo_position[2] = 180;
        }
      */
   
        //t = 0;
        
        
    
}


// Install the module. This code is executed during start-up.

static InitClass init("ThrowModule", &ThrowModule::Create, "Source/UserModules/ThrowModule/");



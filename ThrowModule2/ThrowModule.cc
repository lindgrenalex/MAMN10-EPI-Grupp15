
#include "ThrowModule.h"

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
ThrowModule::Init()
{
    
    input_array = GetInputArray("INPUT");

    OUTPUT_servo_position = GetOutputArray("OUTPUT_servo_position");
    
    OUTPUT_focus_position = GetOutputArray("FOCUS_POSITION");

    t = 0;
    
}


void
ThrowModule::Tick()
{
    
    if( t > 10) {
        
        OUTPUT_servo_position[0] = 180 + OUTPUT_focus_position[0];
        OUTPUT_servo_position[1] = 100;
        OUTPUT_servo_position[2] = 160;

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
   
        /**t = 0;
        
    } else {
        
        t++;
        
    }
*/
    
}


// Install the module. This code is executed during start-up.

static InitClass init("ThrowModule", &ThrowModule::Create, "Source/UserModules/ThrowModule/");




#include "ThrowModule.h"

// use the ikaros namespace to access the math library
// this is preferred to using <cmath>

using namespace ikaros;


void
ThrowModule::Init()
{
    
    input_array = GetInputArray("INPUT");
    input_array_NbrMarkers = GetInputArray("INPUT_NbrMarkers");
    // input_array_size = GetInputSize("INPUT1");

    // Get pointer to a matrix and treat it as a matrix. If an array is
    // connected to this input, size_y will be 1.

    // input_matrix = GetInputMatrix("INPUT2");
    // input_matrix_size_x = GetInputSizeX("INPUT2");
    // input_matrix_size_y = GetInputSizeY("INPUT2");

    // Do the same for the outputs

    output_array_Servo1 = GetOutputArray("OUTPUT_Servo1");
    
    output_array_Servo2 = GetOutputArray("OUTPUT_Servo2");
    
    output_array_Servo3 = GetOutputArray("OUTPUT_Servo3");

    t = 0;
    
}


void
ThrowModule::Tick()
{
    
    if( t > 20) {
    
        if(input_array_NbrMarkers[0] == 1) { // if found 1 marker -> Load position!
    
            output_array_Servo1[0] = 180;
            output_array_Servo2[0] = 100;
            output_array_Servo3[0] = 220;
    
        } else if (input_array_NbrMarkers[0] == 2) { // if found 2 markers -> Throw away!
        
            output_array_Servo1[0] = 180;
            output_array_Servo2[0] = 200;
            output_array_Servo3[0] = 255;
        
        } else {                           // else -> go to start position
    
            output_array_Servo1[0] = 180;
            output_array_Servo2[0] = 180;
            output_array_Servo3[0] = 180;
        }
    
        printf("Number of found markers = %f \n", input_array_NbrMarkers[0]);
      
        t = 0;
        
    } else {
        
        t++;
        
    }

    
}


// Install the module. This code is executed during start-up.

static InitClass init("ThrowModule", &ThrowModule::Create, "Source/UserModules/ThrowModule/");



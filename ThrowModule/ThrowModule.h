
#ifndef ThrowModule_
#define ThrowModule_

#include "IKAROS.h"

class ThrowModule: public Module
{
public:
    static Module * Create(Parameter * p) { return new ThrowModule(p); }

    ThrowModule(Parameter * p) : Module(p) {}
    virtual ~ThrowModule() {};
    

    void 		Init();
    void 		Tick();

    // pointers to inputs and outputs
    // and integers to represent their sizes

    float *     input_array;
    float *     input_array_NbrMarkers;
    
    float *     output_array_Servo1;
    float *     output_array_Servo2;
    float *     output_array_Servo3;

    // parameter values

    int       int_start_parameter;
    int       t;
};

#endif

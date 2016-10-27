
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
    
    float *     output_servo_positions;
    /** //Float position not needed?
    float *     focus_position;
     */

    // parameter values

    int       int_start_parameter;
    int       t;
};

#endif

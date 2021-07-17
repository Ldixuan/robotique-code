#include<cmath>

class PID{
    public:
        PID(float p, float i, float d);
        double compute(double e, ros::Time t);
        void init(ros::Time t);

    private:
        float kp;
        float ki;
        float kd;
        ros::Time previous_time;

        float integral = 0;
        float previous_error = 0;
};

PID::PID(float p, float i, float d){
    kp = p;
    ki = i;
    kd = d;
}

//Summary:  init the control PID
void PID::init(ros::Time t){
    
    previous_time = t;

    integral = 0;
    previous_error = 0;
}

//Summary:  compute the value of pid

//Parameters:

//  e : the error

//  t : the time current

//Return : the error of angle current.
double PID::compute(double e, ros::Time t){

    auto dt = (t - previous_time).toSec();
    //auto dt = 0.1;
    float derivative;
    double output;
    integral = integral + e * dt;
    derivative = (e - previous_error) / dt;
    output = (kp * e) + (ki * integral) + (kd * derivative);
    previous_error = e;
    previous_time = t;

    return output;
}

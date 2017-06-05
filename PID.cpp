#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    Kp_=Kp;
    Ki_=Ki;
    Kd_=Kd;
    p_error_=0;
    d_error_=0;
    i_error_=0;
    param_index_=0;

}

/*
void PID::Twiddle(double cte){

    if(param_index_>2) param_index_=0;
    if(param_index_==0) param_= &Kp_;
    if(param_index_==1) param_= &Ki_;
    if(param_index_==2) param_= &Kd_;
    cout<<"Param Index="<<param_index_<<" Step="<<step_count_<<" cte="<<cte<<" best error="<<best_error_<<" param value="<<*param_<<endl;
    if(step_count_==0){
        *param_=*param_+ Dp_[param_index_];
        step_count_++;
    }
    if(step_count_==1){
        if(cte<best_error_){
            best_error_=cte;
            Dp_[param_index_]=Dp_[param_index_]*1.1;
            step_count_=0;
            param_index_++;
        }else{
            *param_=*param_-2*Dp_[param_index_];
            step_count_++;
        }
    }
    if(step_count_==2){
        if(cte<best_error_){
            best_error_=cte;
            Dp_[param_index_]=Dp_[param_index_]*1.1;
        }else{
            *param_=*param_+ Dp_[param_index_];
            Dp_[param_index_]=Dp_[param_index_]*0.9;
        }
        step_count_=0;
        param_index_++;
    }
}

*/

void PID::UpdateError(double cte) {
    int_cte_=int_cte_+cte;
    double diff_cte=cte-prev_cte_;
    prev_cte_=cte;
    p_error_=-Kp_*cte;
    d_error_=-Kd_*diff_cte;
    i_error_=-Ki_*int_cte_;
}

double PID::TotalError() {
    return p_error_ + i_error_ + d_error_;
}


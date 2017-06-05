#ifndef PID_H
#define PID_H
#include<iostream>

using namespace std;
class PID {
public:
  /*
  * Errors
  */
  double p_error_;
  double i_error_;
  double d_error_;

  /*
  * Coefficients
  */
  double Kp_;
  double Ki_;
  double Kd_;

  double int_cte_=0;
  double prev_cte_=0;

  /*
  * Constructor
  */

  double best_error_=10000;
  int param_index_=0;
  int step_count_=0;
  double *param_;
  double Dp_[3]={0.1,0.1,0.1};

  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  void Twiddle(double cte);
};

#endif /* PID_H */

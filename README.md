----------

PID Controller	
----------

A Proportional-Integral-Derivative controller is  common industrial control system based on control loop feedback mechanism.  

The controller produces an output corresponding to the cross track error. The sensitivity and responsiveness of the controller is tuned by adjusting the following parameters:

**Proportional Gain Tuning Parameter (Kp)**- The proportional gain produces an output that is directly proportional to the current cross track error.  A large value of the Kp leads to faster and pronounced oscillations causing the car to run out of the road,   A small value did not provide adequate steering angle correction and car gradually ran out of the road. A value of 0.20 was selected based on trail and error.  The following animation shows the behavior of car with just a Proportional gain controller. Notice the large oscillations

![enter image description here](https://github.com/karamadai/PID-Controller/blob/master/P_Controller.gif?raw=true)

**Derivative Gain Tuning Parameter (Kd)**- The derivative gain is directly proportional to the rate of the change of the cross track error. The derivative gain helps reduce the settling time and minimize the oscillations that is created by the Proportional Gain term (Kd).  The value of Kd tuning parameter is to 3.  A very small value does not provide adequate dampening of the oscillations while a very large value tends to makes the controller less responsive and eventually the car runs off the road. The following animation shows the car with a PD controller. The Derivative Gain dampens the oscillations:

![enter image description here](https://github.com/karamadai/PID-Controller/blob/master/PD_Controller.gif?raw=true)

**Integral Gain Tuning Parameter (Ki)**- The integral gain is the sum of the instantaneous error over time and helps reduce residual error due to offset in the wheel alignment. Since the simulator was expected to have very small offset, the Ki parameter was to 0.006. A large value of Ki has an effect of over correcting and gradually running the car of the road over time due to accumulation of the errors. A very small or zero value of the Ki slows the minimization of the cross track error.  The following animation shows the car with PID controller. 

![enter image description here](https://github.com/karamadai/PID-Controller/blob/master/PID_Controller.gif?raw=true)

**Throttle adjustment**: In order to make the ride smoother the throttle is adjusted to be proportional the steering value (main.cpp line 68). The thottle is set to 0.1 when the steering angle is at the max (-1 or 1) and proportional increased to a max value of 0.3 as the steering angle is approaches 0.

**Parameter Tuning Method**: The parameters Kp, Ki and Kd were manually tuned using a process similar to that used by Twiddle method.  The values were initially set to 0s. The value of Kp and Kd was initially adjusted leaving Ki at 0 until a satisfactory ride was obtained. The value of Ki was then increased to further stabilize the ride.


# Differential-Drive-Robot

**OBJECTIVE**:

The main goal of this project was to create a P-controller for a differential-drive mobile robot that would assist in achieving the desired reference position.This implies that achieving reference orientation **was not required**.

**BASIC EXPLAINATION**:

Controllers are implemented in the MATLAB environment.The Orientation and Forward controllers generate v(t) and w(t), respectively, which are converted to the wheel velocities vL and vR to provide input to the motors.

As Zumo only accepts input in the form of a PWM signal, which ranges from 0 to 400, it is required to relate the wheel velocities to the PWM signal.

As the controller is implemented in MATLAB, the command is sent from MATLAB by establishing bi-directional Bluetooth communication.

For the feedback part, the gyro and encoders are used to provide the yaw and current distance covered by the encoder. This information is transmitted to MATLAB via Bluetooth in order for it to calculate the error and output the control inputs.

![image](https://user-images.githubusercontent.com/107303057/173319142-b4f89586-8604-4bf6-8492-423b6b32e4c1.png)

**THE CODE**:

There are two folders named "_combined controllers_" and "_separate controllers_." The first folder contains the code for the separate testing for each controller, i.e., forward controller and orientation controller. The second folder contains the code in which, after initial testing, both controllers were combined and were working together. 

**PRECISION**:

The robot's barely moving when PWM signal decreases below 50. Therefore, the precise goal position was not achieved, i.e., the robot stopped before the defined goal position.

![image](https://user-images.githubusercontent.com/107303057/173319599-d0771f52-99ec-4d03-a8fd-f8aa33e27190.png)
![image](https://user-images.githubusercontent.com/107303057/173319840-52266414-b262-4d28-ac9d-6598f60a322d.png)


# Differential-drive-robot

**OBJECTIVE**:

The main goal of this project was to create a P-controller for a differential-drive mobile robot that would assist in achieving the desired reference position.This implies that achieving reference orientation **was not required**.

**BASIC EXPLAINATION**:

Controllers are implemented in the MATLAB environment.The Orientation and Forward controllers generate v(t) and w(t), respectively, which are converted to the wheel velocities vL and vR to provide input to the motors.

As Zumo only accepts input in the form of a PWM signal, which ranges from 0 to 400, it is required to relate the wheel velocities to the PWM signal.

As the controller is implemented in MATLAB, the command is sent from MATLAB by establishing bi-directional Bluetooth communication.

For the feedback part, the gyro and encoders are used to provide the yaw and current distance covered by the encoder. This information is transmitted to MATLAB via Bluetooth in order for it to calculate the error and output the control inputs.

**THE CODE**:

There are two folders named "combined controller" and "separate controllers." The first folder contains the code for the separate testing for each controller, i.e., forward controller and orientation controller. The second folder contains the code in which, after initial testing, both controllers were combined and were working together. 

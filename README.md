# Differential-drive-robot
The main goal of this project was to create a P-controller for a differential-drive mobile robot that would assist in achieving the desired reference position.This implies that achieving reference orientation **was not required**.

Following is the basic explaination of how it works:

Controllers are implemented in the MATLAB environment.The Orientation and Forward controllers generate v(t) and w(t), respectively, which are converted to the wheel velocities vL and vR to provide input to the motors.

As Zumo only accepts input in the form of a PWM signal, which ranges from 0 to 400, it is required to relate the wheel velocities to the PWM signal.

As the controller is implemented in MATLAB, the command is sent from MATLAB by establishing bi-directional Bluetooth communication.

For the feedback part, the gyro and encoders are used to provide the yaw and current distance covered by the encoder. This information is transmitted to MATLAB via Bluetooth in order for it to calculate the error and output the control inputs.

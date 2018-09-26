# Remote Controlled Gate

This is a simple project that implements an IR receiver and remote to drive a servo motor. The servo motor in this case is connected to a roll up gate, which drives it up and down to open and close the gate in response to a signal from the remote.
There are two different implementations for this project.

## Implemetation 1: Fixed Rotation

In the first implementation, which can be found [here](rc_gate/rc_gate_one_press/rc_gate_one_press.ino), the number of rotations of the motor is fixed. This allows for the gate to be opened or closed at the single push of a button, but requires that the number of rotations the motor must make to fully open or close the gate is known before the system is installed. It's a small prerequisite which adds convenience to the end user, but requires custom measurements for each application.

## Implementation 2: Continuous Rotation

For [this implementation](rc_gate/rc_gate_continous_press/rc_gate_continous_press.ino), the user must press and hold on to the button to open or close the gate. It gets rid of the need to know how many rotations are needed for the gate to fully open/close, and also adds the analog ability to open the gate to any varying degree, ie only halfway open, a third closed, and so forth. This can be beneficial for particular use cases. However, it also means one has to keep one's finger on the button for the duration of the entire process. Depending on how nitpicky one is, this might be seen as an inconvenience.

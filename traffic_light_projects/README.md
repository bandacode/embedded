# Traffic Lights Projects

There are many different ways in which traffic light systems are implemented. Relays and timer circuits are used, programmable logic controllers, but the simplest way for a hobbyist or beginner to do so is using a microcontroller.

This project contains 3 different implementations of a traffic light system:

## Implementation 1: Simple 4-Way Traffic Lights

[This implementation](traffic_light_projects/traffic_lights/traffic_lights.ino) is just as the title imples, a simple 4-way traffic light system. The 4-way traffic lights switch in pairs, so their inputs are connected as such, one input signalling two lights pointing at both incoming and outgoing traffic.
You need 4 pairs of 3 red, yellow and green LEDs each, for each lane of our 4-way intersection, for a total of 12 LEDs. Since the LEDs are switching in pairs, only 6 inputs to the microcontroller are used.
When the connections have been made, all that is left is to send ON/OFF signals to the LEDs as needed, while adding a delay before switching colours.

## Implementation 2: Traffic Lights With Countdown

In [this implementation](traffic_light_projects/traffic_lights_with_countdown/traffic_lights_with_countdown.ino), we have the same 4-way implementation as before, but with the addition of a 7-segment display. This display is used to show a countdown to let motorists know how long to wait before they get their turn to go. Knowing is can help reduce anxiety in motorists that might be tempted to skip red lights, or race through amber lights.
The code remains fundamentally the same, with the only difference being that the time delay is added in a loop of its own as a 1 second delay, to allow for the counter to change the displayed number at the end of each cycle.

## Implemetation 3: Traffic Lights With Sensor

[This implementation](traffic_light_projects/traffic_lights_and_sensor/traffic_lights_and_sensor.ino) is an isolated one traffic light system set up in a test environment with an ultrasonic sensor used to determine whether there is a car approaching the lights, and if so, how far away it is. The distance is used to determine what traffic light to show.
In its fully implemented form, it would check to see which side has more traffic by the frequency of hits the sensor gets, and use this information to determine which side gets the green light, and for how long they get to go.

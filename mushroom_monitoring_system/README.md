# Mushroom Monitoring System

This is a project for creating your own small mushroom monitoring system. Myshrooms have specific humidity and temperature conditions which enable them to grow optimally. In this project, we use an Arduino, a DHT11 temperature and humodity sensor, a light bulb, and a fan to monitor and control the conditions in a closed loop system.

The DHT11 monitors temperature and humidity, relaying this information to the microcontroller. The microcontroller then checks to see the set points for temperature and humidity, triggering the light bulb when the temperature is too low, or the fan when the temperature is too high. It also has a pump hooked up to a spraying mechanism which activates to spray in some water when humidity is too low.

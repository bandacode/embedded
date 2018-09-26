# Water Level Remote Monitoring

This is a system which can be used to remotely monitor the water levels in a tank or reserve which may be far away, or not easily accessible, like for instance an elevated tank, or an underground water reserve.

Two Arduinos are used: one on the water tank, and another on the receiving end. The Arduino at the tank has an ultrasonic sensor mounted at the top of the tank, which measures the distance from the top to the water level, and uses this to find out how much water is in the tank. This reading is then transmitted to the receiver Arduino wirelessly and displayed on a monitor.

There are two different implementations for the mode of wireless transfer: one uses [RF modules](water_level_reader/water_level_rx_rf/water_level_rx_rf.ino), and the other uses [XBee](water_level_reader/water_level_rx_xbee/water_level_rx_xbee.ino). Aside from the technology used for the wireless transfer, these implementations are identical in every other way. Its only about preference and using what's readily available. RF modules are quite cheap and easy to use, and can transmit up to 1km radius, but are not as reliable as XBee modules. The XBee modules, however, cost more than the RF modules, with prices going up depending on range. However, you can get affordable ones that offer a range of up to 800m.

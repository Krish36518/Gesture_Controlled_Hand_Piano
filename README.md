# Gesture_Controlled_Hand_Piano
It is a Gesture Controlled Hand piano which uses ultrasonic sensors. it measure the stable distance and also the distance with a movement  and according to eat plays various frequencies on the buzzer

It is a prototype which uses 4 ultrasnoic sensors each assigned to a particular finger. At starting the hand is positioned still at any distance from any surface(preferably a flat surface). After which it computes in loops and finds out in which of the ultrasnoic sensors the distance is getting updated which indicates the movement of that particular finger. 
After detecting the movement of that finger ,the signal is sent to the microcontroller(Arduino Uno here) and it plays the key assigned to that particular finger by use of varying of frequencies.

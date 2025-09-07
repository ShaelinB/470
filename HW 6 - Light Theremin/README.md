# HW 6: Light Theremin
Hello there, come with me as I make a Light Theremin.

## Materials

The materials needed for this project were the Arduino Uno, breadboard, a piezo, a phototransistor, 10 Kohm resistor, and jumper wires.

<img src="Materials.jpeg" alt="Materials" width = 500>

If you want to create it in TinkerCad the materials are listed below.

<img src="Components.png" alt="Components" width = 1000>

## Creating the Circuit

Before building the circuit, I had to make sure any battery or USB was disconnected.

Step 1: I connected power and ground to the breadboard from the 5V and GND pin.

<img src="Connecting Power.jpeg" alt="Connecting Power" width = 500>

Step 2: I connected my piezo to the breadboard and connected one end to ground and the other end to digital pin 8.
Piezo's are not polarized so it doesn't matter what side is connected to what.

<img src="Connecting Piezo.jpeg" alt="Connecting Piezo" width = 500>

Step 3: I connected my phototransistor onto the breadboard.
I took a jumper wire and connected the anode to power.
Then, I took another jumper wire and connected the cathode to pin A0 and to ground through a 10 Kohm resistor.

<img src="Final.jpeg" alt="Final" width = 500>

Step 4: I uploaded the code provided for this exercise to the Arduino.

<img src="Code.png" alt="Code" width = 500>

Now I have completed the Light Theremin. 
As you can see the piezo plays a certain sound when the amount of light that hits the phototransistor changes.

The video below demonstrates this.

[![Mood Cue](https://img.youtube.com/vi/a3dka9c7Xn4/0.jpg)](https://youtu.be/a3dka9c7Xn4)

Below is also a schematic view of the project as well.

<img src="Schematic.png" alt="Schematic" width = 1000>

## Summary

Overall, in this chapter I learned how to make a Light Theremin that produces a sound from the piezo in response to the amount of light the phototransistor receives.
Also, the real life circuit sounds a lot better than the TinkerCad circuit.

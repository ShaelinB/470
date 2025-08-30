# HW 1: Get to Know Your Tools
Hello there, come with me as I make an interactive circuit that turns a LED on when a button is clicked.

## Materials

The materials needed for this project were the Arduino Uno, breadboard, 220 ohm resistor, jumper wires, buttons, and a LED.
The reason I used a resistor is so the LED doesn't burn out due to the high current.

<img src="Materials.jpeg" alt="Materials" width = 500>

## Creating the Circuit

Before building the circuit I had to make sure any battery or USB was disconnected.

Step 1: I connect the red wire to the 5V pin on the Arduino and put the other end in one of the positive long bus lines in the breadboard. 

The red wire is used for power.

<img src="Step 1.jpeg" alt="Step 1" width = 500>

Step 2: I placed the switch across the center of the board. The legs pointed away from the center.

<img src="Step 2.jpeg" alt="Step 2" width = 500>

Step 3: I placed a 220 ohm resistor to connect power to the positive long bus line to one side of the switch.

<img src="Step 3.jpeg" alt="Step 3" width = 500>

Step 4: I added a LED below the left side of the switch with the anode (long leg) facing the top of the board and the cathode (short leg) facing the bottom. 

<img src="Step 4.jpeg" alt="Step 4" width = 500>

Step 5: I placed a jumper wire from the bottom left of the switch to the anode.

<img src="Step 5.jpeg" alt="Step 5" width = 500>

Step 6: I connected the black wire to the ground pin on the Arduino and put the other end in the pin next to the red wire making sure it's in the negative long bus line in the breadboard. 

The black wire is used for ground.

<img src="Step 6.jpeg" alt="Step 6" width = 500>

Step 7: I added a jumper wire from the cathode to the negative long bus line.

<img src="Step 7.jpeg" alt="Step 7" width = 500>

Now I have a completed circuit. 
If I hit the button the circuit will be closed and light the LED.

The video below demonstrates that.

[![LED Circuit](https://img.youtube.com/vi/xkGslWw7OxY/0.jpg)](https://youtu.be/xkGslWw7OxY)

## Series Circuit

Now I'm going to show you a series circuit.

[![LED Series Circuit](https://img.youtube.com/vi/zxkcj5QQifY/0.jpg)](https://youtu.be/zxkcj5QQifY)

As you can see the series circuit involves two buttons. 
A series circuit is when electrical current runs through both switches at the same time.
Think of a series circuit as an AND gate. 
You need both buttons to be pressed in order for the LED to light up.

## Parallel Circuit

Now there is also a parallel circuit.

[![LED Parallel Circuit](https://img.youtube.com/vi/axod5nDe9mM/0.jpg)](https://youtu.be/axod5nDe9mM)

It still has two buttons like a series circuit but instead of it being like an AND gate it's an OR gate. 
A parallel circuit is when electrical current is split between two switches.
Only one of the buttons needs to be held in order for the LED to light up.
Though it still lights up when both are pressed. 

## Summary

Overall, in this chapter I learned how to make a circuit that involves interactivity in order for something to happen. 
In this case lighting up an LED. 
I also learned the difference between a series and parallel circuit. 
While doing the project a lot of it was pretty straight forward the main problem for me was trying to figure out which one was the 220 ohm resistor. 
I used the chart in the book but the colors looked very similar. 
Overall, it was an educational experience. 

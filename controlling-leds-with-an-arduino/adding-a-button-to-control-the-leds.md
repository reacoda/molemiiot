---
description: >-
  For this activity, we will exploring the use of an input device (a button) to
  interact with output devices (the LEDs).
---

# Adding a button to control the LEDs

Now that ****you know the basics, let’s improve it. Add in a pushbutton to control the LEDs whenever you want.  
  
The circuit for the LEDs is exactly the same as the activity above. Connect the button to digital pin 12. You’ll notice that the switch has a high-impedance 10k ohm resistor attached to it. This is called a pull-down resistor.



![Using a pushbutton to control the LEDs](https://lh3.googleusercontent.com/2-6dC8A3bK14AiMGicSp5yQoceandE7aAavxkBI73enCsHlmhw9OBShkDqNnN3sc-p1CwBCkpGy7Vvif6lX7Nz-J7kGwsy5j5ccd9cwq_Q1pQeuRZUgC_KURc3gHsP209zsuKFbd)

A switch either lets the current flow, or doesn’t. This seems simple enough, but in a logic circuit, the current should be always flowing in either a high or low state \(remember – 1 or 0, high or low\). You might assume that a pushbutton switch that isn’t actually being pushed would be defined as being in a low state, but in fact it’s said to be ‘floating’, because no current is being drawn at all.

In this floating state, it’s possible that a false reading will occur as it fluctuates with electrical interference. In other words, a floating switch is giving neither a reliable high, nor low state reading. A pull-down resistor keeps a small amount of current flowing when the switch is closed, thereby ensuring an accurate low state reading. In other logic circuits, you may find a pull-up resistor instead – this works on the same principle, but in reverse, making sure that particular logic gate defaults to high.  


  



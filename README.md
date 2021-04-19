# iotdatatransfer

Aim: Transmit data using LED.
Components:
•	Two Arduino Uno boards.
•	Two resistors (10 kilo ohms and 220 ohms).
•	Two Breadboards.
•	Connecting (jumper) wires.
•	One LDR GM 5539.
•	One LED (Red Color).

Transmission of two bits at a time takes place by using Pulse Width Modulation (PWM).
Values used for thresh1 and comparison operations in get_info() function in receiver code may need to be changed considering the background light conditions and distance between  LDR and LED.

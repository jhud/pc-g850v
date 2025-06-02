# pc-g850v utilities

Programs for the SHARP PC-G850V pocket computer, plus interface board schematic.

Use at your own risk - I accept no responsibility for damage to yourself, others, or your hardware.


## Programs

### terminal.c

A terminal program to allow you to interact with the serial port, use telnet, dial BBSes, interact with remote computers, etc.

Some sources, ie BBSes, seem to freeze this program at higher baud rates (the program seems to get stuck waiting for a character that never comes) but 300 seems safe for everything.

Only uppercase and a subset of characters is supported at the moment - enough to write Hayes-style AT modem commands and interact with BBSes.


## Interface board

Output from the SIO is weird: it has 5v uart levels but inverted as in RS232. You need to invert all the signals, then you get standard 5v UART.

I've included a simple adapter board using a 7440 IC to flip the logic levels to standard UART.

The rts/cts lines seem to be needed for loading and saving.


## Other hardware notes

The power barrel jack on the calculator is negative tip, 8.5V.

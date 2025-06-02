# pc-g850v utilities
Programs for SHARP PC-G850V pocket computer, plus interface board schematic.

Use at your own risk - I accept no responsibility for damage to yourself or your hardware.

## Programs

### terminal.c

A terminal program to allow you to interact with the serial port, use telnet, dial BBSes, interact with remote computers, etc.

## Interface board

Output from the SIO is weird: it has 5v uart levels but inverted as in RS232. You need to invert all the signals, then you get standard 5v UART.

I've included a simple adapter board using a 7440 IC to flip the logic levels to standard UART.

The rts/cts lines seem to be needed for loading and saving.



## Other notes

The power barrel jack on the calculator is negative tip, 8.5V.

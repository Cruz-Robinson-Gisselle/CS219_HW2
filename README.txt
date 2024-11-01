How to run my code:
I have used a makefile to execute this program. To run the code, just make the executable by typing "make" into the terminal and then typing ./assembly (name of my executable).

Code working progress:
To figure out what the command and operands are, I created a function that take the data that I need from the txt file. I used getlines to store my information into my string
variables for the operands and command. Additionally, I pass two variables of type "long" in order to actually perform the operations given by the txt file. These variables are
made by taking the string versions of the operands and converting them into type "long." For the operations of addition, subtraction, and bitwise functions I use the
appropriate functions to perform the desired command and store the results of type type uint32_t to ensure that the answer stays in the form of 32-bits. I display the stored
values for the command and operand variables, as well as the sum of the operands by passing the sum into my function for displaying the hexadecimal value.

Results:
Each command does the following:
ADD/ADDS - adds two operands together
SUB/SUBS - subtracts two operands
AND/ANDS - Performs bitwise AND with two operands
ORR/ORRS - Performs bitwise OR with two operands
XOR/XORS - Performs bitwise XOR with operands
ASR/ASRS - Performs an arithmetic shift right by n bits, MSB is maintained
LSR/LSRS - Performs a logical shift right by n bits, a 0 is shifted into MSB
LSL/LSLS - Performs a logical shift left by n bits, a 0 is shifted into LSB

The results displayed in my terminal are correct and they also correctly display the changes in flag values after each operation. When a command ends with "S", my function
for checking the new flag values is called and changes them based off the result of the command. If the result is negative in the form of a signed number, the N flag changes
to 1, otherwise it changes to 0. If the result is equivalent to 0, the Z flag changes to 1, otherwise it changes to 0. I also made sure that the changes within the flag values persist during the commands that don't end with "S". This demonstrates that the commands without an "S" have no effect on the flag values.

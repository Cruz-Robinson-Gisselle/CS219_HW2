How to run my code:
I have used a makefile to execute this program. To run the code, just make the executable by typing "make" into the terminal and then typing ./assembly (name of my executable).

Code working progress:
To figure out what the command and operands are, I created a function that take the data that I need from the txt file. I used getlines to store my information into my string
variables for the operands and command. Additionally, I pass two variables of type "long" in order to actually perform the operations given by the txt file. These variables are
made by taking the string versions of the operands and converting them into type "long." For the operation of addition, I use my add fucntion to add the operands together and make 
the sum of type uint32_t to ensure that the answer stays in the form of 32-bits. I display the stored values for the command and operand variables, as well as the sum of the operands
by passing the sum into my function for displaying the hexadecimal value. To figure out if overflow happened, I take the longs representing my two operands, add them together, and 
then subtract that sum by the max value of uint32_t - 1. This ensures that the actual value of the sum is used while determining if the sum of the longs is equivalent to the 32-bit
sum of the operands.   

Results:
After running the code, the terminal should display the contents from the txt file input and it will show the correctly added operands for the ADD method. It'll also lidentify if
overflow occurred while adding the operands.
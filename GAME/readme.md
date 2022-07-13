
You are playing a video game in which several stacks of boxes are lined up on the floor, with a crane on top to rearrange the boxes, as shown in the picture below.

The crane supports the following commands:

• Move one position left (does nothing if already at the leftmost position)

• Move one position right (does nothing if already at the rightmost position)

• Pick up a box from the current stack (does nothing if the crane already has a box)

• Drop a box on the current stack (does nothing if the crane doesn't already have a box)

Further, there is a limit H on the number of boxes on each stack. If a 'drop' command would result in a stack having more than H boxes, the crane ignores this drop command. If the current stack has no boxes, a 'pick up' command is ignored.

You are given the initial number of boxes in each stack and the sequence of operations performed by the crane.

For example, suppose the initial configuration of the game is as shown in the figure above, with 7 stacks and H=4. Then, after the following sequence of instructions,

    Pick up box
    Move right
    Move right
    Move right
    Move right
    Drop box
    Move left
    Pick up box
    Move left
    Drop box

the number of boxes in each stack from left to right would be 2,1,3,1,4,0,1.

Input format
• Line 1 : The width of the game (the number of stacks of boxes), N, followed by the max height H of each stack.

• Line 2 : N integers, the initial number of boxes in each stack, from left to right. Each number is ≤ H.

• Line 3 : A sequence of integers, each encoding a command to the crane.

The commands are encoded as follows:

1 : Move left

2 : Move right

3 : Pick up box

4 : Drop box

0 : Quit

• The command Quit (0) appears exactly once, and is the last command.

• The initial position of the crane is above the leftmost stack, with the crane not holding any box.

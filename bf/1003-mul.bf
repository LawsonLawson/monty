,               ; Input a character and store its ASCII value in the current cell

>++++++++       ; Set the second cell to 8 (ASCII value for '\b')
[<------>-]     ; Subtract 8 from the first cell, effectively setting it to the input ASCII value - 8

,               ; Input another character and store its ASCII value in the current cell

>++++++++       ; Set the second cell to 8 again

[<------>-]     ; Subtract 8 from the first cell, effectively setting it to the input ASCII value - 8

<<              ; Move to the first cell

[               ; Loop until the cell is zero (while the first input is not equal to '\b')

    ->          ; Move to the second cell and decrement it (decrement the counter)
    [>+>+<<-]   ; Copy the counter value to the third and fourth cells
    >>          ; Move to the fourth cell
    [-<<+>>]    ; Subtract the value in the third cell from the first cell and add it to the fourth cell
    <           ; Move to the third cell
    [->>+<<]    ; Copy the value in the fourth cell to the third cell and move back to the first cell
    <<          ; Move to the first cell

]               ; End of the loop

>>>>>++++++++++ ; Move to the sixth cell and set it to 10 (ASCII value for '\n')

<               ; Move back to the first cell

[               ; Loop until the first cell is zero (while the second input is not equal to '\b')

    ->-         ; Decrement the counter in the second cell
    [>+>>]      ; Copy the counter value to the third cell
    >           ; Move to the third cell
    [
        +[-<+>] ; Add the counter value to the first cell and clear the third cell
        >+      ; Move to the second cell and increment it
        >>      ; Move to the fifth cell (counter)

    ]

    <<<<<       ; Move back to the first cell

]               ; End of the loop

>>>>++++++++    ; Move to the fifth cell and set it to 8

[<++++++>-]     ; Multiply the value in the sixth cell by 8

<.              ; Output the result as a character

<[->>+<<]       ; Copy the value in the fifth cell to the third cell and move back to the first cell

>>>++++++++    ; Move to the sixth cell and set it to 8

[<++++++>-]     ; Multiply the value in the sixth cell by 8

<.              ; Output the result as a character

>++++++++++.    ; Output a newline character


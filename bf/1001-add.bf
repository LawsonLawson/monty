,		Read a character from input
>,		Move to the next cell (Cell #1) and read another character from input
<		Move back to the original cell (Cell #0).
[->+<]		loop and perform the operation(addition)
>>++++++++	Move to Cell #3 (two cells to the right) and set its value to 8
[<------>-]	loop, subtract 6 from Cell #3 until it becomes zero.
<.		Print or output the result(ASCII)

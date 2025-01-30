OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
{
	. = 0x100000;
	.text : {*(.text)}
	.data : {*(.data)}
	.bss  : {*(.bss)}

	_stack_top = 0x00400000;
    _stack_bottom = _stack_top - 0x100000; /* 1MB stack */

    /* Define heap (starting after kernel & stack) */
    _heap_start = 0x00500000; /* 5MB mark */
    _heap_end = 0x067FFFFF; /* Allocate ~96MB for heap */
}
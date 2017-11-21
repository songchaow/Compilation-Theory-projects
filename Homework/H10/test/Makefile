all: probing_heap var_with_array

probing_heap: probing_heap.c
	gcc probing_heap.c -m32 -o probing_heap

var_with_array: var_with_array.c
	gcc var_with_array.c -m32 -fno-stack-protector -ggdb -o var_with_array
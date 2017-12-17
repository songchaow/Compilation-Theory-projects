assembly: test8-5 test8-5-no-abs test-supple test-supple-global-i

test8-5: test8-5.c
	gcc test8-5.c -o test8-5_gcc.out
	gcc -c -S test8-5.c -o assembly/test8-5_gcc.asm
	clang test8-5.c -o test8-5_clang.out
	clang -c -S test8-5.c -o assembly/test8-5_clang.asm

test8-5-no-abs: test8-5-no-abs.c
	gcc test8-5-no-abs.c -o test8-5-no-abs_gcc.out
	gcc -c -S test8-5-no-abs.c -o assembly/test8-5-no-abs_gcc.asm
	clang test8-5-no-abs.c -o test8-5-no-abs_clang.out
	clang -c -S test8-5-no-abs.c -o assembly/test8-5-no-abs_clang.asm

test-supple: test-supple.c
	gcc test-supple.c -o test-supple_gcc.out
	gcc -c -S test-supple.c -o assembly/test-supple_gcc.asm
	clang test-supple.c -o test-supple_clang.out
	clang -c -S test-supple.c -o assembly/test-supple_clang.asm

test-supple-global-i: test-supple-global-i.c
	gcc test-supple-global-i.c -o test-supple-global-i_gcc.out
	gcc -c -S test-supple-global-i.c -o assembly/test-supple-global-i_gcc.asm
	clang test-supple-global-i.c -o test-supple-global-i_clang.out
	clang -c -S test-supple-global-i.c -o assembly/test-supple-global-i_clang.asm
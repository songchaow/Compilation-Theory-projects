# Homework 1

> PB15000102
>
> 王嵩超

源代码

```c
int operation(int a, int b)
{
    if(a>5)
        return a*b;
    else
        return(a+b);
}
int main()
{
    int a=3,b=5;
    int c;
    c = operation(a,b);
    a+=3;
    c = operation(a,b);
}
```

用gcc -E选项的输出代码

```c
# 预处理信息：
# 1 "hello.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "hello.c"
int operation(int a, int b)
{
    if(a>5)
        return a*b;
    else
        return(a+b);
}
int main()
{
    int a=3,b=5;
    int c;
    c = operation(a,b);
    a+=3;
    c = operation(a,b);
}

```

用gcc -S (-m64)选项的输出代码

```asm
	.file	"hello.c"
	.text
	.globl	operation
	.type	operation, @function
operation:
.LFB0:
	.cfi_startproc #用来生成unwind table的directive
	pushq	%rbp #64位代码 栈寄存器rbp,esp寄存器有64位
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	#操作数仍为32位。int类型决定。
	movl	%edi, -4(%rbp) # a-> edi
	movl	%esi, -8(%rbp) # b-> esi
	cmpl	$5, -4(%rbp)
	jle	.L2
	movl	-4(%rbp), %eax 
	imull	-8(%rbp), %eax # a*b
	jmp	.L3
.L2:
	movl	-4(%rbp), %edx # a->edx
	movl	-8(%rbp), %eax # b->eax
	addl	%edx, %eax	   # eax = eax + edx
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	operation, .-operation
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp # 为局部变量分配空间
	movl	$3, -12(%rbp) # 3->a
	movl	$5, -8(%rbp)  # 5->b
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%edx, %esi #传递参数到寄存器
	movl	%eax, %edi
	call	operation
	movl	%eax, -4(%rbp) # operation -> c
	addl	$3, -12(%rbp)  # a+=3
	movl	-8(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	operation
	movl	%eax, -4(%rbp)
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits


```

用gcc -S -m32选项的输出代码

```gas
	.file	"hello.c"
	.text
	.globl	operation
	.type	operation, @function
operation:
.LFB0:
	.cfi_startproc #用来生成unwind table的directive
	pushl	%ebp #32位代码 ebp寄存器有32位
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	cmpl	$5, 8(%ebp)
	jle	.L2
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	jmp	.L3
.L2:
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
.L3:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	operation, .-operation
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax # store PC to %eax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	$3, -12(%ebp)
	movl	$5, -8(%ebp)
	pushl	-8(%ebp)
	pushl	-12(%ebp)
	call	operation
	addl	$8, %esp
	movl	%eax, -4(%ebp)
	addl	$3, -12(%ebp)
	pushl	-8(%ebp)
	pushl	-12(%ebp)
	call	operation
	addl	$8, %esp
	movl	%eax, -4(%ebp)
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB2:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE2:
	.ident	"GCC: (Ubuntu 6.2.0-5ubuntu12) 6.2.0 20161005"
	.section	.note.GNU-stack,"",@progbits
```
	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "w+b\0"
LC1:
	.ascii "out.txt\0"
LC2:
	.ascii "out1.txt\0"
LC3:
	.ascii "all good\0"
LC4:
	.ascii "something's wrong\0"
LC5:
	.ascii "%s\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$96, %esp
	call	___main
	movl	$LC0, 4(%esp)
	movl	$LC1, (%esp)
	call	_fopen
	movl	%eax, 92(%esp)
	movl	$0, 68(%esp)
	movl	$0, 72(%esp)
	movl	$0, 76(%esp)
	movl	$0, 80(%esp)
	movl	$0, 84(%esp)
	movl	$0, 48(%esp)
	movl	$0, 52(%esp)
	movl	$0, 56(%esp)
	movl	$0, 60(%esp)
	movl	$0, 64(%esp)
	movl	$0, 28(%esp)
	movl	$0, 32(%esp)
	movl	$0, 36(%esp)
	movl	$0, 40(%esp)
	movl	$0, 44(%esp)
	movl	$5, 24(%esp)
	movl	24(%esp), %eax
	movl	$20, 12(%esp)
	movl	$10, 8(%esp)
	movl	%eax, 4(%esp)
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	_fillArray
	movl	24(%esp), %eax
	movl	$20, 12(%esp)
	movl	$10, 8(%esp)
	movl	%eax, 4(%esp)
	leal	48(%esp), %eax
	movl	%eax, (%esp)
	call	_fillArray
	movl	24(%esp), %eax
	movl	$20, 12(%esp)
	movl	$10, 8(%esp)
	movl	%eax, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_fillArray
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	movl	92(%esp), %eax
	movl	%eax, 4(%esp)
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	_saveToFile
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	movl	92(%esp), %eax
	movl	%eax, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_saveToFile
	movl	92(%esp), %eax
	movl	%eax, 8(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	leal	68(%esp), %eax
	movl	%eax, (%esp)
	call	_loadFromFile
	movl	$LC0, 4(%esp)
	movl	$LC2, (%esp)
	call	_fopen
	movl	%eax, 88(%esp)
	movl	24(%esp), %eax
	movl	%eax, 8(%esp)
	movl	88(%esp), %eax
	movl	%eax, 4(%esp)
	leal	48(%esp), %eax
	movl	%eax, (%esp)
	call	_saveToFile
	movl	88(%esp), %eax
	movl	%eax, 8(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_loadFromFile
	movl	92(%esp), %eax
	movl	%eax, 8(%esp)
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	leal	48(%esp), %eax
	movl	%eax, (%esp)
	call	_loadFromFile
	movl	_saveCount, %eax
	cmpl	$3, %eax
	jne	L2
	movl	_loadCount, %eax
	cmpl	$3, %eax
	jne	L2
	movl	$LC3, %eax
	jmp	L3
L2:
	movl	$LC4, %eax
L3:
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	92(%esp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	88(%esp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.section .rdata,"dr"
LC6:
	.ascii "%d \0"
	.text
	.globl	_printArray
	.def	_printArray;	.scl	2;	.type	32;	.endef
_printArray:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L6
L7:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	addl	$1, -12(%ebp)
L6:
	movl	12(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jb	L7
	movl	$10, (%esp)
	call	_putchar
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.globl	_fillArray
	.def	_fillArray;	.scl	2;	.type	32;	.endef
_fillArray:
LFB20:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	movl	$0, (%esp)
	call	_time
	movl	%eax, (%esp)
	call	_srand
	movl	$0, -12(%ebp)
	jmp	L9
L10:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	leal	(%edx,%eax), %ebx
	call	_rand
	movl	%eax, %edx
	movl	20(%ebp), %eax
	subl	16(%ebp), %eax
	leal	1(%eax), %ecx
	movl	%edx, %eax
	cltd
	idivl	%ecx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
L9:
	movl	12(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jb	L10
	nop
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE20:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_saveToFile;	.scl	2;	.type	32;	.endef
	.def	_loadFromFile;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_srand;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef

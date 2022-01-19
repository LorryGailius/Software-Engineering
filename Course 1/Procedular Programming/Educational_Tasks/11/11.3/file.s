	.file	"file.c"
	.globl	_saveCount
	.bss
	.align 4
_saveCount:
	.space 4
	.globl	_loadCount
	.align 4
_loadCount:
	.space 4
	.text
	.globl	_saveToFile
	.def	_saveToFile;	.scl	2;	.type	32;	.endef
_saveToFile:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$4, 4(%esp)
	leal	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	movl	16(%ebp), %eax
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$4, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fwrite
	movl	_saveCount, %eax
	addl	$1, %eax
	movl	%eax, _saveCount
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.globl	_loadFromFile
	.def	_loadFromFile;	.scl	2;	.type	32;	.endef
_loadFromFile:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$1, 8(%esp)
	movl	$4, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	%edx, 8(%esp)
	movl	$4, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	movl	_loadCount, %eax
	addl	$1, %eax
	movl	%eax, _loadCount
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_fread;	.scl	2;	.type	32;	.endef

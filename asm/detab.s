	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$1024, %rsp             ## imm = 0x400
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -1012(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	$1000, %esi             ## imm = 0x3E8
	leaq	-1008(%rbp), %rdi
	callq	_k_and_r_getline
	movl	%eax, -1016(%rbp)
	cmpl	$0, %eax
	jle	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	$1000, %edx             ## imm = 0x3E8
	leaq	-1008(%rbp), %rdi
	movl	-1016(%rbp), %esi
	callq	_detab
	leaq	L_.str(%rip), %rdi
	leaq	-1008(%rbp), %rsi
	movb	$0, %al
	callq	_printf
	movl	%eax, -1020(%rbp)       ## 4-byte Spill
	jmp	LBB0_1
LBB0_3:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_5
## BB#4:
	xorl	%eax, %eax
	addq	$1024, %rsp             ## imm = 0x400
	popq	%rbp
	retq
LBB0_5:
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_k_and_r_getline
	.p2align	4, 0x90
_k_and_r_getline:                       ## @k_and_r_getline
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	xorl	%eax, %eax
	movl	$1000, %ecx             ## imm = 0x3E8
	movl	%ecx, %edx
	movq	$-1, %rcx
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rdi
	movl	%eax, %esi
	callq	___memset_chk
	movl	$0, -20(%rbp)
	movq	%rax, -32(%rbp)         ## 8-byte Spill
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	movl	-20(%rbp), %eax
	movl	-12(%rbp), %edx
	subl	$1, %edx
	cmpl	%edx, %eax
	movb	%cl, -33(%rbp)          ## 1-byte Spill
	jge	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	callq	_getchar
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movl	%eax, -16(%rbp)
	cmpl	$-1, %eax
	movb	%dl, -33(%rbp)          ## 1-byte Spill
	je	LBB1_4
## BB#3:                                ##   in Loop: Header=BB1_1 Depth=1
	cmpl	$10, -16(%rbp)
	setne	%al
	movb	%al, -33(%rbp)          ## 1-byte Spill
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	movb	-33(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB1_5
	jmp	LBB1_7
LBB1_5:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-16(%rbp), %eax
	movb	%al, %cl
	movslq	-20(%rbp), %rdx
	movq	-8(%rbp), %rsi
	movb	%cl, (%rsi,%rdx)
## BB#6:                                ##   in Loop: Header=BB1_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB1_1
LBB1_7:
	cmpl	$10, -16(%rbp)
	jne	LBB1_9
## BB#8:
	movl	-16(%rbp), %eax
	movb	%al, %cl
	movslq	-20(%rbp), %rdx
	movq	-8(%rbp), %rsi
	movb	%cl, (%rsi,%rdx)
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
LBB1_9:
	movslq	-20(%rbp), %rax
	movq	-8(%rbp), %rcx
	movb	$0, (%rcx,%rax)
	movl	-20(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_detab
	.p2align	4, 0x90
_detab:                                 ## @detab
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -28(%rbp)
	movl	$0, -32(%rbp)
	movl	$0, -36(%rbp)
LBB2_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB2_11 Depth 2
                                        ##     Child Loop BB2_17 Depth 2
	xorl	%eax, %eax
	movb	%al, %cl
	movl	-20(%rbp), %eax
	cmpl	-12(%rbp), %eax
	movb	%cl, -37(%rbp)          ## 1-byte Spill
	jge	LBB2_3
## BB#2:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	-20(%rbp), %eax
	movl	-16(%rbp), %ecx
	subl	$1, %ecx
	cmpl	%ecx, %eax
	setl	%dl
	movb	%dl, -37(%rbp)          ## 1-byte Spill
LBB2_3:                                 ##   in Loop: Header=BB2_1 Depth=1
	movb	-37(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB2_4
	jmp	LBB2_22
LBB2_4:                                 ##   in Loop: Header=BB2_1 Depth=1
	movl	$8, %eax
	movl	-24(%rbp), %ecx
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-44(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	cmpl	$0, %edx
	jne	LBB2_7
## BB#5:                                ##   in Loop: Header=BB2_1 Depth=1
	cmpl	$0, -24(%rbp)
	je	LBB2_7
## BB#6:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	$0, -24(%rbp)
LBB2_7:                                 ##   in Loop: Header=BB2_1 Depth=1
	movslq	-20(%rbp), %rax
	movq	-8(%rbp), %rcx
	movsbl	(%rcx,%rax), %edx
	cmpl	$9, %edx
	jne	LBB2_20
## BB#8:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	$8, %eax
	subl	-24(%rbp), %eax
	movl	%eax, -36(%rbp)
	movl	$0, -24(%rbp)
	movl	-12(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -28(%rbp)
	movl	-12(%rbp), %eax
	addl	-36(%rbp), %eax
	movl	-16(%rbp), %ecx
	subl	$1, %ecx
	cmpl	%ecx, %eax
	jge	LBB2_10
## BB#9:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	-36(%rbp), %eax
	subl	$1, %eax
	addl	-12(%rbp), %eax
	movl	%eax, -12(%rbp)
LBB2_10:                                ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_11
LBB2_11:                                ##   Parent Loop BB2_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-28(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	LBB2_16
## BB#12:                               ##   in Loop: Header=BB2_11 Depth=2
	movslq	-28(%rbp), %rax
	movq	-8(%rbp), %rcx
	movsbl	(%rcx,%rax), %edx
	cmpl	$10, %edx
	jne	LBB2_14
## BB#13:                               ##   in Loop: Header=BB2_11 Depth=2
	jmp	LBB2_15
LBB2_14:                                ##   in Loop: Header=BB2_11 Depth=2
	movslq	-28(%rbp), %rax
	movq	-8(%rbp), %rcx
	movb	(%rcx,%rax), %dl
	movl	-28(%rbp), %esi
	addl	-36(%rbp), %esi
	subl	$1, %esi
	movslq	%esi, %rax
	movq	-8(%rbp), %rcx
	movb	%dl, (%rcx,%rax)
LBB2_15:                                ##   in Loop: Header=BB2_11 Depth=2
	movl	-28(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB2_11
LBB2_16:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	-20(%rbp), %eax
	movl	%eax, -32(%rbp)
LBB2_17:                                ##   Parent Loop BB2_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-32(%rbp), %eax
	movl	-20(%rbp), %ecx
	addl	-36(%rbp), %ecx
	cmpl	%ecx, %eax
	jge	LBB2_19
## BB#18:                               ##   in Loop: Header=BB2_17 Depth=2
	movslq	-32(%rbp), %rax
	movq	-8(%rbp), %rcx
	movb	$32, (%rcx,%rax)
	movl	-32(%rbp), %edx
	addl	$1, %edx
	movl	%edx, -32(%rbp)
	jmp	LBB2_17
LBB2_19:                                ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_20
LBB2_20:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
## BB#21:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB2_1
LBB2_22:
	movl	-16(%rbp), %eax
	subl	$1, %eax
	movslq	%eax, %rcx
	movq	-8(%rbp), %rdx
	movb	$0, (%rdx,%rcx)
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%s\n"


.subsections_via_symbols

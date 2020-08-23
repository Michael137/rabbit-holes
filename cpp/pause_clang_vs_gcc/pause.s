	.text
	.file	"pause.cc"
	.globl	_Z4testv                # -- Begin function _Z4testv
	.p2align	4, 0x90
	.type	_Z4testv,@function
_Z4testv:                               # @_Z4testv
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	jmp	.LBB0_1
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	pause
	pause
	pause
	pause
	pause
	#APP
	pause
	#NO_APP
	#APP
	pause
	#NO_APP
	#APP
	pause
	#NO_APP
	#APP
	pause
	#NO_APP
	#APP
	pause
	#NO_APP
	jmp	.LBB0_1
.Lfunc_end0:
	.size	_Z4testv, .Lfunc_end0-_Z4testv
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax
	movl	$0, -4(%rbp)
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 10.0.1-++20200708123507+ef32c611aa2-1~exp1~20200707224105.191 "
	.section	".note.GNU-stack","",@progbits
	.addrsig

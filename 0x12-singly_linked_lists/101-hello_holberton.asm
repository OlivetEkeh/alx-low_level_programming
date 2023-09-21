section .data
hello_msg db 'Hello, Holberton',0
format db '%s',0

section .text
global _start

_start:
; Clear registers
xor rdi, rdi
xor rsi, rsi

; Load the address of the format string
mov rsi, format

; Load the address of the hello_msg string
mov rdi, hello_msg

; Call printf
call printf

; Exit the program
mov rax, 60         ; syscall: exit
xor rdi, rdi        ; status: 0
syscall

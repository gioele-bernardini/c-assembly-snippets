section .data
    hello db 'Hello, World!',10  ; Aggiungi 10 per la nuova riga (newline)
    hello_len equ $ - hello       ; Calcola la lunghezza della stringa

section .text
global _start

_start:
    ; La funzione write richiede i seguenti parametri:
    ; File descriptor (1 per stdout)
    ; Puntatore alla stringa da stampare
    ; Lunghezza della stringa
    mov eax, 4            ; Codice di sistema per la sys_write
    mov ebx, 1            ; File descriptor (1 = stdout)
    mov ecx, hello        ; Puntatore alla stringa
    mov edx, hello_len    ; Lunghezza della stringa
    int 0x80              ; Chiamata di sistema

    ; Termina il programma
    mov eax, 1            ; Codice di sistema per la sys_exit
    xor ebx, ebx          ; Codice di uscita (0)
    int 0x80              ; Chiamata di sistema


; nasm -f elf hello.asm
; ld -m elf_i386 -s -o hello hello.o
; ./hello

section .data
    hello db "HTTP/1.1 200 OK", 13, 10
          db "Content-Type: text/plain", 13, 10
          db "Content-Length: 12", 13, 10
          db 13, 10
          db "Hello World", 13, 10
    hello_len equ $ - hello

section .bss
    sockaddr resb 16
    buffer resb 30000

section .text
    global _start

_start:
    ; Create socket: socket(AF_INET, SOCK_STREAM, 0)
    xor rax, rax
    mov al, 41                ; syscall: socket
    xor rdi, rdi
    mov dil, 2                ; AF_INET
    mov esi, 1                ; SOCK_STREAM
    xor rdx, rdx              ; protocol 0
    syscall
    mov rdi, rax              ; save socket fd

    ; Bind socket: bind(sock_fd, sockaddr, addrlen)
    mov rsi, sockaddr
    xor rdx, rdx
    mov dword [rsi + 0], 0x0200            ; sin_family = AF_INET
    mov word [rsi + 2], 8080               ; sin_port = htons(8080)
    xor rbx, rbx
    mov dword [rsi + 4], rbx               ; sin_addr.s_addr = INADDR_ANY
    mov dword [rsi + 8], rbx               ; padding (sin_zero)

    mov al, 49                ; syscall: bind
    mov edx, 16               ; sizeof(sockaddr_in)
    syscall

    ; Listen: listen(sock_fd, backlog)
    xor rax, rax
    mov al, 50                ; syscall: listen
    mov esi, 3                ; backlog
    syscall

main_loop:
    ; Accept: accept(sock_fd, sockaddr, addrlen)
    mov rsi, sockaddr
    mov rdx, 16
    xor rax, rax
    mov al, 43                ; syscall: accept
    syscall
    mov rdi, rax              ; save new socket fd

    ; Read request: read(new_sock_fd, buffer, buffer_len)
    mov rsi, buffer
    mov edx, 30000
    xor rax, rax
    mov al, 0                 ; syscall: read
    syscall

    ; Write response: write(new_sock_fd, hello, hello_len)
    mov rsi, hello
    mov rdx, hello_len
    xor rax, rax
    mov al, 1                 ; syscall: write
    syscall

    ; Close socket: close(new_sock_fd)
    xor rax, rax
    mov al, 3                 ; syscall: close
    syscall

    jmp main_loop

    ; Exit (should never reach here in this example)
    xor rax, rax
    mov al, 60                ; syscall: exit
    xor rdi, rdi
    syscall

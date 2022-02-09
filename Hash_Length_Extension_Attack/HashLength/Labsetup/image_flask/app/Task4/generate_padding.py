payload = bytearray("123456:myname=RushabhPrajapati&uid=1001&lstcmd=1","utf8")
len(payload)
length_field = (len(payload) * 8).to_bytes(8,'big')
padding = b'\x80' + b'\x00' * (64 - len(payload) - 1 - 8) + length_field
print(''.join('%{:02x}'.format(x) for x in padding))

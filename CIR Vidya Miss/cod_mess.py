inp = input("Enter the code message:")
out = ""
i = len(inp) - 1

while i >= 0:
    print("i:", i)
    if inp[i] == '#':
        print("i:", i)
        i -= 1
        print("i:", i)
        out += chr(ord("a") + int(inp[i:i-2:-1]))
        i -= 2
        print("i:", i)
    else:
        out += chr(ord("a") + int(inp[i]) - 1)
        i -= 1

print("The decoded message is:", out[::-1])
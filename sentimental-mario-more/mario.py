x = 0
while not (1 <= x <= 8):
    try:
        x = int(input("Height: "))
    except ValueError:
        continue
else:
    for i in range(x):
        n = i + 1
        for j in range(x-n):
            print(" ", end="")
        for j in range(n):
            print("#", end="")
        print("  ", end="")
        for j in range(n):
            print("#", end="")
        print()

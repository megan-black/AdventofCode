with open("input.txt", 'r') as f:
    count = 0
    ls = f.readlines()
    i = 1
    prev = int(ls[0]) + int(ls[1]) + int(ls[2])
    while i < len(ls) - 2:
        cur = int(ls[i]) + int(ls[i+1]) + int(ls[i+2])
        if cur > prev: count += 1
        prev = cur
        i += 1
    print(count)

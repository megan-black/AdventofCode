with open("input.txt", 'r') as file:
    count = 0
    lines = file.readlines()
    for i in range(len(lines)-1):
        if(int(lines[i+1]) > int(lines[i])): 
            count += 1
    print(count)
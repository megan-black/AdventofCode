#part 1

f = open("input.txt", 'r')

days = f.readline().split(',')
days = [int(day, base=10) for day in days]

for x in range(80):
    day_len = len(days)
    for i in range(day_len):
        if days[i] == 0:
            days[i] = 6
            days.append(8)
        else:
            days[i] -= 1
print(len(days))

f.close()

#part 2
f = open("input.txt", 'r')
days = f.readline().split(',')
days = [int(day, base=10) for day in days]

for x in range(256):
    day_len = len(days)
    for i in range(day_len):
        if days[i] == 0:
            days[i] = 6
            days.append(8)
        else:
            days[i] -= 1
    print(x)
print(len(days))
f.close()
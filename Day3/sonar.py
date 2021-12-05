f = open("./input.txt")
ls = f.readlines()

gamma = ''
epsilon = ''

for i in range(len(ls[0])-1):
    count_1 = len([x[i] for x in ls if x[i] == "1"])
    count_0 = len([x[i] for x in ls if x[i] == "0"])
    if count_1 >= count_0:
        gamma += '1'
        epsilon += '0'
    else:
        gamma += '0'
        epsilon += '1'
print("Part 1: ")
print(int(gamma,2) * int(epsilon,2))

# part 2:

def get_index(arr, num1, num2):
    i = 0
    while(len(arr) > 1):
        count_1 = len([x[i] for x in arr if x[i] == "1"])
        count_0 = len([x[i] for x in arr if x[i] == "0"])
        if(count_1 >= count_0):
            arr = [x for x in arr if x[i] == num1]
        else:
            arr = [x for x in arr if x[i] == num2]
        i += 1
    return arr[0]

o2 = ls ; co2 = ls
print("Part 2:")
print(int(get_index(o2, '1', '0'),2) * int(get_index(co2, '0', '1'),2))

        
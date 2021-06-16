N = int(input())

#1087388483 = 1021·1031·1033 = 1052651 * 1033 = 1021 * 1065023 = 1054693 * 1031
ind_multips = [1021, 1031, 1033]
double_multips = [1021*1031, 1021*1033, 1031*1033]
num_itself = 1021*1031*1033

input_multips = []
i = 0

while i < N:
    n = int(input())
    if n in ind_multips or n in double_multips or n == num_itself:
        input_multips.append(n)
    i += 1
    
if (set(ind_multips).issubset(input_multips)
    or (ind_multips[0] in input_multips and double_multips[2] in input_multips)
    or (ind_multips[1] in input_multips and double_multips[1] in input_multips)
    or (ind_multips[2] in input_multips and double_multips[0] in input_multips)
    or (num_itself in input_multips)):
     print ("YES")
else:    
     print ("NO")
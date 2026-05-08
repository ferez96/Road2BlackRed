def f(arr):
    cur_max = arr[0]
    count = 0
    for i in range(1, len(arr)):
        if arr[i] < cur_max+1:
            count += 1
        cur_max = max(cur_max+1, arr[i])
    return count


print(f([1, 1]))
print(f([2, 1, 3]))
print(f([2, 1, 4]))
print(f([1, 2]))

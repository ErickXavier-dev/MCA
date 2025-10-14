li = [1,2,3,4,5,6,7,8,9]

n = int(input("Enter the number of positions to shift: "))
n = n % len(li)  # To handle cases where n is greater than the length of the list
shifted_li = li[n:] + li[:n]
print("Shifted List:", shifted_li)
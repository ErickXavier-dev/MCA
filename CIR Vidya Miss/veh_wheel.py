wheels = int(input("Enter number of wheels:"))
vehicles = int(input("Enter number of vehicles:"))

t,f = 0,0

for i in range(vehicles+1):
  if (i*4 + (vehicles-i)*2) == wheels:
    t = i
    f = vehicles - i
    break

print("Number of four wheeler vehicles:",t)
print("Number of two wheeler vehicles:",f)
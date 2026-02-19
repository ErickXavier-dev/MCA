n = int(input())
m = int(input())

v = []
d = []

# Read v[i] values
for _ in range(n):
    v.append(int(input()))

# Read d[i] values
for _ in range(n):
    d.append(int(input()))

total_taste = []

# Generate all possible taste values
for i in range(n):
    current = v[i]
    for t in range(m):
        if current <= 0:
            break
        total_taste.append(current)
        current -= d[i]

# Sort in descending order
total_taste.sort(reverse=True)

# Take top m meals
print(sum(total_taste[:m]))

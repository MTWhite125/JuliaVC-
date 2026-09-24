import pandas as pd

df = pd.read_csv("random_numbers_1000.csv")

my_list = df["Random Number"].tolist()
print(my_list)

# Sort ascending
sorted_list = sorted(my_list)
print(sorted_list)

# Reverse the sorted list
reversed_list = sorted_list[::-1]
print(reversed_list)
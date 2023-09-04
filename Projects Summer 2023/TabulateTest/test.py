from tabulate import tabulate

data = [
    ["Alice", 28, "Engineer"],
    ["Bob", 24, "Designer"],
    ["Charlie", 22, "Writer"],
]

table_format = "fancy_grid"
table = tabulate(data, headers=["Name", "Age", "Occupation"], tablefmt=table_format)
print(table)
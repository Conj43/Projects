user = input("Welcome to Conj's To-Do List! What is your name? ")

list = f"{user}_list.txt"

try:
    with open(list, "r") as file:
        tasks = file.read().splitlines()
except FileNotFoundError:
    tasks = []

while True:
    print("\nChoose a number to pick an action!")
    print("1. Add a task")
    print("2. View tasks")
    print("3. Delete tasks")
    print("4. Exit")

    action = input("Choose an action: ")

    if action == "1":
        task = input("Enter a task: ")
        tasks.append(task)
    elif action == "2":
        if tasks:
            print("\nYour tasks:")
            for i, task in enumerate(tasks, start=1):
                print(f"{i}. {task}")
        else:
            print("No tasks yet!")
    elif action == "3":
        if tasks:
            print("\nYour tasks:")
            for i, task in enumerate(tasks, start =1):
                print(f"{i}. {task}")
            task_index = int(input("Enter task number to remove: "))
            if 1 <= task_index <= len(tasks):
                removed_task = tasks.pop(task_index - 1)
                print(f"Removed task: {removed_task}")
            else:
                print("Invald task number!")
        else:
            print("No tasks to remove.")
    elif action == "4":
        with open(list , "w") as file:
            for task in tasks: 
                file.write(task + "\n")
        print("Bye!")
        break
    else:
        print("Invalid Choice. Please Try Again.")



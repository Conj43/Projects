def show_menu():
    print("To-Do List Menu:")
    print("1. Add task")
    print("2. View tasks")
    print("3. Remove task")
    print("4. Exit")

tasks = []

while True:
    show_menu()
    choice = input("Enter your choice (1-4): ")

    if choice == '1':
        task = input("Enter the task: ")
        tasks.append(task)
        print("Task added successfully!")
    elif choice == '2':
        if len(tasks) == 0:
            print("No tasks in the list.")
        else:
            print("Tasks:")
            for i, task in enumerate(tasks, start=1):
                print(f"{i}. {task}")
    elif choice == '3':
        if len(tasks) == 0:
            print("No tasks to remove.")
        else:
            task_index = input("Enter the index of the task to remove: ")
            try:
                index = int(task_index) - 1
                if 0 <= index < len(tasks):
                    removed_task = tasks.pop(index)
                    print(f"Task '{removed_task}' removed successfully!")
                else:
                    print("Invalid task index.")
            except ValueError:
                print("Invalid task index.")
    elif choice == '4':
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 4.")


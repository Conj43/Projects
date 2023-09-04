import tkinter as tk


def main():
    global entry, listbox  # Declare entry and listbox as global variables

    root = tk.Tk()
    root.title("To-Do List")

    # Create listbox
    listbox = tk.Listbox(root)
    listbox.pack(pady=20)

    # Create entry
    entry = tk.Entry(root, font=("Helvetica", 16))
    entry.pack(pady=20)

    # Create buttons
    button_frame = tk.Frame(root)
    button_frame.pack(pady=20)

    add_button = tk.Button(button_frame, text="Add Task", command=add_task)
    add_button.grid(row=0, column=0)

    delete_button = tk.Button(button_frame, text="Delete Task", command=delete_task)
    delete_button.grid(row=0, column=1)

    entry = tk.Entry(root, font=("Helvetica", 16), foreground="pink")
    entry.insert(0, "Enter task...")
    entry.bind("<FocusIn>", on_entry_click)
    entry.bind("<FocusOut>", on_focus_out)
    entry.pack(pady=10)

    root.mainloop()


def add_task():
    task = entry.get()
    if task:
        listbox.insert(tk.END, task)
        entry.delete(0, tk.END)

def delete_task():
    try:
        index = listbox.curselection()
        listbox.delete(index)
    except:
        pass

def on_entry_click(event):
    if entry.get() == "Enter task...":
        entry.delete(0, tk.END)
        entry.configure(foreground="pink")

def on_focus_out(event):
    if entry.get() == "":
        entry.insert(0, "Enter task...")
        entry.configure(foreground="pink")

if __name__ == "__main__":
    main()



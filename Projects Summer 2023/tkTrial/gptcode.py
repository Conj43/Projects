import tkinter as tk

# Create the main window
root = tk.Tk()
root.title("Conj's To Do List")

# Function to capture the input when the button is pressed
def capture_input():
    user_input = entry.get()  # Get the text from the Entry widget
    if user_input:
        task_list.insert(tk.END, user_input)  # Add the task to the listbox
        entry.delete(0, tk.END)  # Clear the Entry widget

# Create a frame to hold the buttons on the right side
button_frame = tk.Frame(root)
button_frame.grid(row=0, column=1, padx=10, pady=10, rowspan=2)  # Use grid

# Create a listbox to display tasks on the left side
task_list = tk.Listbox(root, width=45, height=35)
task_list.grid(row=0, column=0, padx=25, pady=10, rowspan=2)  # Use grid

# Create an Entry widget for user input below the buttons
entry = tk.Entry(root, width=30)
entry.grid(row=2, column=1, padx=10, pady=10)  # Use grid

# Create a button widget
button1 = tk.Button(button_frame, text="Add Task", width=15, height=3, command=capture_input)
button2 = tk.Button(button_frame, text="View Tasks", width=15, height=3)
button3 = tk.Button(button_frame, text="Delete Task", width=15, height=3)
button4 = tk.Button(button_frame, text="Quit", width=15, height=3, command=root.quit)

# Use grid for buttons in button_frame
button1.grid(row=0, column=0, padx=10, pady=10)
button2.grid(row=1, column=0, padx=10, pady=10)
button3.grid(row=0, column=1, padx=10, pady=10)
button4.grid(row=1, column=1, padx=10, pady=10)

# Create a label widget
# Create a label to display the captured input
label = tk.Label(root, text="")
label.grid(row=3, column=0, columnspan=2, pady=10)  # Use grid

# Making window bigger
root.geometry("900x700")

# Start the main event loop
root.mainloop()


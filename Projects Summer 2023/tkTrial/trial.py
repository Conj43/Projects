import tkinter as tk
from tkinter import font
# Create the main window
root = tk.Tk()
root.title("Conj's To Do List")
count = 1
# Function to capture the input when the button is pressed
def capture_input():
    global count
    user_input = entry.get()  # Get the text from the Entry widget
    if user_input:
        task_text = f"{count}. {user_input}"
        task_list.insert(tk.END, task_text)  # Add the task to the listbox
        entry.delete(0, tk.END)  # Clear the Entry widget
        count +=1

# Function to center-align and style the Listbox text
def center_text(event):
    width = event.width
    task_list.itemconfig(tk.END, font=("Helvetica", 14))  # Set the font
    task_list.itemconfig(tk.END, justify=tk.CENTER)  # Center align
    task_list.itemconfig(tk.END, width=width)  # Set the width

root.configure(bg = "purple")

# Create a frame to hold the buttons on the right side
button_frame = tk.Frame(root)
button_frame.grid(row=0, column=1, padx=10, pady=10, rowspan=2)  # Use grid

# Create a listbox to display tasks on the left side
task_list = tk.Listbox(root, width=45, height=35, font=("Helvetica", 14), bg = "light blue")  # Set a custom font
task_list.grid(row=0, column=0, padx=25, pady=10, rowspan=2)  # Use grid
# Bind the center_text function to configure events
task_list.bind("<Configure>", center_text)

# Create an Entry widget for user input below the buttons
entry = tk.Entry(root, width=30)
entry.grid(row=1, column=1, padx=10, pady=10)  # Use grid

# Create a button widget
button1 = tk.Button(button_frame, text="Add Task", width=15, height=3, command=capture_input)
button2 = tk.Button(button_frame, text="Delete Task", width=15, height=3)
button3 = tk.Button(button_frame, text="Quit", width=15, height=3, command=root.quit)

# Use grid for buttons in button_frame
button1.grid(row=0, column=0, padx=10, pady=10)
button2.grid(row=0, column=1, padx=10, pady=10)
button3.grid(row=1, column=1, padx=10, pady=10)

# Create a label widget
# Create a label to display the captured input
label = tk.Label(root, text="")
label.grid(row=3, column=0, columnspan=2, pady=10)  # Use grid


# Making window bigger
root.geometry("900x700")

# Start the main event loop
root.mainloop()

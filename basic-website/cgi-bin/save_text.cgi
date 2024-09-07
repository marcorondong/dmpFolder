#!/usr/bin/env python3
import cgi
import os

print("Content-Type: text/html\n")

# Directory to save the text file
upload_dir = "public/uploads"
os.makedirs(upload_dir, exist_ok=True)  # Ensure the upload directory exists

# Get the form data
form = cgi.FieldStorage()
text_input = form.getvalue('text')

# Set a filename for saving the text input
filename = "submitted_text.txt"
file_path = os.path.join(upload_dir, filename)

# Save the text input to a file
try:
	with open(file_path, 'w') as file:
		file.write(text_input)
	print(f"<p>Text saved successfully in {filename}.</p>")
except Exception as e:
	print(f"<p>Error saving text: {str(e)}</p>")

#!/usr/bin/env python3

import cgi
import cgitb
import html

cgitb.enable()  # Enable debugging

# Set the content-type header for HTTP response
print("Content-Type: text/html\n")

# Parse the form data for both GET and POST
form = cgi.FieldStorage()
name = form.getvalue("name")
email = form.getvalue("email")

# Safely escape the input to avoid HTML injection
if name and email:
	safe_name = html.escape(name)
	safe_email = html.escape(email)

	# File path to the database HTML file
	# database_file = "path/to/your/database.html"  # Adjust the path to where your database.html is located
	database_file = "public/pages/database.html"  # Adjust the path to where your database.html is located

	try:
		# Append the new name to the HTML file inside the <ul> element
		with open(database_file, "r+") as file:
			lines = file.readlines()
			
			# Find the line where the <ul id="namesList"> tag is located
			for i, line in enumerate(lines):
				if '<ul id="namesList">' in line:
					# Insert the new name just after the <ul> opening tag
					lines.insert(i + 1, f"        <li>Name: {safe_name}, Email: {safe_email}</li>\n")
					break
			
			# Move the file pointer to the beginning and write updated content
			file.seek(0)
			file.writelines(lines)
		
		# Output success message
		print("<p>Name and email registered successfully!</p>")

	except Exception as e:
		# Output error message
		print(f"<p>Error registering name and email: {str(e)}</p>")
else:
	print("<p>Invalid data submitted.</p>")

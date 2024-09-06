#!/usr/bin/env python3

import cgi
import cgitb
import html

cgitb.enable()

print("Content-Type: text/html\n")

# Get the form data
form = cgi.FieldStorage()
search_name = form.getvalue("name")

if search_name:
	safe_search_name = html.escape(search_name)
	database_file = "public/pages/database.html"
	result_found = False

	try:
		with open(database_file, "r") as file:
			lines = file.readlines()
			for line in lines:
				if safe_search_name in line:
					print(f"<p>Found: {line.strip()}</p>")
					result_found = True
					break
		if not result_found:
			print("<p>No matching name found.</p>")
	except Exception as e:
		print(f"<p>Error searching for name: {str(e)}</p>")
else:
	print("<p>Please enter a name to search.</p>")

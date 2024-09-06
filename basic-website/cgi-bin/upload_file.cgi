#!/usr/bin/env python3
import cgi
import os
import json

print("Content-Type: application/json\n")

form = cgi.FieldStorage()
file_item = form['file']

upload_dir = "public/uploads"
message = ""
if file_item.filename:
	file_path = os.path.join(upload_dir, os.path.basename(file_item.filename))
	with open(file_path, 'wb') as file:
		file.write(file_item.file.read())
	# message = "File uploaded successfully."

files = os.listdir(upload_dir)
print(json.dumps(files))  # Return the list of filenames as JSON

#!/usr/bin/env python3
import os
import urllib.parse
import json

print("Content-Type: application/json\n")

# Parse the query string for the file parameter
query_string = os.environ.get('QUERY_STRING', '')
params = urllib.parse.parse_qs(query_string)
file_name = params.get('file', [None])[0]

upload_dir = "public/uploads"
if file_name:
	file_path = os.path.join(upload_dir, file_name)
	try:
		os.remove(file_path)
		# print("<p>File deleted successfully.</p>")
	except Exception as e:
		print(f"<p>Error deleting file: {str(e)}</p>")
else:
	print("<p>No file specified.</p>")

files = os.listdir(upload_dir)
print(json.dumps(files))  # Return the list of filenames as JSON

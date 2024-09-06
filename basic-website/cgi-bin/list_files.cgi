#!/usr/bin/env python3
import os
import json

print("Content-Type: application/json\n")

# print("Current Working Directory:", os.getcwd())  # Print the current working directory
upload_dir = "public/uploads"
files = os.listdir(upload_dir)
print(json.dumps(files))  # Return the list of filenames as JSON

# # Construct the absolute path to the uploads directory
# script_dir = os.path.dirname(__file__)  # Directory where the script is located
# upload_dir = os.path.join(script_dir, "../public/uploads")  # Adjust relative to the script's location

# # Use the absolute path to list files
# upload_dir = os.path.abspath(upload_dir)  # Convert to an absolute path
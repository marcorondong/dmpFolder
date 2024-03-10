#!/bin/bash

# Function to display usage instructions
usage() {
    echo "Usage: Just run $0 and follow the prompts."
    echo "The script will ask for the file path and the line numbers."
    exit 1
}

# Check if arguments were provided and show usage if they were
if [ "$#" -gt 0 ]; then
    echo "Error: No arguments expected."
    usage
fi

# Prompt for FILE input
echo "Enter the file path:"
read FILE

# Check if the file exists
if [ ! -f "$FILE" ]; then
    echo "Error: File '$FILE' not found."
    exit 1
fi

# Prompt for LINES input
echo "Enter the comma-separated list of line numbers:"
read LINES

# Convert comma-separated line numbers into space-separated
LINE_NUMBERS=$(echo "$LINES" | tr ',' ' ')

for line in $LINE_NUMBERS; do
    echo "Test starting at line $line:"
    sed -n "${line},\$p" "$FILE" | awk 'NF {p=1} !NF {if(p) exit} {if(p) print}'
    echo "--------------------------------"
done

################################################################################
#                               USAGE INSTRUCTIONS                             #
################################################################################
#
#----------------------FOR PRINTING THE TESTFILE CONTENTS----------------------#
#
# This is a script to be used alongside the minishell tester of zstenger93
# (https://github.com/zstenger93/42_minishell_tester).
# git clone https://github.com/zstenger93/42_minishell_tester.git
#
# 1. Copy zstenger's minishell tester in the root of your minishell folder.
# (Follow his instructions; you have to give execution permission to his tester)
# 2. Put this script in the root of your minishell folder.
# 3. Give it execution permission (chmod +x print_testfile_lines.sh).
# 4. Execute it (./print_testfile_lines.sh)
#
# It needs the path+filename of the test, and a comma-separated list of the
# lines (line head -line_number).
# It's like typing 'cat path_filename | head -line_number' but it's "automatic".
# It prompts for the path+file and then it prompts for the line numbers
# to execute the 'head' command.
# It prints whole command file for that specific test; even if it's multiline.
# E.g: Use it like this:
# ./print_file_lines.sh
# Enter the file path:
# /nfs/homes/marondon/42_minishell_tester/cmds/mand/1_scmds.sh
# Enter the comma-separated list of line numbers:
# 19,24,48,52
#
################################################################################
#          MADE BY MARONDON WITH THE HELP OF STACK OVERFLOW AND CHATGPT        #
################################################################################

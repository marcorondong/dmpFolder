#!/bin/bash

# Prompt for test mode
echo "Enter the test mode (m, vm, d, ne, b):"
read test_mode

# Function to normalize yes/no answers
normalize_input() {
    case "$1" in
        y|Y|yes|YES)
            echo "yes"
            ;;
        n|N|no|NO)
            echo "no"
            ;;
        *)
            echo "invalid"
            ;;
    esac
}

# Ask if all parts should be included
echo "Include all tested parts? (STD_OUT, STD_ERR, EXIT_CODE, LEAKS) [y/n]:"
read include_all
include_all=$(normalize_input "$include_all")

# Initialize the awk command
awk_cmd="awk '"

# Always print headers, subheaders, and the summary section, and detect the start of the summary section
awk_cmd+="/🚀|#|🏁/ {print; if(/🏁/) inSummary=1; next;} "

# If not including all parts, add conditions for selected test parts
if [ "$include_all" != "yes" ]; then
    echo "Include STD_OUT? [y/n]:"
    read include_stdout
    include_stdout=$(normalize_input "$include_stdout")
    if [ "$include_stdout" == "yes" ]; then
        awk_cmd+="/STD_OUT: ❌/ && !inSummary {print; next;} "
    fi

    echo "Include STD_ERR? [y/n]:"
    read include_stderr
    include_stderr=$(normalize_input "$include_stderr")
    if [ "$include_stderr" == "yes" ]; then
        awk_cmd+="/STD_ERR: ❌/ && !inSummary {print; next;} "
    fi

    echo "Include EXIT_CODE? [y/n]:"
    read include_exitcode
    include_exitcode=$(normalize_input "$include_exitcode")
    if [ "$include_exitcode" == "yes" ]; then
        awk_cmd+="/EXIT_CODE: ❌/ && !inSummary {print; next;} "
    fi

    echo "Include LEAKS? [y/n]:"
    read include_leaks
    include_leaks=$(normalize_input "$include_leaks")
    if [ "$include_leaks" == "yes" ]; then
        awk_cmd+="/LEAKS: ❌/ && !inSummary {print; next;} "
    fi
else
    # If including all parts, print any line with a failure
    awk_cmd+="/❌/ && !inSummary {print;} "
fi

# Print all lines once in the summary section
awk_cmd+="inSummary {print}'"

# Use the full path to the tester.sh script, apply sed to remove ANSI escape codes, and then apply the awk command
eval "bash /nfs/homes/marondon/42_minishell_tester/tester.sh $test_mode | sed -e 's/\x1b\[[0-9;]*m//g' | $awk_cmd"

################################################################################
#                               USAGE INSTRUCTIONS                             #
################################################################################
#
#FOR PRINTING THE FILTERED TEST RESULT ACCORDING TO TEST PART (STD_OUT,ERR,ETC)#
#
# This is a script to be used alongside the minishell tester of zstenger93.
# (https://github.com/zstenger93/42_minishell_tester).
# git clone https://github.com/zstenger93/42_minishell_tester.git
#
# 1. Copy zstenger's minishell tester in the root of your minishell folder.
# (Follow his instructions; you have to give execution permission to his tester)
# 2. Put this script in the root of your minishell folder.
# 3. Give it execution permission (chmod +x print_filtered_result.sh).
# 4. Inside this script look for
# "/nfs/homes/marondon/42_minishell_tester" and change
# marondon with your username. (the script needs the full path to
# 42_minishell_tester/tester.sh)
# 5. Execute it (./print_filtered_result.sh) and it'll automatically run
# zstenger's minishell tester.
#
# It ask for:
# The test mode to use (m, vm, d, ne, b, etc) (read zstenger93 tester usage).
# The failed "test part" to print (e.g: STD_OUT, STD_ERR, etc)
# Then it runs the whole test, and only prints the fails on the selected parts;
# but WITHOUT including the testfile contents.
# So you'll only see in what you fail, but not the commands that were used
# to test your minishell.
#
################################################################################
#          MADE BY MARONDON WITH THE HELP OF STACK OVERFLOW AND CHATGPT        #
################################################################################

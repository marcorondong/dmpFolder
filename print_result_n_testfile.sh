#!/bin/bash

# Flag to indicate if the summary section has started
summary_started=false

# Read input from the pipeline or a file
while IFS= read -r line; do
    # Check if the summary section has started
    if [[ $line =~ 🏁 ]]; then
        summary_started=true
    fi

    # If the summary has started, print lines as is
    if [ "$summary_started" = true ]; then
        echo "$line"
        continue
    fi

    # Process only failed test lines before the summary starts
    if echo "$line" | grep -q '❌'; then
        # Extract the file path and line number
        file_path=$(echo "$line" | grep -oE '/nfs/homes/marondon/42_minishell_tester/cmds/[^ ]+\.sh')
        line_number=$(echo "$line" | grep -oE '\.sh:[0-9]+' | cut -d: -f2)

        echo "$line"
        echo ""
        if [[ -n "$file_path" && -n "$line_number" ]]; then
            echo "Test starting at line $line_number:"
            sed -n "${line_number},\$p" "$file_path" | awk 'NF {p=1} !NF {if(p) exit} {if(p) print}'
            echo "--------------------------------"
            echo ""
        else
            echo "Could not extract test details."
            echo "--------------------------------"
            echo ""
        fi
    else
        # Print headers and other lines as is, before the summary starts
        echo "$line"
    fi
done

################################################################################
#                               USAGE INSTRUCTIONS                             #
################################################################################
#
#---FOR PRINTING THE TEST RESULTS AND THE TESTFILE CONTENTS OF ALL THE FAILS---#
#
# This is a script to be used alongside the minishell tester of zstenger93
# (https://github.com/zstenger93/42_minishell_tester).
# git clone https://github.com/zstenger93/42_minishell_tester.git
#
# 1. Copy zstenger's minishell tester in the root of your minishell folder.
# (Follow his instructions; you have to give execution permission to his tester)
# 2. Put this script in the root of your minishell folder.
# 3. Give it execution permission (chmod +x print_result_n_testfile.sh).
# 4. Inside this script look for
# "/nfs/homes/marondon/42_minishell_tester" and change
# marondon with your username. (the script needs the full path to
# 42_minishell_tester/tester.sh)
#
# It needs the test result output. Either you redirect the input from a saved
# test result file, or you pipe it.
# Note that for filtering the test, the folloing command should be used:
# awk '/🚀|#|❌/; /🏁/ {printIt = 1} printIt'
# If you don't filter the test, or either you pipe it without filtering;
# then it'll print the whole test, and will print only the test fie content
# of the failing test.
# E.g: Use it like this:
# ./print_result_n_testfile.sh < test_result_file.txt
# Or
# mstest m | awk '/🚀|#|❌/; /🏁/ {printIt = 1} printIt' | ./print_result_n_testfile.sh
# Or
# mstest m | ./print_result_n_testfile.sh
# (this one shows whole test without filtering, but only prints file contents
# of failed test).
#
# mstest is an alias for the tester script ( $HOME/42_minishell_tester/tester.sh)
# that is created automatically when "installing" zstenger's minishell tester:
# bash -c "$(curl -fsSL https://raw.githubusercontent.com/zstenger93/42_minishell_tester/master/install.sh)"
#
################################################################################
#          MADE BY MARONDON WITH THE HELP OF STACK OVERFLOW AND CHATGPT        #
################################################################################

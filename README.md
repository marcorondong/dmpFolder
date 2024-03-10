<h1 align=center>Filter scripts for zstenger's 42_minishell_tester</h1>

# Setup
First you have to clone zstenger's 42_minishell_tester in the root of your minishell repository and follow his instructions. 

Then copy the scripts in the root of your minishell repository.

Give the scripts execution permisions: `chmod +x name_of_the_script`

Then follow their instructions. They are in the code of each script (open them in text editor).

# WHAT EACH SCRIPT DOES
*print_testfile_lines.sh* : FOR PRINTING THE TESTFILE CONTENTS


*print_result_n_testfile.sh* : FOR PRINTING THE TEST RESULTS AND THE TESTFILE CONTENTS OF ALL THE FAILS


*print_filtered_result.sh* : FOR PRINTING THE FILTERED TEST RESULT ACCORDING TO TEST PART (STD_OUT,ERR,ETC)


*print_filtered_result_n_testfile.sh* : FOR PRINTING THE FILTERED TEST RESULT ACCORDING TO TEST PART (STD_OUT,ERR,ETC) AND THE TESTFILE CONTENTS.


<h2 align=center>USEFUL COMMANDS</h2>

- Use this command to filter the test result to only show the failed tests:

`awk '/🚀|#|❌/; /🏁/ {printIt = 1} printIt'`

E.G:

mstest m | awk '/🚀|#|❌/; /🏁/ {printIt = 1} printIt'

(remember that mstest is an alias for executing the minishell tester)



***
- Use this command to look for the executed commands in the minishell tester script:

`cat /nfs/homes/marondon/42_minishell_tester/cmds/mand/1_variables.sh | head -55`

Ex if the failed line is this one:

  23:	STD_OUT: ❌  STD_ERR: ✅  EXIT_CODE: ✅  /nfs/homes/marondon/42_minishell_tester/cmds/mand/1_variables.sh:55 



***
- Use this method for telling minishell to execute a series of commands inside a txt file:

bash < tests_to_run.txt



***
- To see "special chars" (like end of line), add `| cat -e¸` to the command:

bash < tests_to_run.txt | cat -e



***
- To comment out some test inside the txt file (instead of delete them), use # and then execute this command:

`grep -v '^#' commands.txt | ./minishell`

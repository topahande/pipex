# pipex

Reimplementation of the pipe (|) operator in C.

For the single pipe operator, run:

``
make
``

``./pipex file1 cmd1 cmd2 file2`` (implements the behaviour of ``< file1 cmd1 | cmd2 > file2``). 

Example:

``./pipex infile "ls -l" "wc -l" outfile`` (should behave like ``< infile ls -l | wc -l > outfile``). \
``./pipex infile "grep a1" "wc -w" outfile`` (should behave like ``< infile grep a1 | wc -w > outfile``). 

For multiple pipe operators, run:

``
make bonus
``

``./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`` (implements the behaviour of `` < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2 ``).





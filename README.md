# Placenta Analyzer - Largest square submatrix

## Generate executables

    make

## Clean

    make clean

## Program

	tp2 -i <entry file> -o <out file> -d (DEBUG) -p <Paradigm>
	Possible paradigms
	-p b(Brute Force) d(Dynamic programming) g(Greedy)
	-p n(Branch and bound) a(All)
	Examples: tp2 -i in.txt -o out.txt -d -p d
	tp2 -i in.txt -o out.txt
	tp2 -i in.txt

The most likely options to be used are i, o and p.
In case you only want to pass the input file as a parameter, it is possible, and that will make the output be in the standard output and the paradigm to be used will be asked during the execution.
To skip the question of which paradigm to use, just use the parameter p with some paradigm (b,d,g,n) or all (a).


The program input should have the following pattern:

1 1 1 1
1 1 1 0
1 1 1 1
1 0 1 0

Every line must have a '\n' at the end.

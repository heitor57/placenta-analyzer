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

As opções prováveis a serem mais utilizadas são o i,o e p
Caso queira passar somente o arquivo de entrada como parâmetro é possível, e isso fará com que a saída seja na saída padrão e o paradigma a ser utilizado irá se perguntado durante a execução.
Para pular a pergunta de qual paradigma a ser utilizado basta utilizar o parametro p com algum paradigma (b,d,g,n) ou todos (a).


A entrada do programa deve ter o seguinte padrão:

1 1 1 1
1 1 1 0
1 1 1 1
1 0 1 0

Toda linha deve ter um '\n' no final.

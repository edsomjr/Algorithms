#!/bin/bash

# Executa o teste de execução de um algoritmo
#
# Autor: Edson Alves
# Data: 06/03/2015
# Licença: LGPL. Sem copyright.

# Parâmetros
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 {source.cpp}"
    exit
fi

testfile=$1
runs=1

INCLUDE=$ALGO_HOME
CLASSPATH=$ALGO_HOME

if [ "$#" -gt 1 ]; then
    runs=$2
fi

filename=$(basename ${testfile})
extension="${filename##*.}"
filename="${filename%.*}"

package='package'

# Entradas e saídas
infile=${filename}.in
outfile=${filename}.sol

readarray INPUT < $infile
readarray OUTPUT < $outfile

# Compilação
if [ $extension == "java" ]; then
    javac -classpath ${CLASSPATH} $testfile
    package=`sed -n 's/package \(.*\);/\1/p' $testfile`
else
    g++ -o prog -W -Wall -pedantic -ansi -std=c++11 $testfile -I${INCLUDE} -O2 
fi

# Número de casos de teste
N=$((${#INPUT[@]} - 1))

# Teste caso a caso
for i in $(seq 0 $N); do
    sum=0;
    total=0;

    # Múltiplas execuções de um teste, para obter a média do tempo
    for j in $(seq $runs); do
        begin=`date +"%s%N"`;
        infile="$ALGO_HOME/files/"`echo ${INPUT[$i]} | tr '\n' ' '`

        if [ $extension == "java" ]; then
            cat $infile | java -cp $CLASSPATH $package.$filename > 'out.txt' 2> 'elapsed.txt';
        else
            cat $infile | ./prog > 'out.txt' 2> 'elapsed.txt';
        fi

        end=`date +"%s%N"`;
        elapsed=$(<'elapsed.txt');

        sum=$((sum + end - begin));
        total=$((total + elapsed));

        diff 'out.txt' $ALGO_HOME/files/${OUTPUT[$i]};
        if [ $? -ne 0 ]; then
            echo "Erro na entrada ${INPUT[$i]}"
            exit
        fi
        rm 'out.txt'
    done

    mean=$((sum/(1000000*$runs)))
    meanT=$((total/$runs))
    echo -n "${INPUT[$i]}"
    echo "  -- Elapsed time: $mean ms"
    echo "  -- Algorithm time: $meanT ms"
done

rm -f prog out.txt elapsed.txt *.class

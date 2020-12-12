#!/bin/bash
# Script que facilita analise de fator de carga da atividade N1

echo "Legenda: "
echo "Instancias de alunos x Elementos"

for i in {0..10}
do
    echo -n "$i x "
    ./trabalho_n1_pota | grep $i | wc -l
done

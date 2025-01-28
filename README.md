# Ordena-o-quick-e-bubble-sort
Relatório de uso dos modelos

Comparação entre Bubble Sort e Quick Sort
Bubble Sort:

Complexidade: O(n²) no pior e no caso médio; O(n) no melhor caso (lista já ordenada).
Funcionamento: Compara e troca elementos adjacentes até que a lista esteja ordenada.
Eficiência: Ineficiente para listas grandes.
Estabilidade: Algoritmo estável (preserva a ordem de elementos iguais).
Quick Sort:

Complexidade: O(n log n) no melhor e no caso médio; O(n²) no pior caso.
Funcionamento: Escolhe um pivô e organiza a lista com elementos menores à esquerda e maiores à direita. O processo é recursivo.
Eficiência: Muito mais eficiente que o Bubble Sort, especialmente em listas grandes.
Estabilidade: Algoritmo instável (pode alterar a ordem de elementos iguais).
Escolha de Pivôs no Quick Sort
A escolha do pivô impacta diretamente a performance do Quick Sort. Algumas estratégias incluem:

Pivô fixo (primeiro, último ou do meio): Simples, mas pode levar a um desempenho ruim em listas ordenadas.
Pivô aleatório: Minimiza a chance de cenários de pior caso, garantindo um bom desempenho médio.
Pivô mediano (ou mediana de três): Escolhe a mediana entre o primeiro, o último e o elemento do meio, oferecendo um desempenho mais equilibrado em listas diversas.

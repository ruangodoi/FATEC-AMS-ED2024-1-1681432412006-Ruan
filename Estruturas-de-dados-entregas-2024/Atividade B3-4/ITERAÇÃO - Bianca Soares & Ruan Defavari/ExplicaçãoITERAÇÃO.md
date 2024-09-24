# Código de Iteração

Este código é considerado de **iteração** porque utiliza **laços de repetição** (loops) para percorrer e processar dados em várias sessões e verificar a primalidade de números. A **iteração** se refere ao processo de repetir um bloco de código várias vezes com base em condições específicas, algo que é feito neste código através de dois loops principais:

## 1. Laço para percorrer as sessões de transmissão:
No código, o primeiro laço `for` percorre cada uma das sessões de transmissão:

```c
for (int i = 0; i < session_count; i++) {
    printf("Verificando sessão %d:\n", i + 1);
    // Processamento da sessão
}
```
Aqui, ele começa na primeira sessão e itera até a última, processando os números de cada sessão. Esse laço repete a verificação para cada sessão de dados.

## 2. Laço para percorrer os pacotes de dados dentro de uma sessão:
Dentro de cada sessão, existe outro laço for que percorre os pacotes de dados (números):

```c
for (int j = 0; j < session_size; j++) {
    int data_packet = sessions[i][j];
    // Verifica se o número é primo
}
```
Esse laço itera sobre cada número dentro da sessão e verifica se é primo. Ele faz isso repetidamente para cada número da transmissão.

## 3. Laço para verificar divisores (na função is_prime):
Além disso, dentro da função is_prime, outro laço for é usado para verificar se um número é primo:

```c
for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
        return 0; // Não é primo
    }
}
```
Esse laço é responsável por iterar sobre os possíveis divisores do número, determinando se ele pode ser dividido por algum número entre 2 e sua raiz quadrada. Ele repete a verificação até encontrar um divisor ou até esgotar as possibilidades.
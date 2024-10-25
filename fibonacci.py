def pertence_fibonacci(n):
    #Função para verificar se um número pertence à sequência de Fibonacci
    def quadrado_perfeito(x):
        s = int(x ** 0.5)
        return s * s == x
    
    #Fórmulas para verificar se um número é um número de Fibonacci
    eh_fibonacci = quadrado_perfeito(5 * n * n + 4) or quadrado_perfeito(5 * n * n - 4)
    return eh_fibonacci

def sequencia_fibonacci(n):
    #Funçãp para gerar a sequência de Fibonaccu até um número n
    sequencia = [0, 1]
    while sequencia[-1] < n:
        sequencia.append(sequencia[-1] + sequencia[-2])
    return sequencia
    
def main():
    num = int(input("Informe um número: "))
    fib_sequencia = sequencia_fibonacci(num)
    print(f"Sequência de Fibonacci até {num}: {fib_sequencia}")
    if pertence_fibonacci(num):
        print(f"O número {num} pertence à sequência de Fibonacci.")
    else:
        print(f"O número {num} NÃO pertence à sequência de Fibonacci.")   

if __name__ == "__main__":
    main()
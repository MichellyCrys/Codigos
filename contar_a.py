def contar_a(string):
    # Inicializa o contador
    contador = 0
    # Verifica cada caractere na string
    for caractere in string:
        if caractere.lower() == 'a':
            contador += 1
    # Retorna o resultado
    return contador

def main():
    # Solicita ao usuário que informe a string
    string = input("Informe um(a) texto/frase: ")
    # Chama a função para contar a letra 'a'
    quantidade = contar_a(string)
    # Verifica se 'a' existe na string e imprime o resultado
    if quantidade > 0:
        print(f"A letra 'a' aparece {quantidade} vez(es) na string.")
    else:
        print("A letra 'a' não aparece na string.")

if __name__ == "__main__":
    main()

def ordenamiento_burbuja_mejorado(arr):
    n = len(arr)
    
    # Asumimos que el array está desordenado al principio
    ordenado = False
    
    # Realizamos pasadas hasta que el array esté ordenado
    while not ordenado:
        ordenado = True
        
        # Recorremos el array desde el inicio hasta el final
        for i in range(n - 1):
            # Si el elemento actual es mayor que el siguiente
            if arr[i] > arr[i + 1]:
                # Intercambiamos los elementos
                aux = arr[i]
                arr[i] = arr[i +1]
                arr[i+1] = aux
                # Marcamos que se ha realizado un intercambio
                ordenado = False
    
    return arr
 
def main():
   arreglo = [9, 3, 8, 5, 1, 0, 2]
   print(arreglo)
   ordenado = ordenamiento_burbuja_mejorado(arreglo)
   print(ordenado)

if __name__ == "__main__":
   main()
import matplotlib.pyplot as plt

# Função para ler os dados de um arquivo .txt
def read_data(filename):
    data = {"Randomizado": {"sizes": [], "swaps": []},
            "Ordenado": {"sizes": [], "swaps": []},
            "Inverso": {"sizes": [], "swaps": []}}
    
    current_section = None
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line.startswith("Randomizado:") or line.startswith("Ordenado:") or line.startswith("Inverso:"):
                current_section = line.replace(":", "")
            elif "Tamanho:" in line:
                parts = line.split(" - ")
                size = int(parts[0].split(": ")[1])
                swap = int(parts[1].split(": ")[1])
                data[current_section]["sizes"].append(size)
                data[current_section]["swaps"].append(swap)
    return data

# Lendo os dados dos arquivos
quicksort_data = read_data("quicksort.txt")
merge_sort_data = read_data("mergesort.txt")
bubble_sort_data = read_data("bubblesort.txt")

# Função para criar os gráficos
def create_plots(data_list, titles):
    fig, axs = plt.subplots(1, len(data_list), figsize=(15, 5))  # Cria uma linha de gráficos
    if len(data_list) == 1:
        axs = [axs]  # Garante que axs seja uma lista, mesmo com um único gráfico
    
    for i, (data, title) in enumerate(zip(data_list, titles)):
        for case in data:
            sizes = data[case]["sizes"]
            swaps = data[case]["swaps"]
            axs[i].plot(sizes, swaps, label=case, marker="o")
        
        axs[i].set_xlabel("Tamanho do Array")
        axs[i].set_ylabel("Número de Trocas")
        axs[i].set_title(title)
        axs[i].legend()
        axs[i].grid(True)
    
    plt.tight_layout()  # Ajusta o layout para evitar sobreposição
    plt.show()

# Lista de dados e títulos
data_list = [quicksort_data, merge_sort_data, bubble_sort_data]
titles = ["Quicksort - Número de Trocas", "Merge Sort - Número de Trocas", "Bubble Sort - Número de Trocas"]

# Criando os gráficos
create_plots(data_list, titles)
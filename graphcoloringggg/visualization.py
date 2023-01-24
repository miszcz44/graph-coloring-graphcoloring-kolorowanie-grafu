import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import seaborn as sns


class ReadFile:

    def __init__(self, file_arr, file_colors):
        self.file_arr = file_arr
        self.file_colors = file_colors

    def read_arr(self):
        try:
            with open(self.file_arr, 'r') as file:
                lines = file.readlines()
                data = [list(map(int, line.strip().split())) for line in lines]
                return np.array(data)
        except FileNotFoundError:
            print(f"{self.file_arr} not found")

    def read_colors(self):
        try:
            with open(self.file_colors, 'r') as file:
                lines = file.readlines()
                data = list(map(int, lines[0].strip().split()))
                return np.array(data)
        except FileNotFoundError:
            print(f"{self.file_colors} not found")


class Graph(ReadFile):

    def __init__(self, file_arr, file_colors):
        super().__init__(file_arr, file_colors)
        self.adjacency_matrix = self.read_arr()
        self.colors = self.read_colors()
        self.G = nx.Graph(self.adjacency_matrix)
        self.colorCreated = sns.color_palette("Dark2", len(self.colors))
        self.colorMapping = dict(zip(self.colors, self.colorCreated))

    def visualize(self):
        vertex_colors = [self.colorMapping[x] for x in self.colors]
        nx.draw_networkx_nodes(self.G, pos=nx.spring_layout(self.G), node_color=vertex_colors)
        nx.draw_networkx_edges(self.G, pos=nx.spring_layout(self.G), edge_color='blue')
        plt.show()


if __name__ == '__main__':
    graph = Graph(r"C:\Users\mikołaj\source\repos\miszcz44\graphcoloringggg\graphcoloringggg\out.txt",
                  r"C:\Users\mikołaj\source\repos\miszcz44\graphcoloringggg\graphcoloringggg\color.txt")
    graph.visualize()

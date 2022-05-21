class GRAPH:

    def __init__(self, Vertices):
        self.v = Vertices
        self.g = []

    def Edge(self, p, q, r):
        self.g.append([p, q, r])

    def arr(self, D):
        print("Distance from Source")
        for n in range(self.v):
            print("{0}\t\t{1}".format(n, D[n]))

    def Bellman(self, Source):

        D = [float("INF")] * self.v
        D[Source] = 0
        for _ in range(self.v - 1):
            for p, q, r in self.g:
                if D[p] != float("INF") and D[p] + r < D[q]:
                    D[q] = D[p] + r

        for p, q, r in self.g:
            if D[p] != float("INF") and D[p] + r < D[q]:
                print("negative weight cycle is present......")
                return
        self.arr(D)


G = GRAPH(5)
G.Edge(0, 1, 6)
G.Edge(0, 2, 5)
G.Edge(1, 1, 4)
G.Edge(2, 1, 5)
G.Edge(3, 1, 4)

G.Bellman(0)

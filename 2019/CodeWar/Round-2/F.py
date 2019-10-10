class Rec:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.data = [0 for x in range(m*(n+2))]

    def transform(self, x, y)-> int:
        return x*self.n + y

    def q1(self, r1, c1, r2, c2):
        self.data[self.transform(r1, c1)] += 1
        self.data[self.transform(r2, c2) + 1] -= 1        

    def gsum(self, x, y):
        if x < 0 or y < 0:
            return 0
        return self.sum[x][y]

    def q2(self, r1, c1, r2, c2):
        return self.gsum(r2, c2) - self.gsum(r1-1, c2) - self.gsum(r2, c1-1) + self.gsum(r1-1, c1-1)

    def calc_sum(self):
        N = len(self.data)
        for i in range(1, N):
            self.data[i] = self.data[i-1]+self.data[i]
        self.sum = [[0 for x in range(self.m)] for y in range(self.n)] 
        for i in range(self.n):
            for j in range(self.m):
                self.sum[i][j] = self.gsum(i-1, j) + self.gsum(i, j-1) - self.gsum(i-1, j-1) + self.data[self.transform(i, j)]
                # print(i,j, self.data[self.transform(i, j)], self.sum)


def queriesOnRectange(n, m, queries1, queries2):
    rec = Rec(n, m)
    for x in queries1:
        rec.q1(x[0], x[1], x[2], x[3])
    rec.calc_sum()
    # print(rec.data)
    # print(rec.sum)
    res = []
    for x in queries2:
        res.append(rec.q2(x[0], x[1], x[2], x[3]))
    return res


print(queriesOnRectange(4, 4, [[0, 1, 1, 2], [1, 1, 2, 2]], [[0, 0, 1, 1], [1, 1, 2, 3]]))
print(queriesOnRectange(5, 4, [[1, 2, 4, 3],[0, 0, 2, 1], [1, 1, 1, 2], [0, 0, 4, 3], [3, 2, 4, 1]], [[1, 2, 3, 3],[2, 0, 4, 2], [2, 0, 4, 3], [0, 0, 1, 0], [2, 0, 3, 2], [3, 2, 4, 3]]))

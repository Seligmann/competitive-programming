#almostunionfind.py

import io, os, sys
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

class Node:

    def __init__(self, value):
        self.value = value
        self.summ = value
        self.parent = self
        self.size = 1

    def get_root(self):
        curr = self
        while curr.parent is not curr:
            curr.parent = curr.parent.parent
            curr = curr.parent
        return curr

    def vacate(self):
        root = self.get_root()
        root.size -= 1
        root.summ -= self.value
    
    def insert(self, other):
        other.parent = self
        self.summ += other.summ
        self.size += other.size

    def __str__(self):
        return str(self.size) + ' ' + str(self.summ) + '\n'

while True:
    try:
        n, m = (int(i) for i in input().decode().split())
    except EOFError:
        break
    except ValueError:
        break
    nodes = [Node(i + 1) for i in range(n)]
    for _ in range(m):
        line = input().decode().split()
        p = nodes[int(line[1]) - 1]
        rp = p.get_root()
        if line[0] == '1':
            #union p and q
            q = nodes[int(line[2]) - 1]
            rq = q.get_root()
            if rp is not rq:
                rp.insert(rq)
        elif line[0] == '2':
            #remove p, add to q
            q = nodes[int(line[2]) - 1]
            rq = q.get_root()
            if rp is not rq:
                p.vacate()
                i = int(line[1]) - 1
                nodes[i] = Node(i + 1)
                rq.insert(nodes[i])
        else:
            sys.stdout.write(str(rp))
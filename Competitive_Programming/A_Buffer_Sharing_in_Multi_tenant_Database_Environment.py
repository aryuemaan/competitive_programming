from collections import defaultdict, deque

# read input
n, q, m = map(int, input().split())
L = list(map(int, input().split()))
D = list(map(int, input().split()))
Q = [tuple(map(int, input().split())) for _ in range(n)]

# initialize buffer
buffer = defaultdict(deque)

# initialize memory usage counters for each tenant
mem_cnt = [0] * n

# initialize LRU queue
lru_queue = deque()

# function to evict a page from buffer
def evict_page():
    # pop the least recently used page from the LRU queue
    c = lru_queue.popleft()
    # remove the page from buffer
    p = buffer[c[0]].popleft()
    # decrement memory usage counter of the corresponding tenant
    mem_cnt[p[0]-1] -= 1
    return c, p

# iterate over the operations
for i in range(m):
    # read the operation
    u, p = map(int, input().split())
    # check if the requested page is in the buffer
    if p in [x[1] for x in buffer[u]]:
        # if yes, update the LRU queue
        lru_queue.remove((u, p))
        lru_queue.append((u, p))
        # return the buffer location
        print(buffer[u].index((u, p)) + 1)
    else:
        # if no, evict a page from buffer
        while True:
            # find the tenant with the lowest memory usage counter
            min_mem_cnt = min(mem_cnt)
            min_mem_tenant = mem_cnt.index(min_mem_cnt)
            # check if the eviction satisfies the memory usage constraints
            if Q[min_mem_tenant][0] <= mem_cnt[min_mem_tenant] <= Q[min_mem_tenant][2] or buffer[u]:
                break
            # if not, evict a page from the buffer
            c, p = evict_page()
            # add the evicted page to the LRU queue
            if buffer[c[0]]:
                lru_queue.append((c[0], buffer[c[0]][0][1]))
            # print the eviction
            print(c[0], c[1])
        # if the eviction is not from the same tenant, swap out the page
        if buffer[c[0]]:
            swapped_out = buffer[c[0]].popleft()
            mem_cnt[swapped_out[0]-1]


#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 将 sourceX, sourceY 转换成 targetX, targetY 最少需要多少次计算
# @param sourceX long长整型  x初始值
# @param sourceY long长整型  y初始值
# @param targetX long长整型  x目标值
# @param targetY long长整型  y目标值
# @return long长整型
#
class Solution:
    def GetMinCalculateCount(self, sourceX, sourceY, targetX, targetY):
        d = {
            (sourceX, sourceY): 0
        }
        list = [(sourceX, sourceY)]
        while len(list) > 0:
            now = list.pop(0)
            if (d[now] > 15):
                return -1

            node = (now[0]+1, now[1]+1)
            if d.get(node,None) is None:
                d[node] = d[now]+1
                list.append(node)
                if node==(targetX, targetY):
                    return d[node]

            node = (now[0]*2, now[1]*2)
            if d.get(node,None) is None:
                d[node] = d[now]+1
                list.append(node)
                if node==(targetX, targetY):
                    return d[node]
            # print(now)
        return -1
        # write code here


print(Solution().GetMinCalculateCount(1, 2, 4, 6))
print(Solution().GetMinCalculateCount(10, 100, 22, 202))
print(Solution().GetMinCalculateCount(11, 100, 22, 202))
print(Solution().GetMinCalculateCount(1, 1, 1024, 1024))
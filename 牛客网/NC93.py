#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# lru design
# @param operators int整型二维数组 the ops
# @param k int整型 the k
# @return int整型一维数组
#


class Solution:
    def LRU(self, operators: list[list[int]], k: int) -> list[int]:
        # write code here
        d = {}
        ans = []
        i = 0
        for operator in operators:
            if operator[0] == 1:
                d[operator[1]] = {}
                d[operator[1]]['val'] = operator[2]
                d[operator[1]]['stamp'] = i
                i += 1
            else:
                if d.get(operator[1]) and i-d.get(operator[1]).get('stamp') <= k:
                    ans.append(d.get(operator[1]).get('val'))
                    d[operator[1]]['stamp'] = i
                    i += 1
                else:
                    ans.append(-1)

        return ans


S = Solution()
l = S.LRU([[1, 1, 1], [1, 2, 2], [1, 3, 2], [2, 1], [1, 4, 4], [2, 2]], 3)
print(l)
l = S.LRU([[1, 1, 1], [1, 2, 2], [2, 1], [1, 3, 3], [
          2, 2], [1, 4, 4], [2, 1], [2, 3], [2, 4]], 2)
print(l)
"""
Given a list of integers, find the length of the longest strictly increasing subsequence in the list
"""
def longestIncreasing(arr):
    from bisect import bisect_left
    tmp = []

    for v in arr:
        if len(tmp) == 0:
            tmp.append(v)
        
        elif v < tmp[-1]:
            element_replace = bisect_left(tmp, v)
            tmp[element_replace] = v

        else:
            tmp.append(v)

    return len(tmp)

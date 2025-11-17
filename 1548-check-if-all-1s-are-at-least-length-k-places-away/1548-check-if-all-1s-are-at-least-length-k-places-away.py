class Solution(object):
    def kLengthApart(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if k == 0:
            return True

        n = len(nums)
        curr = None  # store last seen index of 1

        for i in range(n):
            if nums[i] == 1:
                if curr is not None and (i - curr - 1) < k:
                    return False
                curr = i

        return True

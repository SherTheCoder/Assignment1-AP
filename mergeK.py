class ListNode:
    def __init__(self, x=0, next=None):
        self.val = x
        self.next = next

class Solution:
    def mergeKLists(self, lists):
        if not lists:
            return None
        for i in range(1, len(lists)):
            lists[0] = self.merge(lists[0], lists[i])
        return lists[0]

    def merge(self, left, right):
        dummy = ListNode(0)
        ptr = dummy
        while left and right:
            if left.val < right.val:
                ptr.next = left
                left = left.next
            else:
                ptr.next = right
                right = right.next
            ptr = ptr.next
        if left:
            ptr.next = left
        if right:
            ptr.next = right
        return dummy.next


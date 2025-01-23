# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        initial_sum = l1.val + l2.val
        carry_over = initial_sum // 10
        head = ListNode(initial_sum % 10)
        current = head
        l1, l2 = l1.next, l2.next

        while l1 or l2:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            total = val1 + val2 + carry_over
            carry_over = total // 10
            current.next = ListNode(total % 10)
            current = current.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next

        if carry_over:
            current.next = ListNode(carry_over)

        return head
            
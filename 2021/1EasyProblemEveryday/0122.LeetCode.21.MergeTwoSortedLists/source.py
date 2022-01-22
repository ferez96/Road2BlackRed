from typing import *

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        if list2 is None:
            return list1
            
        head, tail = None, None        

        while list1 is not None and list2 is not None:
            if list1.val <= list2.val:
                if head is None:
                    head = list1                
                else:
                    tail.next = list1
                tail = list1    
                list1 = list1.next
            else:
                if head is None:
                    head = list2                    
                else:
                    tail.next = list2
                tail = list2
                list2 = list2.next

        if list1 is not None:            
            tail.next = list1
        if tail is not None and list2 is not None:
            tail.next = list2
        
        return head
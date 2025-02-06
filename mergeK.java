import java.util.List;

class ListNode {
    int val;
    ListNode next;
    ListNode() { val = 0; next = null; }
    ListNode(int x) { val = x; next = null; }
    ListNode(int x, ListNode next) { val = x; this.next = next; }
}

class Solution {
    public ListNode mergeKLists(List<ListNode> lists) {
        if (lists.isEmpty()) return null;
        for (int i = 1; i < lists.size(); i++) {
            lists.set(0, merge(lists.get(0), lists.get(i)));
        }
        return lists.get(0);
    }

    public ListNode merge(ListNode left, ListNode right) {
        ListNode dummy = new ListNode(0);
        ListNode ptr = dummy;
        while (left != null && right != null) {
            if (left.val < right.val) {
                ptr.next = left;
                left = left.next;
            } else {
                ptr.next = right;
                right = right.next;
            }
            ptr = ptr.next;
        }
        if (left != null) ptr.next = left;
        if (right != null) ptr.next = right;
        return dummy.next;
    }
}


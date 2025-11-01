// Definition for singly-linked list.
use std::collections::HashSet;

impl Solution {
    pub fn modified_list(nums: Vec<i32>, head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let s: HashSet<i32> = nums.into_iter().collect();
        let mut dummy = Box::new(ListNode { val: 0, next: head });
        let mut curr = &mut dummy;

        while let Some(ref mut node) = curr.next {
            if s.contains(&node.val) {
                curr.next = node.next.take();
            } else {
                curr = curr.next.as_mut().unwrap();
            }
        }
        dummy.next
    }
}
var mergeTwoLists = function(list1, list2) {
    const result = new ListNode(0);
    let temp = result;

    while(list1 && list2) {
        if (list1.val <= list2.val) {
            temp.next = list1;
            list1 = list1.next;
        } else {
            temp.next = list2;
            list2 = list2.next;
        }
        temp = temp.next;
    }

    temp.next = list1 || list2;
    return result.next;
};
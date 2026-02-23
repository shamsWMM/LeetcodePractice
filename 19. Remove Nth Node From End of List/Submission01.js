var removeNthFromEnd = function(head, n) {
    const dummy = new ListNode(0, head);
    let rightNode = dummy;
    let leftNode = dummy;

    for (let i = 0; i <= n; i++)
    {
        rightNode = rightNode.next;
    }

    while ( rightNode !== null)
    {
        rightNode = rightNode.next;
        leftNode = leftNode.next;
    }

    leftNode.next = leftNode.next.next;

    return dummy.next;
};
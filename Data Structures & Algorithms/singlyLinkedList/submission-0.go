type LinkedList struct {
    Root *Node
}

type Node struct {
    Value int 
    Next *Node
}

func NewLinkedList() *LinkedList {
    return &LinkedList{
        Root: nil,
    }
}

func (ll *LinkedList) Get(index int) int {
    if ll.Root == nil || index < 0 {
        return -1 
    }

    idx := 0
    for curr := ll.Root; curr != nil; curr = curr.Next {
        if idx == index {
            return curr.Value
        }
        idx++
    }

    return -1 
}

func (ll *LinkedList) InsertHead(val int) {
    ll.Root = &Node{
        Value: val,
        Next: ll.Root,
    }
}

func (ll *LinkedList) InsertTail(val int) {
    node := &Node{
        Value: val,
        Next: nil,
    }

    if ll.Root == nil {
        ll.Root = node 
        return 
    }

    curr := ll.Root 
    for curr.Next != nil {
        curr = curr.Next
    }

    curr.Next = node 
}

func (ll *LinkedList) Remove(index int) bool {
    if ll.Root == nil || index < 0 {
        return false 
    }

    if index == 0 {
        ll.Root = ll.Root.Next
        return true 
    }

    prev := ll.Root
    curr := ll.Root.Next

    for idx := 1; curr != nil; idx++ {
        if idx == index {
            prev.Next = curr.Next 
            return true 
        }

        prev = curr 
        curr = curr.Next
    }
    return false
}

func (ll *LinkedList) GetValues() []int {

    ret := make([]int, 0, 64)

    for curr := ll.Root; curr != nil; curr = curr.Next {
        ret = append(ret, curr.Value)
    }

    return ret
}

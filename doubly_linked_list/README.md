# Doubly Linked List


## Insertion

### Insertion at the head
```cpp
Algorithm insert_at_head(data, HEAD)
// data is the data to be stored in the new node
// HEAD is the head of the doubly linked list
{
    // create a new node new_node
    new_node.data = data;
    new_node.prev = NULL;
    new_node.next = HEAD;
    
    if (HEAD != NULL) {
        HEAD.prev = new_node;
    }

    HEAD = new_node;
}
```

### Insertion after a node
```cpp
Algorithm insert_after(data, predecessor)
// data is the data to be stored in the new node
// predecessor is the node after which new node is to be inserted
{
    // create a new node new_node
    new_node.data = data;
    new_node.prev = predecessor;
    new_node.next = predecessor.next;
    predecessor.next = new_node;
    new_node.next.prev = new_node; 
}
```

### Insertion before a node
```cpp
Algorithm insert_before(data, successor)
// data is the data to be stored in the new node
// successor is the node before which new node is to be inserted
{
    // create a new node new_node
    new_node.data = data;
    new_node.prev = successor.prev;
    new_node.next = successor;
    successor.prev = new_node;
    new_node.prev.next = new_node;
}
```


## Deletion

### Remove from head
```cpp
Algorithm remove_from_head(HEAD, return_data)
// HEAD is the head of the doubly linked list
// return_data is the reference storing the data to be returned
// returns true if data was removed successfully false otherwise
{
    if (HEAD == NULL) {
        return false;
    }

    new_head = HEAD.next;
    new_head.prev = NULL;
    return_data = HEAD.data;

    HEAD = new_head;

    return true;
}
```

### Remove an arbitrary node
```cpp
Algorithm remove(node)
// node is the pointer to the doubly linked list node to be removed
{
    // if not head
    if(node.prev != NULL) {
        node.prev.next = node.next;
    }
    // if not tail
    if(node.next != NULL) {
        node.next.previous = node.prev;
    }
}
```



## Search

### Search and Retrive data
```cpp
Algorithm retrieve(HEAD, data, return_node)
// HEAD is the head of the doubly linked list
// data is the data to be searched
// return_node is reference in which returned node is stored if data is found
{
    if (HEAD == NULL) // the whole list is empty
        return false;

    return_node = NULL;
    for (start = HEAD; start != NULL; start = start.next)
    {
        if (start.data == data)
        {
            return_node = start;
            return true; // indicating the data was found
        }
    }
    return false; // indicating the data wasn't found
}
```
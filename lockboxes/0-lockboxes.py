#!/usr/bin/python3

# method that determines if all the boxes can be opened
def canUnlockAll(boxes):
    # store the boxes that are open
    openBoxes = {0}
    # have the keys
    keys = set(boxes[0])
    
    # loop in the keys
    while keys:
        # take a key
        key = keys.pop()
        # check if the box of that key exist and is close
        if key not in openBoxes and key < len(boxes):
            # open the box
            openBoxes.add(key)
            # store the keys of that box
            keys.update(boxes[key])
    # check if all boxes are open
    return len(boxes) == len(openBoxes)
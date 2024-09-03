#!/usr/bin/python3

"""
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes.
"""
def canUnlockAll(boxes):
    """
        solve the problem of
        loockboxes
    """
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
#!/usr/bin/python3

def canUnlockAll(boxes):
    openBoxes = {0}
    keys = set(boxes[0])
    
    while keys:
        key = keys.pop()
        if key not in openBoxes and key < len(boxes):
            openBoxes.add(key)
            keys.update(boxes[key])
    return len(boxes) == len(openBoxes)
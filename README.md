This is engine

It is based on SDL2. To use it you need rewrite CMakeLists.txt and connect to it SDL2.


Also I created script language to create objects from file (for example, Object.objecy)
Syntax:
    1. Firstly, you need to indicate type of object.
    2.
        1) If type of object equals point, you need to indicate position in format "position=0,0"
        2) If type of object equals line, you need to indicate start of line "position=0,0" and end of line "position=0,0"
        3) If type of object equals rect, you need to indicate left corner of rect and its size
        4) If type of object equals circle, you need to indicate center of circle and its size
        5) If type of object equals circumference, you need to indicate center of circle and its size
        6) If type of object equals trinagle, you need to indicate three vertexs position
        7) If type of object equals polygon, you need to indicate all its vertexs

In the future, I want add script language to write logic for game
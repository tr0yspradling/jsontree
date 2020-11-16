# jsontree
A fast, lightweight, cross-platform utility for viewing & navigating large JSON documents.

Generated using [gtkmm-project](https://github.com/tr0yspradling/gtkmm-project.git).

# Dependencies
- [RapidJSON](https://rapidjson.org/)  
- [gtkmm](https://www.gtkmm.org/)  

# Build
```
$ mkdir build && cd build
$ cmake .. && make
```

# License
......free?

# Notes
- Capture root object & iterate over it's children
    - if child is array or object, recursively iterate again
    - otherwise, add child to node's data 
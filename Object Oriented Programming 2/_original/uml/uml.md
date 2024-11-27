# Sneaky Snuke - Snake Game in C++

## UML Diagrams

```
#################################
# Color
#################################
# - red: unsigned char
# - green: unsigned char
# - blue: unsigned char
#################################
# + Color()
# + Color(red: unsigned char, green: unsigned char, blue: unsigned char)
# + red(): unsigned char
# + green(): unsigned char
# + blue(): unsigned char
# + red(red: unsigned char)
# + green(green: unsigned char)
# + blue(blue: unsigned char)
#################################
```

```
#################################
# Point <<struct>>
#################################
# + x: unsigned int
# + y: unsigned int
#################################
```

```
#################################
# Direction <<enum>>
#################################
# + UP
# + DOWN
# + LEFT
# + RIGHT
#################################
```

```
#################################
# Canvas
#################################
# - _buffer: std::array<std::array<Color>>
# - penColor: Color
#################################
# + Canvas()
# + clear()
# + pen_color(color: Color)       set the active drawing color
# + pixel(point: Point)
# + horizontal_line(origin: Point, length: unsigned int)
# + vertical_line(origin: Point, length: unsigned int)
# + rectangle(origin: Point, second: Point)
# + buffer(): std::array<std::array<Color>>
#################################
```

```
#################################
# Snake
#################################
# - snake: std::vector<Point>
# - direction: Direction
# - isMoving: bool
# - START_LENGTH: unsigned int = 3
#################################
# + Snake()       create snake of START_LENGTH
# + up()
# + down()
# + left()
# + right()
# + stop()
# + grow(delta: unsigned int)
# + body(): std::vector<Point>
# + head(): Point
# + update()
#################################
```

```
#################################
# Game
#################################
# - snake: Snake
# - canvas: Canvas
# - isPlaying: bool
#################################
# + Game()
# - update()      update entities
# - draw()        draw entities on canvas
# - render()      output canvas to renderer (terminal)
#################################
```

Layout represents static indestructible walls

```
#################################
# Layout (may need a better name)
#################################
# - width: unsigned int
# - height: unsigned int
# - walls: std::vector<Point>
#################################
# + Layout(width: unsigned int, height: unsigned int)       setup perimeter
# + update()                                                probable does nothing
# + blocks(): std::vector<Point>
#################################
```

Later on we will need to add the following classes:

* Apple (editable)
* Renderer interface + 2 implementations
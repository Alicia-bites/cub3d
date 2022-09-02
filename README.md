# cub3d
You must create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. You have to create this representation using the Ray-Casting principles mentioned earlier.

## Team name  
**SMBASH**  


## Contributors
- amarchan
- abarrier


## Content
- [Historic :clock7:](#historic-clock7)
- [ToDo :dart:](#todo-dart)
- [Externals Functions](#externals-functions)
- [Sources :link:](#sources-link)


## Historic :clock7:
[Go to content](#content)
|Date _YYYY-MM-DD_|Description|
|:-|:-|
|2022-09-01|Init|


## ToDo :dart:
[Go to content](#content)
- [ ] Program name **cub3D**
- [ ] Map in format **.cub**

## Externals functions
[Go to content](#content)
- open, close, read, write, printf, malloc, free, perror, strerror, exit
- All functions of the math library (-lm man man 3 math)
- All functions of the MinilibX

## Parsing
[Go to content](#content)

### Rules
- [ ] Scene description file with the **.cub** extension

:heavy\_check\_mark: __Valid case:__
```
./cub3D sample.cub
./cub3D sample.cub.cub
./cub3D cub.cub
```
:x: __Invalid case:__
```
./cub3D
./cub3D sample.cube
./cub3D sample.cub.cube
```

- [ ] Only 6 possible characters
	- [ ] 0 for an empty space
	- [ ] 1 for a wall
	- [ ] N,S,E or W for the player’s start position and spawning orientation.

:heavy\_check\_mark: __Valid case:__
```
111111
1100N1
111111
```
```
111111
1E0001
111111
```
:x: __Invalid case:__
```
111111
110001
111111
```
```
111111
1Z0001
111111
```

- [ ] The map must be closed/surrounded by walls, if not the program must return an error

:heavy\_check\_mark: __Valid case:__
```
111111
1100N1
111111
```
```
111111
1E0001
111111
```
:x: __Invalid case:__
space 0 as closed/surrounded walls
```
111110
1100N1
111111
```
empty space as closed/surrounded walls
```
111111
1E000
111111
```
player spawn as closed/surrounded walls
```
11111E
110001
111111
```

- [ ] Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order

|Type identifier|Description|Value|Example|
|:-|:-|:-|:-|
|NO|North texture|path|NO ./path\_to\_the\_north\_texture|
|SO|South texture|path|SO ./path\_to\_the\_south\_texture|
|WE|West texture|path|WE ./path\_to\_the\_west\_texture|
|EA|East texture|path|EA ./path\_to\_the\_east\_texture|
|F|Floor color|R,G,B colors in range \[0,255\]: 0, 255, 255|F 220,100,0|
|C|Ceilling color|R,G,B colors in range \[0,255\]: 0, 255, 255|C 225,30,0|

- [ ] Except for the map content, each type of element can be separated by one or more empty line(s)

:heavy\_check\_mark: __Valid case:__
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
```
```
NO 		./path_to_the_north_texture
SO    ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,			100, 0
C 225 , 30 , 0
```
> :interrobang: Case without space between the type identifier and the value to be validated  :interrobang:
```
NO./path_to_the_north_texture
SO./path_to_the_south_texture
WE./path_to_the_west_texture
EA./path_to_the_east_texture
F220,100,0
C225,30,0
```
:x: __Invalid case:__
```
no ./path_to_the_north_texture
So ./path_to_the_south_texture
wE ./path_to_the_west_texture
E A ./path_to_the_east_texture
Z 220,100,0
C 225,30,0
```

- [ ] Except for the map content which always has to be the last, each type of element can be set in any order in the file

:heavy\_check\_mark: __Valid case:__
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0

111111
1100N1
111111
```
:x: __Invalid case:__
```
111111
1100N1
111111

NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
```
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
111111
1100N1
111111

F 220,100,0
C 225,30,0
```


## Sources :link:
[Go to content](#content)

### Raycasting
- https://lodev.org/cgtutor/raycasting.html

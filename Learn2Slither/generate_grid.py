import random

def snake_view(grid):
    snake_x, snake_y = None, None
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if grid[y][x] == 'H':
                snake_x, snake_y = x, y
                break
        if snake_x is not None:
            break
    
    view_grid = []
    for y in range(len(grid)):
        row = []
        for x in range(len(grid[0])):
            row.append(' ')
        view_grid.append(row)
    
    view_grid[snake_y][snake_x] = 'H'
    
    directions = [
        (0, -1),
        (0, 1),
        (-1, 0),
        (1, 0)
    ]
    
    for dx, dy in directions:
        current_x = snake_x + dx
        current_y = snake_y + dy
        
        while (0 <= current_x < len(grid[0]) and 
               0 <= current_y < len(grid)):
            
            view_grid[current_y][current_x] = grid[current_y][current_x]
            
            if grid[current_y][current_x] == 'W':
                break
                
            current_x += dx
            current_y += dy
    
    return view_grid


def place_apples(grid, width, height):
    green_apple1 = None
    green_apple2 = None
    red_apple = None
    green_apple1 = random.randint(1, width - 2), random.randint(1, height - 2)
    while green_apple2 is None or green_apple2 == green_apple1:
        green_apple2 = random.randint(1, width - 2), random.randint(1, height - 2)
    while red_apple is None or red_apple == green_apple1 or red_apple == green_apple2:
        red_apple = random.randint(1, width - 2), random.randint(1, height - 2)
    grid[green_apple1[1]][green_apple1[0]] = 'G'
    grid[green_apple2[1]][green_apple2[0]] = 'G'
    grid[red_apple[1]][red_apple[0]] = 'R'
    return grid


def place_snake(grid, width, height):
    """
    Places a snake of length 3 on the grid.
    """
    directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]  # right, down, left, up
    while True:
        head_x = random.randint(1, width - 2)
        head_y = random.randint(1, height - 2)
        direction = random.choice(directions)
        body1_x = head_x + direction[0]
        body1_y = head_y + direction[1]
        body2_x = body1_x + direction[0]
        body2_y = body1_y + direction[1]
        if (1 <= body1_x < width - 1 and 1 <= body1_y < height - 1 and
            1 <= body2_x < width - 1 and 1 <= body2_y < height - 1 and
            grid[head_y][head_x] == '0' and
            grid[body1_y][body1_x] == '0' and
            grid[body2_y][body2_x] == '0'):
            grid[head_y][head_x] = 'H'
            grid[body1_y][body1_x] = 'S'
            grid[body2_y][body2_x] = 'S'
            break
    return grid

 
def generate_grid(width, height):
    grid = []
    for y in range(height):
        row = []
        for x in range(width):
            if x == 0 or x == width - 1 or y == 0 or y == height - 1:
                row.append('W')
            else:
                row.append('0')
        grid.append(row)

    
    grid = place_apples(grid, width, height)

    grid = place_snake(grid, width, height)
    
    return grid

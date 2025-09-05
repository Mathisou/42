import numpy as np
from generate_grid import generate_grid
from generate_grid import snake_view

class SnakeEnvironment:
    """Environment for Snake game using reinforcement learning."""
    
    def __init__(self, width=12, height=12):
        self.width = width
        self.height = height
        self.grid = None
        self.snake_pos = None
        self.snake_body = []  # Add snake body tracking
        self.last_positions = []  # Track recent positions to avoid loops
        self.direction = None
        self.score = 0
        self.done = False
        
        # Actions: 0=up, 1=down, 2=left, 3=right
        self.action_space = 4
        
    def reset(self):
        """Reset the environment to initial state."""
        self.grid = generate_grid(self.width, self.height)
        self.score = 0
        self.done = False
        self.snake_body = []
        self.last_positions = []
        
        # Find snake head position
        for y in range(len(self.grid)):
            for x in range(len(self.grid[0])):
                if self.grid[y][x] == 'H':
                    self.snake_pos = (x, y)
                    break
        
        # If no snake head found, place one randomly
        if self.snake_pos is None:
            x = np.random.randint(2, self.width - 2)
            y = np.random.randint(2, self.height - 2)
            self.grid[y][x] = 'H'
            self.snake_pos = (x, y)
            # Add initial body segment
            self.grid[y+1][x] = 'S'
            self.snake_body = [(x, y+1)]
        
        return self.get_state()
    
    def get_state(self):
        """Get current state representation for the neural network."""
        # Use snake_view to get what the snake can see
        view = snake_view(self.grid)
        
        # Convert grid to numerical representation
        state = []
        for row in view:
            for cell in row:
                if cell == ' ':      # Empty/unseen
                    state.append(0)
                elif cell == '0':    # Empty space
                    state.append(1)
                elif cell == 'W':    # Wall
                    state.append(2)
                elif cell == 'G':    # Green apple
                    state.append(3)
                elif cell == 'R':    # Red apple
                    state.append(4)
                elif cell == 'H':    # Snake head
                    state.append(5)
                elif cell == 'S':    # Snake body
                    state.append(6)
                else:
                    state.append(0)
        
        return np.array(state, dtype=np.float32)
    
    def step(self, action):
        """Execute action and return new state, reward, done."""
        if self.done:
            return self.get_state(), 0, True
        
        # Convert action to direction
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]  # up, down, left, right
        dx, dy = directions[action]
        
        # Calculate new position
        new_x = self.snake_pos[0] + dx
        new_y = self.snake_pos[1] + dy
        
        # Check boundaries
        if (new_x < 0 or new_x >= self.width or 
            new_y < 0 or new_y >= self.height or 
            self.grid[new_y][new_x] == 'W'):
            # Hit wall - game over
            self.done = True
            return self.get_state(), -10, True  # Negative reward for dying
        
        # Check what's at new position
        target_cell = self.grid[new_y][new_x]
        reward = 0
        
        if target_cell == 'G':  # Green apple
            reward = 50  # Higher reward for eating good apples
            self.score += 1  # Count apples eaten (human score)
        elif target_cell == 'R':  # Red apple
            reward = -25  # negative reward for red apple
            self.score -= 1  # Penalty in human score
        elif target_cell == 'S' or target_cell == 'W':  # Game over conditions
            self.done = True
            return self.get_state(), -100, True  # Negative reward for self-collision
        else:  # Empty space
            reward = -1.0  # Smaller penalty to encourage exploration
            # self.score unchanged for empty moves
        
        # Move snake
        # self.grid[self.snake_pos[1]][self.snake_pos[0]] = '0'  # Clear old position
        self.grid[new_y][new_x] = 'H'  # Place head at new position
        self.snake_pos = (new_x, new_y)
        
        # If apple was eaten, place a new one
        if target_cell in ['G', 'R']:
            self._place_new_apple()
        
        return self.get_state(), reward, self.done
    
    def _place_new_apple(self):
        """Place a new apple randomly on empty space."""
        empty_positions = []
        for y in range(1, self.height - 1):
            for x in range(1, self.width - 1):
                if self.grid[y][x] == '0':
                    empty_positions.append((x, y))
        
        if empty_positions:
            x, y = empty_positions[np.random.randint(len(empty_positions))]
            apple_type = 'G' if np.random.random() < 0.8 else 'R'  # 80% green, 20% red
            self.grid[y][x] = apple_type

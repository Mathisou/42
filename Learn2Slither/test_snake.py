from q_learning import Agent
from snake_env import SnakeEnvironment
import torch
import pygame
import time

def test_trained_snake():
    """Test the trained Snake AI with visual display."""
    
    # Setup environment and agent
    env = SnakeEnvironment(width=12, height=12)
    state = env.reset()
    input_dims = [len(state)]
    
    agent = Agent(
        gamma=0.99,
        epsilon=0.0,  # No exploration for testing
        lr=0.003,
        input_dims=input_dims,
        batch_size=64,
        n_actions=4
    )
    
    # Load trained model
    try:
        agent.Q_eval.load_state_dict(torch.load('snake_model.pth'))
        print("Loaded trained model successfully!")
    except FileNotFoundError:
        print("No trained model found. Please train first using train_snake.py")
        return
    
    # Pygame setup for visualization
    pygame.init()
    screen = pygame.display.set_mode((500, 500))
    pygame.display.set_caption("Trained Snake AI")
    clock = pygame.time.Clock()
    
    running = True
    episodes = 0
    
    while running and episodes < 5:  # Show 5 games
        state = env.reset()
        done = False
        steps = 0
        max_steps = 200
        
        print(f"\n--- Game {episodes + 1} ---")
        
        while not done and steps < max_steps and running:
            # Handle pygame events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
            
            # AI chooses action
            action = agent.choose_action(state)
            action_names = ["UP", "DOWN", "LEFT", "RIGHT"]
            print(f"Step {steps}: Action = {action_names[action]}")
            
            # Execute action
            state, reward, done = env.step(action)
            
            # Visualize
            screen.fill("purple")
            grid = env.grid
            
            for y in range(1, len(grid) - 1):
                for x in range(1, len(grid[0]) - 1):
                    cell = grid[y][x]
                    color = "white"
                    if cell == 'G':
                        color = "green"
                    elif cell == 'R':
                        color = "red"
                    elif cell == 'H':
                        color = "blue"
                    elif cell == 'S':
                        color = "cyan"
                    
                    pygame.draw.rect(screen, color, ((x-1) * 50, (y-1) * 50, 50, 50))
                    pygame.draw.rect(screen, "black", ((x-1) * 50, (y-1) * 50, 50, 50), 1)
            
            pygame.display.flip()
            time.sleep(0.3)  # Slow down for visibility
            steps += 1
        
        print(f"Game {episodes + 1} finished! Score: {env.score}, Steps: {steps}")
        episodes += 1
        time.sleep(1)  # Pause between games
    
    pygame.quit()

if __name__ == "__main__":
    test_trained_snake()
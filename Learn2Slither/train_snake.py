from q_learning import Agent
from snake_env import SnakeEnvironment
import numpy as np
import matplotlib.pyplot as plt
import torch as T

def train_snake():
    """Train the Snake AI using Deep Q-Learning."""
    
    # Environment setup
    env = SnakeEnvironment(width=12, height=12)
    
    # Get state dimensions
    state = env.reset()
    input_dims = [len(state)]  # Flattened grid size
    
    # Agent setup
    agent = Agent(
        gamma=0.95,          # Slightly lower discount for immediate rewards
        epsilon=1.0,         # Start with full exploration
        lr=0.003,           # Lower learning rate for stability
        input_dims=input_dims,
        batch_size=64,       # Larger batch for better learning
        n_actions=4,         # 4 directions
        max_mem_size=50000,  # More memory
        eps_end=0.05,        # Higher minimum exploration
        eps_dec=8e-4         # Slower decay to explore longer
    )
    
    # Training parameters
    n_episodes = 1000  # More episodes for better learning
    scores = []
    
    print("Starting training...")
    
    for episode in range(n_episodes):
        state = env.reset()
        score = 0
        done = False
        steps = 0
        max_steps = 200  # Prevent infinite loops
        
        while not done and steps < max_steps:
            # Choose action
            action = agent.choose_action(state)
            
            # Take action
            new_state, reward, done = env.step(action)
            
            # # Additional reward shaping
            # if steps > 150:  # If taking too long
            #     reward -= 2  # Penalty for inefficiency
            
            # Store experience
            agent.store_transition(state, action, reward, new_state, done)
            
            # Learn from experience
            agent.learn()
            
            # Update state and score
            state = new_state
            score += reward
            steps += 1
        
        scores.append(score)
        
        # Print progress
        if episode % 100 == 0:
            avg_score = np.mean(scores[-100:])
            print(f"Episode {episode}, Average Score: {avg_score:.2f}, Epsilon: {agent.epsilon:.3f}")
    
    # Save the trained model

    T.save(agent.Q_eval.state_dict(), 'snake_model.pth')
    print("Model saved as 'snake_model.pth'")
    
    # Plot training progress
    plt.figure(figsize=(12, 4))
    
    plt.subplot(1, 2, 1)
    plt.plot(scores)
    plt.title('Scores over Episodes')
    plt.xlabel('Episode')
    plt.ylabel('Score')
    
    plt.subplot(1, 2, 2)
    # Moving average
    window = 50
    moving_avg = [np.mean(scores[max(0, i-window):i+1]) for i in range(len(scores))]
    plt.plot(moving_avg)
    plt.title(f'Moving Average (window={window})')
    plt.xlabel('Episode')
    plt.ylabel('Average Score')
    
    plt.tight_layout()
    plt.savefig('training_progress.png')
    plt.show()

if __name__ == "__main__":
    train_snake()
